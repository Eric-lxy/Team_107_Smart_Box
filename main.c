#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include "RGB.h"
#include "SPI_Driver.h"
#include <string.h>

//float currentRange = 5;

char msg[100];
char fmsg[100]="\0";
char colour;
uint8_t Voltage;
uint16_t newVolt;// for pressure sensor
//*********************************************************
uint8_t rxData; // esp32 read
float rxDataf = 0; // esp32 convert to float
float boundingCondition;
float rxDatafLower;
float rxDatafUpper;

int rx_f = 1; // recieve flag
int tx_f = 1; // transmit flag
//**********************************************************


int IR = 1300;

void ISR_3(void)
{/*
        uint8_t rxByte;
        //uint8_t data; // change with the teammates' data
        UART3_Receive_ISR();
            // Logic to echo received data
            if(UART3_is_rx_ready())
            {
                //data = currentRange;
                rxByte = UART3_Read();
                //msg[0]=rxByte;
                if (rxByte == '\0'){
                    //LED_Toggle();
//                    __delay_ms(500);
                }
                strncat(msg,&rxByte,1);

                
                UART3_Write(rxByte); // change teammates' data
            }
        //LED_Toggle();
   */
    
    UART3_Receive_ISR();
    
    while(!UART3_is_rx_ready);
        rxData = UART3_Read();

}

void tx(float dist) 
{
    if(tx_f == 1) {
    while(!UART3_is_tx_ready());
    
    printf("%f6.2",dist);
    __delay_ms(0.5);
    printf("\r\n");
    
    while(!UART3_is_tx_done());
    }
}

void main(void)
{
    uint16_t currentRange = 0;
    //float btnForce = 0;
    int counter = 0;
    
    // Initialize the device
    SYSTEM_Initialize();
    UART3_Initialize();
    UART3_SetRxInterruptHandler(ISR_3);
    //SPI2_Initialize();
    
    ADCC_Initialize();
    ADCC_DisableContinuousConversion();
   
    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
  
    LED_SetHigh();
    //clear(); // Clearing string    
    
    
//    if(counter == 3) // 3 is the number of colours used (number of cases)
//        counter = 0;
//    
    for(int i = 0; i < numLEDs; i++)
    {
        switch(i)
        {
            case 0: // Sets LEDS RED
                for(int i = 0; i < numLEDs; i++)
                    red();
                break;
            case 1: // Sets LEDS GREEN
                for(int i = 0; i < numLEDs; i++)
                    green();
                break;
            case 2: // Sets LEDS BLUE
                for(int i = 0; i < numLEDs; i++)
                    blue();
                break;
        }
        __delay_ms(500);
        counter++;
    }
        
    while (1)
    {
        if(0==strcmp(msg,"abc\0"))// it can work with only one character, but cannot work with a string. How to fix that?
        {
            LED_Toggle();
            __delay_ms(100);
        }
        
        readADC();
        __delay_ms(50);
        
        currentRange = ADCC_GetSingleConversion(IR_OUT); //1250-1268
        
        if(currentRange > IR)
        {
            for(int i = 0; i < numLEDs; i++)
                LED_SetHigh();
        }
        else
            LED_SetLow();
        
        tx(currentRange);
        
        //MQQT value set lights
        
        switch(rxData)
        {
            case 114:
                for(int i = 0; i < numLEDs; i++)
                    red();
                break;
            case 98:
                for(int i = 0; i < numLEDs; i++)
                    blue();
                break;
            case 121:
                for(int i = 0; i < numLEDs; i++)
                    yellow();
                break;
            case 103:
                for(int i = 0; i < numLEDs; i++)
                    green();
                break;
            case 119:
                for(int i = 0; i < numLEDs; i++)
                    white();
                break;
            case 99:
                for(int i = 0; i < numLEDs; i++)
                    clear();     
                break;
        }  
        rxData = 0;
        
    }
}