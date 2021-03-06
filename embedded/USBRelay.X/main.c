/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F1455
        Driver Version    :  2.00
 */

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
 */

#include "mcc_generated_files/mcc.h"
#include "usb_relay_app.h"
#include "nvm.h"

#define BUFFER_SIZE 64

#define USB_COMMAND(x) (strcmp(buffer, x)) 

uint8_t buffer[BUFFER_SIZE];

uint8_t bufferPos;

uint8_t LineReception(uint8_t *buffer, uint8_t maxSize);
void FlushString(uint8_t *data);

t_relay* p_relays;

void init_relay_app()
{
    R0_LAT = 1;
    R1_LAT = 1;
    R2_LAT = 1;
    R3_LAT = 1;
    R4_LAT = 1;
    R5_LAT = 1;
    R6_LAT = 1;
    R7_LAT = 1;
    p_relays = RelayApp_Start(); 
    
}

void main(void) {
    // initialize the device
    
    SYSTEM_Initialize();
    
    init_relay_app();
    TMR1_SetInterruptHandler(RelayApp_ISR);
    bufferPos = 0;
    
    
    nvm_read_conf();
    
    
    TMR1_StartTimer();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    
    while (1) {
        USBDeviceTasks();
        if ((USBGetDeviceState() < CONFIGURED_STATE) || (USBIsDeviceSuspended() == true)) {
            continue; //go back to the top of the while loop
        } else {
            //Keep trying to send data to the PC as required
           
            //while(!USBUSARTIsTxTrfReady()) 
            CDCTxService();            
            //Run application code.
            if (LineReception(buffer, BUFFER_SIZE)) {
                
                if (USB_COMMAND("SC") == 0) {                    
                  
                    nvm_save_conf(p_relays);
                    
                    FlushString("OK\n");
                   
                    continue;
                }
                
                if (USB_COMMAND("CLR") == 0)
                {
                    init_relay_app();
                    FlushString("OK\n");
                    continue;
                }
                
                if (USB_COMMAND("ON") == 0)
                {
                    TMR1_StartTimer();
                    FlushString("OK\n");
                    continue;
                }
                
                if (USB_COMMAND("OFF") == 0)
                {
                    TMR1_StopTimer();
                    FlushString("OK\n");
                    continue;
                }
                
                switch (RelayApp_ParseWhole(buffer, p_relays)) {
                    case USB_RELAY_OK:
                        FlushString("OK\n");
                        break;
                    case USB_RELAY_ERR:
                        FlushString("PARSE_ERR\n");
                        break;
                    case USB_RELAY_MAX_STEPS_ERR:
                        FlushString("MAX_STEPS_ERR\n");
                        break;
                    default:
                        FlushString("UNKNOWN\n");
                        break;
                }
            }
        }
    }
}

void FlushString(uint8_t *data) {
    do {
        CDCTxService();
    } while (!USBUSARTIsTxTrfReady());
    putUSBUSART(data, strlen(data));
    CDCTxService();
}

//R2D123C456,S1P123,S0P333
uint8_t LineReception(uint8_t *buffer, uint8_t maxSize) {
    uint8_t rxByte;
    uint8_t cdc_rx_len;
    extern USB_HANDLE CDCDataOutHandle;
    extern volatile unsigned char cdc_data_rx[CDC_DATA_OUT_EP_SIZE];
    if (!USBHandleBusy(CDCDataOutHandle)) {
        if (maxSize > USBHandleGetLength(CDCDataOutHandle)) {
            maxSize = USBHandleGetLength(CDCDataOutHandle);
        }
                
        for (cdc_rx_len = 0; cdc_rx_len < maxSize; cdc_rx_len++) {
            rxByte = cdc_data_rx[cdc_rx_len];
            if (bufferPos < maxSize) {
                buffer[bufferPos] = rxByte;
                if (buffer[bufferPos] == '\r') {
                    buffer[bufferPos] = 0;
                    bufferPos = 0;
                    CDCDataOutHandle = USBRxOnePacket(CDC_DATA_EP, (uint8_t*) & cdc_data_rx, sizeof (cdc_data_rx));
                    return 1;
                }
                bufferPos++;
            } else {
                bufferPos = 0;
            }
        }
    }
    //CDCDataOutHandle = USBRxOnePacket(CDC_DATA_EP, (uint8_t*) & cdc_data_rx, sizeof (cdc_data_rx));
    return 0;
}

void RelayApp_UpdateIO(uint8_t relay_number, uint8_t io_state) {
    switch (relay_number) {
        case 0:
            R7_LAT = (io_state);
            break;
        case 1:
            R6_LAT = (io_state);
            break;
        case 2:
            R5_LAT = (io_state);
            break;
        case 3:
            R4_LAT = (io_state);
            break;
        case 4:
            R3_LAT = (io_state);
            break;
        case 5:
            R2_LAT = (io_state);
            break;
        case 6:
            R1_LAT = (io_state);
            break;
        case 7:
            R0_LAT = (io_state);
            break;
        default:
            break;
    }
}

/**
 End of File
 */