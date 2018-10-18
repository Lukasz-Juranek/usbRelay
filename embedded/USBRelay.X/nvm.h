/* 
 * File:   nvm.h
 * Author: ay7vi2
 *
 * Created on July 20, 2018, 10:19 AM
 */

#ifndef NVM_H
#define	NVM_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcc_generated_files/mcc.h"
#include "usb_relay_app.h"
    
uint8_t nvm_read_conf(t_relay* relays_config);
void nvm_save_conf(t_relay* relays_config);
    
typedef struct {
    uint16_t valid_conf;
    t_relay relays_conf[USB_RELAY_MAX_RELAY_NO];
    //uint8_t padding;
} t_nvm_conf;

#ifdef	__cplusplus
}
#endif

#endif	/* NVM_H */

