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
        Device            :  PIC16F18857
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

// get/set BUTTON aliases
#define BUTTON_TRIS                 TRISAbits.TRISA6
#define BUTTON_LAT                  LATAbits.LATA6
#define BUTTON_PORT                 PORTAbits.RA6
#define BUTTON_WPU                  WPUAbits.WPUA6
#define BUTTON_OD                   ODCONAbits.ODCA6
#define BUTTON_ANS                  ANSELAbits.ANSA6
#define BUTTON_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define BUTTON_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define BUTTON_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define BUTTON_GetValue()           PORTAbits.RA6
#define BUTTON_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define BUTTON_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define BUTTON_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define BUTTON_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define BUTTON_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define BUTTON_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define BUTTON_SetAnalogMode()      do { ANSELAbits.ANSA6 = 1; } while(0)
#define BUTTON_SetDigitalMode()     do { ANSELAbits.ANSA6 = 0; } while(0)

// get/set IO_OPTO aliases
#define IO_OPTO_TRIS                 TRISAbits.TRISA7
#define IO_OPTO_LAT                  LATAbits.LATA7
#define IO_OPTO_PORT                 PORTAbits.RA7
#define IO_OPTO_WPU                  WPUAbits.WPUA7
#define IO_OPTO_OD                   ODCONAbits.ODCA7
#define IO_OPTO_ANS                  ANSELAbits.ANSA7
#define IO_OPTO_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define IO_OPTO_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define IO_OPTO_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define IO_OPTO_GetValue()           PORTAbits.RA7
#define IO_OPTO_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define IO_OPTO_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define IO_OPTO_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define IO_OPTO_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define IO_OPTO_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define IO_OPTO_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define IO_OPTO_SetAnalogMode()      do { ANSELAbits.ANSA7 = 1; } while(0)
#define IO_OPTO_SetDigitalMode()     do { ANSELAbits.ANSA7 = 0; } while(0)

// get/set OPTO_INPUT aliases
#define OPTO_INPUT_TRIS                 TRISBbits.TRISB0
#define OPTO_INPUT_LAT                  LATBbits.LATB0
#define OPTO_INPUT_PORT                 PORTBbits.RB0
#define OPTO_INPUT_WPU                  WPUBbits.WPUB0
#define OPTO_INPUT_OD                   ODCONBbits.ODCB0
#define OPTO_INPUT_ANS                  ANSELBbits.ANSB0
#define OPTO_INPUT_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define OPTO_INPUT_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define OPTO_INPUT_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define OPTO_INPUT_GetValue()           PORTBbits.RB0
#define OPTO_INPUT_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define OPTO_INPUT_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define OPTO_INPUT_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define OPTO_INPUT_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define OPTO_INPUT_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define OPTO_INPUT_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define OPTO_INPUT_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define OPTO_INPUT_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set RB3 procedures
#define RB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define RB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define RB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define RB3_GetValue()              PORTBbits.RB3
#define RB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define RB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define RB3_SetPullup()             do { WPUBbits.WPUB3 = 1; } while(0)
#define RB3_ResetPullup()           do { WPUBbits.WPUB3 = 0; } while(0)
#define RB3_SetAnalogMode()         do { ANSELBbits.ANSB3 = 1; } while(0)
#define RB3_SetDigitalMode()        do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set SCK1 aliases
#define SCK1_TRIS                 TRISCbits.TRISC3
#define SCK1_LAT                  LATCbits.LATC3
#define SCK1_PORT                 PORTCbits.RC3
#define SCK1_WPU                  WPUCbits.WPUC3
#define SCK1_OD                   ODCONCbits.ODCC3
#define SCK1_ANS                  ANSELCbits.ANSC3
#define SCK1_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define SCK1_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define SCK1_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define SCK1_GetValue()           PORTCbits.RC3
#define SCK1_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define SCK1_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define SCK1_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define SCK1_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define SCK1_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define SCK1_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define SCK1_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define SCK1_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set SDI1 aliases
#define SDI1_TRIS                 TRISCbits.TRISC4
#define SDI1_LAT                  LATCbits.LATC4
#define SDI1_PORT                 PORTCbits.RC4
#define SDI1_WPU                  WPUCbits.WPUC4
#define SDI1_OD                   ODCONCbits.ODCC4
#define SDI1_ANS                  ANSELCbits.ANSC4
#define SDI1_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define SDI1_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define SDI1_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define SDI1_GetValue()           PORTCbits.RC4
#define SDI1_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define SDI1_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define SDI1_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define SDI1_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define SDI1_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define SDI1_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define SDI1_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define SDI1_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set CS_SCR aliases
#define CS_SCR_TRIS                 TRISCbits.TRISC5
#define CS_SCR_LAT                  LATCbits.LATC5
#define CS_SCR_PORT                 PORTCbits.RC5
#define CS_SCR_WPU                  WPUCbits.WPUC5
#define CS_SCR_OD                   ODCONCbits.ODCC5
#define CS_SCR_ANS                  ANSELCbits.ANSC5
#define CS_SCR_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define CS_SCR_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define CS_SCR_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define CS_SCR_GetValue()           PORTCbits.RC5
#define CS_SCR_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define CS_SCR_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define CS_SCR_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define CS_SCR_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define CS_SCR_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define CS_SCR_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define CS_SCR_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define CS_SCR_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set SDO1 aliases
#define SDO1_TRIS                 TRISCbits.TRISC6
#define SDO1_LAT                  LATCbits.LATC6
#define SDO1_PORT                 PORTCbits.RC6
#define SDO1_WPU                  WPUCbits.WPUC6
#define SDO1_OD                   ODCONCbits.ODCC6
#define SDO1_ANS                  ANSELCbits.ANSC6
#define SDO1_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define SDO1_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define SDO1_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define SDO1_GetValue()           PORTCbits.RC6
#define SDO1_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define SDO1_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define SDO1_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define SDO1_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define SDO1_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define SDO1_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define SDO1_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define SDO1_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

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