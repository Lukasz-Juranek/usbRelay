#include "nvm.h"
#include "mcc_generated_files/memory.h"
#include "usb_relay_app.h"
// 50 * 80 = 400
#define USB_CONF_SIZE (USB_RELAY_MAX_RELAY_NO * sizeof(t_relay))
#define dataeeAddr (((END_FLASH - USB_CONF_SIZE - WRITE_FLASH_BLOCKSIZE)) & ((END_FLASH-1) ^ (ERASE_FLASH_BLOCKSIZE-1)))
#define CONF_VALID_KEY 0xAB

const uint8_t config_table[0x3FF] __at(0x1600);

/* nvm is 14 bit wide - so only 8 bit is used from each address*/

uint8_t nvm_read_conf(){
        uint8_t tmp_byte = 0;
        uint16_t w_offset = FLASH_ReadByte(dataeeAddr - WRITE_FLASH_BLOCKSIZE);
        extern t_relay* p_relays;
        t_relay* relays_config = p_relays;
        
        if ((uint8_t)w_offset == CONF_VALID_KEY)
        {
            for (w_offset = 0; w_offset < USB_CONF_SIZE; w_offset += sizeof(tmp_byte))
            {
                tmp_byte = FLASH_ReadByte(dataeeAddr + w_offset);
                memcpy(((uint8_t*)relays_config) + w_offset, &tmp_byte, sizeof(tmp_byte));
            }
            return 1; 
        } 
    return 0;
}

void nvm_save_conf() {
    uint16_t w_offset = CONF_VALID_KEY;
    extern t_relay* p_relays;

    t_relay* relays_config = p_relays;
    FLASH_WriteBlock(dataeeAddr - WRITE_FLASH_BLOCKSIZE, &w_offset);
    for (w_offset = 0; w_offset <= (USB_CONF_SIZE + WRITE_FLASH_BLOCKSIZE); w_offset += WRITE_FLASH_BLOCKSIZE) {
        FLASH_WriteBlock(dataeeAddr + w_offset, ((uint8_t*) relays_config) + w_offset);
    }
}

