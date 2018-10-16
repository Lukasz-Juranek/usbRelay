#include <ctype.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "usb_relay_app.h"

/* private functions */
uint8_t RelayApp_ParseRelayData(char* i_data, t_relay* realy_data);
uint8_t RelayApp_ParseStep(char* i_data, t_step_conf *realy_data);
void RelayApp_ProcessStep(t_relay* relay);
uint8_t RelayApp_ParseRelayNumber(char* i_data);

/* commands in format: RrDdddCccc,SsPppp,SsPppp...
 where:
 r - relay number max 8
 ddd[optional] - delay in ms max 4294967295U if non then instant action
 ccc[optional] - cycles count max 4294967295U if non then infinty
 after coma is step definition that are cycled in one cycle where:
 s - relay state during cycle
 pppp[optional] - cycle lenght/period in ms, how long relay state will last 4294967295U, if none then instant switch
 */

uint8_t RelayApp_ParseWhole(char* i_data, t_relay* relay_array) {
	uint8_t relay_no;
	uint8_t i;
	t_relay* relay_data;
	const char relay_params[] = ",";
	char* param_pointer = strpbrk(i_data, relay_params);
	/* check for , */
	if (param_pointer == NULL) {
		return USB_RELAY_ERR;
	}

	/* 1. to upper */
	for (i = 0; i < (strlen(i_data) - 1); ++i) {
		i_data[i] = toupper(i_data[i]);
	}

	/* extract relay number */
	relay_no = RelayApp_ParseRelayNumber(i_data);
	if (relay_no >= USB_RELAY_MAX_RELAY_NO)
		return USB_RELAY_ERR;
	relay_data =  &(relay_array[relay_no]);

	/* parse paramteres and save to array */
	if (RelayApp_ParseRelayData(i_data, relay_data) == 0) {
		return USB_RELAY_ERR;
	}
	relay_data->all_steps_count = 0;
//	param_pointer = strpbrk(param_pointer + 1, relay_params);
	while (param_pointer != NULL) {
		/* check for avaliable slots */
		if (relay_data->all_steps_count >= USB_RELAY_MAX_STEPS_COUNT)
			return USB_RELAY_MAX_STEPS_ERR;
		RelayApp_ParseStep(param_pointer + 1,
				&(relay_data->steps_array[relay_data->all_steps_count]));
		relay_data->all_steps_count++;

		param_pointer = strpbrk(param_pointer + 1, relay_params);
	}
	return USB_RELAY_OK;
}

uint8_t RelayApp_ParseRelayNumber(char* i_data) {
	const char relay_params[] = "RDC";
	char* param_pointer;
	param_pointer = strpbrk(i_data, relay_params);

	while (param_pointer != NULL) {
		char *pNumberEnd;
		uint32_t tmp_val = strtol((char*) (param_pointer + 1), &pNumberEnd, 10);
		if (param_pointer[0] == 'R')
		{
			return tmp_val;
		}
		param_pointer = strpbrk(param_pointer + 1, relay_params);
	}
	return USB_RELAY_MAX_RELAY_NO;
}


uint8_t RelayApp_ParseRelayData(char* i_data, t_relay* realy_data) {
	const char relay_params[] = "RDC";
	char* param_pointer;

	realy_data->cycle_count = UINT32_MAX;
	realy_data->cfg_cycle_count = UINT32_MAX;

	realy_data->delay_ms = 0;
	realy_data->cfg_delay_ms = 0;


	/* 2. Cycle by all params */
	param_pointer = strpbrk(i_data, relay_params);
	while (param_pointer != NULL) {
		/* 2a. extract value from parameter */
		char *pNumberEnd;
		uint32_t tmp_val = strtol((char*) (param_pointer + 1), &pNumberEnd, 10);
		/* 2b. parameter check */
		switch (param_pointer[0]) {
			case 'R': {
				if ((pNumberEnd == NULL) || ((tmp_val >= USB_RELAY_MAX_RELAY_NO))) {
					return USB_RELAY_ERR;
				} else {
					realy_data->relay_number = tmp_val;
				}
				break;
			}
			case 'D': {
				if (pNumberEnd == NULL) {
					/* do nothing */
				} else {
					realy_data->delay_ms = tmp_val;
					realy_data->cfg_delay_ms = tmp_val;
				}
				break;
			}
			case 'C': {
				if (pNumberEnd == NULL) {
					/* do nothing */
				} else {
					realy_data->cycle_count = tmp_val;
					realy_data->cfg_cycle_count = tmp_val;
				}
				break;
			}
		}
		param_pointer = strpbrk(param_pointer + 1, relay_params);
	}
	return USB_RELAY_OK;
}

uint8_t RelayApp_ParseStep(char* i_data, t_step_conf* realy_data) {

	const char relay_params[] = "SP,";
	uint8_t i;
	char* param_pointer;
	realy_data->active_status = 0;
	realy_data->period_ms = 0;
	/* 2. Cycle by all params */
	param_pointer = strpbrk(i_data, relay_params);
	while (param_pointer != NULL) {
		/* 2a. extract value from parameter */
		char *pNumberEnd;
		uint32_t tmp_val = strtol((char*) (param_pointer + 1), &pNumberEnd, 10);
		/* 2b. parameter check */
		switch (param_pointer[0]) {
		case 'S': {
			if ((pNumberEnd == NULL) || ((tmp_val >= 2))) {
				return USB_RELAY_ERR;
			} else {
				realy_data->active_status = tmp_val;
			}
			i |= 0x01;
			break;
		}
		case 'P': {
			if (pNumberEnd == NULL) {
				realy_data->period_ms = 0;
			} else {
				realy_data->period_ms = tmp_val;
			}
			i |= 0x02;
			break;
		}
		case ',': {
			if ((i & 0x01) == 0x01)
				return USB_RELAY_OK;
			return USB_RELAY_ERR;
		}
		default:
			break;
		}
		param_pointer = strpbrk(param_pointer + 1, relay_params);
	}

	if ((i & 0x01) == 0x01)
		return USB_RELAY_OK;
	return USB_RELAY_ERR;
}

uint8_t RelayApp_ActivateStep(t_relay* relay, uint8_t stepNo) {

	if (stepNo < relay->all_steps_count) {
		relay->active_step_number = stepNo;
		memcpy((void *) (&relay->active_step_data),
				(void *) (&(relay->steps_array[stepNo])),
				sizeof(relay->active_step_data));
		return USB_RELAY_OK;
	}
	return USB_RELAY_MAX_STEPS_ERR;
}

//uint8_t RelayApp_ActivateStepToNext(t_relay* relay) {
//	return RelayApp_ActivateStep(relay, (relay->active_step_number + 1) % relay->all_steps_count);
//}

void RelayApp_SetRelayState(t_relay* active_relay) {
	RelayApp_UpdateIO(active_relay->relay_number, active_relay->active_step_data.active_status);
}

t_relay relays[USB_RELAY_MAX_RELAY_NO];

t_relay* RelayApp_Start(void)
{
	memset(relays,0,sizeof(t_relay)*USB_RELAY_MAX_RELAY_NO);
	return relays;
}

void RelayApp_ProcessStep(t_relay* relay) {

	if (relay->cycle_count > 0) {
		/* 0. Process delay */
		if (relay->delay_ms > 0) {
			relay->delay_ms--;
		} else {
			/* 1. Process step period */
			if (relay->active_step_data.period_ms > 0) {
				relay->active_step_data.period_ms--;
			} else {
				RelayApp_SetRelayState(relay);
				if (RelayApp_ActivateStep(relay,relay->active_step_number + 1) == USB_RELAY_MAX_STEPS_ERR)
				{
					RelayApp_ActivateStep(relay, 0);
					/* 2. Process operation count*/
					if (relay->cycle_count != UINT32_MAX) {
						relay->cycle_count--;
					} else {
						/* do not decrement */
					}
				}
			}
		}
	}
}

/* function called in timer */
void RelayApp_ISR() {
    uint8_t i;
	for (i = 0; i < USB_RELAY_MAX_RELAY_NO; i++) {
    	RelayApp_ProcessStep(&relays[i]);
	}
}
