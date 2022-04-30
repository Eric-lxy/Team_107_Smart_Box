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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F16Q40
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
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

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LED aliases
#define LED_TRIS                 TRISAbits.TRISA5
#define LED_LAT                  LATAbits.LATA5
#define LED_PORT                 PORTAbits.RA5
#define LED_WPU                  WPUAbits.WPUA5
#define LED_OD                   ODCONAbits.ODCA5
#define LED_ANS                  ANSELAbits.ANSELA5
#define LED_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define LED_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define LED_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define LED_GetValue()           PORTAbits.RA5
#define LED_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define LED_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define LED_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define LED_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set LEDS aliases
#define LEDS_TRIS                 TRISBbits.TRISB4
#define LEDS_LAT                  LATBbits.LATB4
#define LEDS_PORT                 PORTBbits.RB4
#define LEDS_WPU                  WPUBbits.WPUB4
#define LEDS_OD                   ODCONBbits.ODCB4
#define LEDS_ANS                  ANSELBbits.ANSELB4
#define LEDS_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define LEDS_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define LEDS_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define LEDS_GetValue()           PORTBbits.RB4
#define LEDS_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define LEDS_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define LEDS_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define LEDS_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define LEDS_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define LEDS_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define LEDS_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define LEDS_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set INPUT aliases
#define INPUT_TRIS                 TRISBbits.TRISB5
#define INPUT_LAT                  LATBbits.LATB5
#define INPUT_PORT                 PORTBbits.RB5
#define INPUT_WPU                  WPUBbits.WPUB5
#define INPUT_OD                   ODCONBbits.ODCB5
#define INPUT_ANS                  ANSELBbits.ANSELB5
#define INPUT_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define INPUT_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define INPUT_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define INPUT_GetValue()           PORTBbits.RB5
#define INPUT_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define INPUT_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define INPUT_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define INPUT_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define INPUT_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define INPUT_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define INPUT_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define INPUT_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set CS aliases
#define CS_TRIS                 TRISBbits.TRISB7
#define CS_LAT                  LATBbits.LATB7
#define CS_PORT                 PORTBbits.RB7
#define CS_WPU                  WPUBbits.WPUB7
#define CS_OD                   ODCONBbits.ODCB7
#define CS_ANS                  ANSELBbits.ANSELB7
#define CS_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define CS_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define CS_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define CS_GetValue()           PORTBbits.RB7
#define CS_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define CS_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define CS_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define CS_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define CS_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define CS_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define CS_SetAnalogMode()      do { ANSELBbits.ANSELB7 = 1; } while(0)
#define CS_SetDigitalMode()     do { ANSELBbits.ANSELB7 = 0; } while(0)

// get/set CLK aliases
#define CLK_TRIS                 TRISCbits.TRISC1
#define CLK_LAT                  LATCbits.LATC1
#define CLK_PORT                 PORTCbits.RC1
#define CLK_WPU                  WPUCbits.WPUC1
#define CLK_OD                   ODCONCbits.ODCC1
#define CLK_ANS                  ANSELCbits.ANSELC1
#define CLK_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define CLK_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define CLK_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define CLK_GetValue()           PORTCbits.RC1
#define CLK_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define CLK_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define CLK_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define CLK_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define CLK_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define CLK_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define CLK_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define CLK_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set RC2 procedures
#define RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RC2_GetValue()              PORTCbits.RC2
#define RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define RC2_SetPullup()             do { WPUCbits.WPUC2 = 1; } while(0)
#define RC2_ResetPullup()           do { WPUCbits.WPUC2 = 0; } while(0)
#define RC2_SetAnalogMode()         do { ANSELCbits.ANSELC2 = 1; } while(0)
#define RC2_SetDigitalMode()        do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSELC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set IR_OUT aliases
#define IR_OUT_TRIS                 TRISCbits.TRISC6
#define IR_OUT_LAT                  LATCbits.LATC6
#define IR_OUT_PORT                 PORTCbits.RC6
#define IR_OUT_WPU                  WPUCbits.WPUC6
#define IR_OUT_OD                   ODCONCbits.ODCC6
#define IR_OUT_ANS                  ANSELCbits.ANSELC6
#define IR_OUT_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define IR_OUT_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define IR_OUT_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define IR_OUT_GetValue()           PORTCbits.RC6
#define IR_OUT_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define IR_OUT_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define IR_OUT_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define IR_OUT_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define IR_OUT_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define IR_OUT_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define IR_OUT_SetAnalogMode()      do { ANSELCbits.ANSELC6 = 1; } while(0)
#define IR_OUT_SetDigitalMode()     do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set OUT aliases
#define OUT_TRIS                 TRISCbits.TRISC7
#define OUT_LAT                  LATCbits.LATC7
#define OUT_PORT                 PORTCbits.RC7
#define OUT_WPU                  WPUCbits.WPUC7
#define OUT_OD                   ODCONCbits.ODCC7
#define OUT_ANS                  ANSELCbits.ANSELC7
#define OUT_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define OUT_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define OUT_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define OUT_GetValue()           PORTCbits.RC7
#define OUT_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define OUT_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define OUT_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define OUT_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define OUT_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define OUT_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define OUT_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define OUT_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)

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