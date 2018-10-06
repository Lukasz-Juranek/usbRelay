#include "doctest.h"

#include <stdint.h>



extern "C" {
	#include "./../USBRelay.X/usb_relay_app.h"
	extern uint8_t RelayApp_ParseRelayData(char* i_data, t_relay* realy_data);
	extern uint8_t RelayApp_ParseStep(char* i_data, t_step_conf *realy_data);
	extern void RelayApp_ProcessStep(t_relay* relay);
}

int last_update_relay_no = -1;
int last_update_io_state = -1;

void RelayApp_UpdateIO(uint8_t relay_number,uint8_t io_state){
	last_update_relay_no = relay_number;
	last_update_io_state = io_state;
}

TEST_CASE( "Valid Step data is parsed corectly") {
	t_step_conf relay_data;
    REQUIRE( RelayApp_ParseStep("S0P1023", &relay_data) == USB_RELAY_OK);
    REQUIRE( relay_data.active_status == 0);
    REQUIRE( relay_data.period_ms == 1023);
}

TEST_CASE( "Valid Relay data is parsed corectly") {
	t_relay relay_data;
    REQUIRE( RelayApp_ParseRelayData("R1D10C44", &relay_data) == USB_RELAY_OK);
    REQUIRE( relay_data.cycle_count == 44);
    REQUIRE( relay_data.relay_number == 1);
    REQUIRE( relay_data.delay_ms == 10);
}


TEST_CASE( "Valid Commands are parsed coreclty") {
	t_relay* relays = RelayApp_Start();
    REQUIRE(RelayApp_ParseWhole("R1D123C456,S1P123,S0P333",relays) == USB_RELAY_OK);

    REQUIRE( relays[1].all_steps_count == 2);

    REQUIRE( relays[1].steps_array[0].period_ms == 123);
    REQUIRE( relays[1].steps_array[0].active_status == 1);

    REQUIRE( relays[1].steps_array[1].period_ms == 333);
	REQUIRE( relays[1].steps_array[1].active_status == 0);

    REQUIRE( relays[1].cfg_delay_ms == 123);
    REQUIRE( relays[1].cfg_cycle_count == 456);

    REQUIRE( relays[1].delay_ms == 123);
    REQUIRE( relays[1].cycle_count == 456);
}

TEST_CASE( "Cycles, and delay are not mandatory, by default infinite cycles, no delay") {
	t_relay* relays = RelayApp_Start();
    REQUIRE(RelayApp_ParseWhole("R0,S1P123,S0P333",relays) == USB_RELAY_OK);

    REQUIRE( relays[0].cfg_delay_ms == 0);
    REQUIRE( relays[0].cfg_cycle_count == UINT32_MAX);

    REQUIRE( relays[0].delay_ms == 0);
    REQUIRE( relays[0].cycle_count == UINT32_MAX);
}


TEST_CASE( "Steps activation is working") {
	t_relay* relays = RelayApp_Start();
	RelayApp_ParseWhole("R2D123C456,S1P123,S0P333",relays);

	// max steps excited
	REQUIRE( RelayApp_ActivateStep(&relays[2],4) == USB_RELAY_MAX_STEPS_ERR);

	REQUIRE(RelayApp_ActivateStep(&relays[2],1) == USB_RELAY_OK);

	relays[2].active_step_data.period_ms = 333;
	relays[2].active_step_data.active_status = 0;
}

TEST_CASE( "Cycling through steps is working") {

	last_update_relay_no = -1;
	last_update_io_state = -1;

	t_relay* relays = RelayApp_Start();
	RelayApp_ParseWhole("R2D1C3,S1P123,S0P333",relays);
	REQUIRE(USB_RELAY_OK == RelayApp_ActivateStep(&relays[2],0));

	for (int i = 0; i < 3; i++)
	{
		REQUIRE(relays[2].active_step_number == 0);
		RelayApp_ProcessStep(&relays[2]);
		for (int i = 0; i < 123; i++)
		{
			RelayApp_ProcessStep(&relays[2]);
		}
		RelayApp_ProcessStep(&relays[2]);
		REQUIRE(last_update_relay_no == 2);
		REQUIRE(last_update_io_state == 1);
		REQUIRE(relays[2].active_step_number == 1);
		for (int i = 0; i < 333; i++)
		{
			RelayApp_ProcessStep(&relays[2]);
		}
		RelayApp_ProcessStep(&relays[2]);
		REQUIRE(last_update_io_state == 0);
		REQUIRE(relays[2].active_step_number == 0);
	}

	for (int i = 0; i < 500; i++)
	{
		RelayApp_ProcessStep(&relays[2]);
	}
	REQUIRE(relays[2].active_step_number == 0);
	REQUIRE(last_update_relay_no == 2);
	REQUIRE(last_update_io_state == 0);
}
