/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F1455
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 procedures
#define RA0_GetValue()              PORTAbits.RA0

// get/set RA1 procedures
#define RA1_GetValue()              PORTAbits.RA1

// get/set R6 aliases
#define R6_TRIS                 TRISAbits.TRISA4
#define R6_LAT                  LATAbits.LATA4
#define R6_PORT                 PORTAbits.RA4
#define R6_WPU                  WPUAbits.WPUA4
#define R6_ANS                  ANSELAbits.ANSA4
#define R6_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define R6_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define R6_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define R6_GetValue()           PORTAbits.RA4
#define R6_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define R6_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define R6_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define R6_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define R6_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define R6_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set R7 aliases
#define R7_TRIS                 TRISAbits.TRISA5
#define R7_LAT                  LATAbits.LATA5
#define R7_PORT                 PORTAbits.RA5
#define R7_WPU                  WPUAbits.WPUA5
#define R7_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define R7_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define R7_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define R7_GetValue()           PORTAbits.RA5
#define R7_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define R7_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define R7_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define R7_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)

// get/set R0 aliases
#define R0_TRIS                 TRISCbits.TRISC0
#define R0_LAT                  LATCbits.LATC0
#define R0_PORT                 PORTCbits.RC0
#define R0_ANS                  ANSELCbits.ANSC0
#define R0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define R0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define R0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define R0_GetValue()           PORTCbits.RC0
#define R0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define R0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define R0_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define R0_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set R1 aliases
#define R1_TRIS                 TRISCbits.TRISC1
#define R1_LAT                  LATCbits.LATC1
#define R1_PORT                 PORTCbits.RC1
#define R1_ANS                  ANSELCbits.ANSC1
#define R1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define R1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define R1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define R1_GetValue()           PORTCbits.RC1
#define R1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define R1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define R1_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define R1_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set R2 aliases
#define R2_TRIS                 TRISCbits.TRISC2
#define R2_LAT                  LATCbits.LATC2
#define R2_PORT                 PORTCbits.RC2
#define R2_ANS                  ANSELCbits.ANSC2
#define R2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define R2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define R2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define R2_GetValue()           PORTCbits.RC2
#define R2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define R2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define R2_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define R2_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set R3 aliases
#define R3_TRIS                 TRISCbits.TRISC3
#define R3_LAT                  LATCbits.LATC3
#define R3_PORT                 PORTCbits.RC3
#define R3_ANS                  ANSELCbits.ANSC3
#define R3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define R3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define R3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define R3_GetValue()           PORTCbits.RC3
#define R3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define R3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define R3_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define R3_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set R4 aliases
#define R4_TRIS                 TRISCbits.TRISC4
#define R4_LAT                  LATCbits.LATC4
#define R4_PORT                 PORTCbits.RC4
#define R4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define R4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define R4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define R4_GetValue()           PORTCbits.RC4
#define R4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define R4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)

// get/set R5 aliases
#define R5_TRIS                 TRISCbits.TRISC5
#define R5_LAT                  LATCbits.LATC5
#define R5_PORT                 PORTCbits.RC5
#define R5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define R5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define R5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define R5_GetValue()           PORTCbits.RC5
#define R5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define R5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/