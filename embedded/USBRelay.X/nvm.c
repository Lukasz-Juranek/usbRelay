#include "nvm.h"
#include "mcc_generated_files/memory.h"
// 50 * 80 = 400
#define USB_CONF_SIZE (USB_RELAY_MAX_RELAY_NO * sizeof(t_relay))
#define dataeeAddr (((END_FLASH - USB_CONF_SIZE - WRITE_FLASH_BLOCKSIZE)) & ((END_FLASH-1) ^ (ERASE_FLASH_BLOCKSIZE-1)))
#define CONF_VALID_KEY 0xABCD

uint8_t nvm_read_conf(t_relay *relays_config)
{
    uint16_t martusia = 0;
    uint16_t w_offset = FLASH_ReadWord(dataeeAddr - WRITE_FLASH_BLOCKSIZE);
    
    if (w_offset == CONF_VALID_KEY)
    {
        for (w_offset = 0; w_offset <= USB_CONF_SIZE; w_offset += sizeof(martusia))
        {
            martusia = FLASH_ReadWord(dataeeAddr + w_offset);
            memcpy(((uint8_t*)relays_config) + w_offset, &martusia, sizeof(martusia));
        }
        return 1; 
    } else {
        return 0;
    }
}

void nvm_save_conf(t_relay* relays_config)
{
    uint16_t w_offset = CONF_VALID_KEY;
    FLASH_WriteBlock(dataeeAddr - WRITE_FLASH_BLOCKSIZE, &w_offset); 
    for (w_offset = 0; w_offset <= (USB_CONF_SIZE + WRITE_FLASH_BLOCKSIZE); w_offset += WRITE_FLASH_BLOCKSIZE)
    {
        FLASH_WriteBlock(dataeeAddr + w_offset, ((uint8_t*)relays_config) + w_offset); 
    }    
}

