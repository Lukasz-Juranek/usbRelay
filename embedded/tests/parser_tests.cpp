#include "catch.hpp"
#include "./../USBRelay.X/usb_relay_app.h"

TEST_CASE( "Valid data is parsed coreclty", "[parser]" ) {
    t_relay_data relay_data;
    REQUIRE( RelayApp_ParseCommand("R1S0P1023D123C343", &relay_data) == 1 );
    REQUIRE( relay_data.relay_number == 1);
    REQUIRE( relay_data.is_closed == 0);
    REQUIRE( relay_data.period_ms == 1023);
    REQUIRE( relay_data.delay_ms == 123);
    REQUIRE( relay_data.operation_count == 343);
}
