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

#define MAX_RELAY_NO 8
    
typedef struct {
    uint8_t relay_number;
    uint8_t is_closed;
    uint32_t operation_count;
    uint32_t period_ms;
    uint32_t delay_ms;
}t_relay_data;

uint8_t RelayApp_ParseCommand(char* i_data, t_relay_data *realy_data);

#ifdef	__cplusplus
}
#endif

#endif	/* USB_RELAY_APP_H */

