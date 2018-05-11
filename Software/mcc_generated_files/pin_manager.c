/**
  Generated Pin Manager File

  Company:
    Microchip Technology Inc.

  File Name:
    pin_manager.c

  Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F18857
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB             :  MPLAB X 4.15

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.
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

#include <xc.h>
#include "pin_manager.h"
#include "stdbool.h"

#include "../APP/optoCoupleur.h"


void (*IOCBF6_InterruptHandler)(void);


void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;

    /**
    TRISx registers
    */
    TRISA = 0xFF;
    TRISB = 0xD7;
    TRISC = 0x97;

    /**
    ANSELx registers
    */
    ANSELC = 0xE7;
    ANSELB = 0xAF;
    ANSELA = 0xFF;

    /**
    WPUx registers
    */
    WPUE = 0x00;
    WPUB = 0x00;
    WPUA = 0x00;
    WPUC = 0x00;

    /**
    ODx registers
    */
    ODCONA = 0x00;
    ODCONB = 0x00;
    ODCONC = 0x00;


    /**
    IOCx registers 
    */
    //interrupt on change for group IOCBF - flag
    IOCBFbits.IOCBF6 = 0;
    //interrupt on change for group IOCBN - negative
    IOCBNbits.IOCBN6 = 0;
    //interrupt on change for group IOCBP - positive
    IOCBPbits.IOCBP6 = 1;



    // register default IOC callback functions at runtime; use these methods to register a custom function
    IOCBF6_SetInterruptHandler(IOCBF6_DefaultInterruptHandler);
   
    // Enable IOCI interrupt 
    PIE0bits.IOCIE = 1; 
    
	
    SSP1CLKPPSbits.SSP1CLKPPS = 0x13;   //RC3->MSSP1:SCK1;    
    SSP1DATPPSbits.SSP1DATPPS = 0x14;   //RC4->MSSP1:SDI1;    
    RXPPSbits.RXPPS = 0x0C;   //RB4->EUSART:RX;    
    RC3PPS = 0x14;   //RC3->MSSP1:SCK1;    
    RB3PPS = 0x10;   //RB3->EUSART:TX;    
    RC6PPS = 0x15;   //RC6->MSSP1:SDO1;    
}
  
void PIN_MANAGER_IOC(void)
{   
	// interrupt on change for pin IOCBF6
    if(IOCBFbits.IOCBF6 == 1)
    {
        IOCBFbits.IOCBF6 = 0;
        flagButton();
    }	
}

/**
   IOCBF6 Interrupt Service Routine
*/
void IOCBF6_ISR(void) {

    // Add custom IOCBF6 code

    // Call the interrupt handler for the callback registered at runtime
    if(IOCBF6_InterruptHandler)
    {
        IOCBF6_InterruptHandler();
    }
    IOCBFbits.IOCBF6 = 0;
}

/**
  Allows selecting an interrupt handler for IOCBF6 at application runtime
*/
void IOCBF6_SetInterruptHandler(void (* InterruptHandler)(void)){
    IOCBF6_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCBF6
*/
void IOCBF6_DefaultInterruptHandler(void){
    // add your IOCBF6 interrupt custom code
    // or set custom function using IOCBF6_SetInterruptHandler()
}

/**
 End of File
*/