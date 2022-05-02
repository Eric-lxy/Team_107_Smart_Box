#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include "RGB.h"
#include "SPI_Driver.h"
#include <string.h>

//*********************************************************
uint8_t rxData; // esp32 read
//**********************************************************


int IR = 1300;

//UART interupt for recieving colour data from MQTT server
void ISR_3(void)
{   
    UART3_Receive_ISR();
    
    while(!UART3_is_rx_ready());
        rxData = UART3_Read();

}
//Function for sending IR sensor range data to MQTT server
void tx(float dist) 
{
    while(!UART3_is_tx_ready());
    
    printf("%f6.2",dist);
    __delay_ms(0.5);
    printf("\r\n");
    
    while(!UART3_is_tx_done());
    
}

void main(void)
{
    uint16_t currentRange = 0;
    int counter = 0;
    
    // Initialize the device
    SYSTEM_Initialize();
    UART3_Initialize();
    UART3_SetRxInterruptHandler(ISR_3);
    
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
  
    
    //initializing board LED and LED strip 
    LED_SetHigh();

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
        readADC(); //reading FSR and setting LED Strip
        __delay_ms(50);
        
        currentRange = ADCC_GetSingleConversion(IR_OUT); //reading IR sensor value
        
        if(currentRange > IR) //if object is within range turning on board LED
        {
            for(int i = 0; i < numLEDs; i++)
                LED_SetHigh();
        }
        else
            LED_SetLow();
        
        tx(currentRange); //Sending IR sensor value to MQTT server
        
        //MQQT value set lights
        //When a colour name is selected and published to the MQTT server
        //ESP32 retrieves the colour value and the LED Strip colour is set accordingly
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
        rxData = 0; //re-setting rxData for new value
        
    }
}