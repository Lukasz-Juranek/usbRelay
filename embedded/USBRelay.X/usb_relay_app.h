/* 
 * File:   usb_relay_app.h
 * Author: ay7vi2
 *
 * Created on 20 wrze?nia 2018, 09:32
 */

#ifndef USB_RELAY_APP_H
#define	USB_RELAY_APP_H

#ifdef	__cplusplus
extern "C" {
#endif

#define USB_RELAY_MAX_RELAY_NO 8
#define USB_RELAY_MAX_STEPS_COUNT 5
    
#define USB_RELAY_OK 1
#define USB_RELAY_ERR 0
#define USB_RELAY_MAX_STEPS_ERR 2

typedef struct {
    uint8_t  active_status;
    uint32_t period_ms;
}t_step_conf;

typedef struct {
	uint8_t relay_number;

	uint32_t cfg_cycle_count;
    uint32_t cfg_delay_ms;

    uint32_t cycle_count;
    uint32_t delay_ms;

    t_step_conf active_step_data;
    uint8_t all_steps_count;
    uint8_t active_step_number;
    t_step_conf steps_array[USB_RELAY_MAX_STEPS_COUNT];
} t_relay;

void RelayApp_ISR(void);
t_relay* RelayApp_Start(void);
uint8_t RelayApp_ActivateStep(t_relay* relay, uint8_t stepNo);
uint8_t RelayApp_ParseWhole(char* i_data, t_relay* relay_array);

#ifdef	__cplusplus
}
#endif

#endif	/* USB_RELAY_APP_H */

