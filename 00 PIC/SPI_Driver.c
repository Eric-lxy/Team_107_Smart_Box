#include "SPI_Driver.h"
#include "RGB.h"
 
int counter = 0;

//SPI driver for MCP3002 ADC
void readADC()
{
    k = 0;
        
    CS = 0;
    CLK = 0;
    OUT = 1;
    
    __delay_us(1);
    
    CLK = 1;
    
    __delay_us(1);
    
    CLK = 0;
    __delay_us(1);
    
    CLK = 1;
    __delay_us(1);
    
    CLK = 0;
    
    OUT = 0;
    __delay_us(1);
    
    CLK = 1;
    __delay_us(1);
    
    CLK = 0;
    OUT = 1;
    
    __delay_us(1);
    
    CLK = 1;
    
    __delay_us(1);
    
    CLK = 0;
    __delay_us(1);
    
    CLK = 1;
    
    __delay_us(1);
    
    CLK = 0;
    __delay_us(1);
    CLK = 1;
    
    
    __delay_us(1);
    
    CLK = 0;
    __delay_us(1);
    
    CLK = 1;
    adcData[0] = INPUT_GetValue();
    NOP();
    NOP();
    
    CLK = 0;
    __delay_us(1);
    
    CLK = 1;
    adcData[1] = INPUT_GetValue();
    
    NOP();
    NOP();
    CLK = 0;
    __delay_us(1);
    
    CLK = 1;
    adcData[2] = INPUT_GetValue();
    
    NOP();
    NOP();
    CLK = 0;
    __delay_us(1);
    
    CLK = 1;
    adcData[3] = INPUT_GetValue();
    
    NOP();
    NOP();
    CLK = 0;
    __delay_us(1);
    
    CLK = 1;
    adcData[4] = INPUT_GetValue();
    
    NOP();
    NOP();
    CLK = 0;
    __delay_us(1);
    
    CLK = 1;
    adcData[5] = INPUT_GetValue();
    
    NOP();
    NOP();
    CLK = 0;
    __delay_us(1);
    
    CLK = 1;
    adcData[6] = INPUT_GetValue();
    
    NOP();
    NOP();
    CLK = 0;
    __delay_us(1);
    
    CLK = 1;
    adcData[7] = INPUT_GetValue();
    
    NOP();
    NOP();
    CLK = 0;
    __delay_us(1);
    
    CLK = 1;
    adcData[8] = INPUT_GetValue();
    
    NOP();
    NOP();
    CLK = 0;
    __delay_us(1);
   
    CLK = 1;
    adcData[9] = INPUT_GetValue();
    
    NOP();
    NOP();
    
    CLK = 0;
    CS = 1;
    __delay_us(1);
    
    CLK = 1;
    
    __delay_us(1);
    
    CS = 0;
    CLK = 0;
    
    __delay_us(1);
    
    CLK = 1;
    
   __delay_us(1);
    
    CLK = 0;
    __delay_us(1);
    
    CLK = 1;
    
    __delay_us(1);
    
    CLK = 0;
    OUT = 0;
    __delay_us(1);
    
    CLK = 1;
    
    __delay_us(1);
    
    CLK = 0;
    __delay_us(1);
    
    CLK = 1;
        
    CS = 1;
    
    
    //Converting binary value to integer
    uint16_t data = adcData[0];
        
    for(int i = 1; i < 10; i++)
    {
        data = data << 1;
        data = data | adcData[i];
    }
    
    
    //cycling through colours on medium pressure presses
    if (data < 900 && data > 250)
    {
        counter++;
        
        if(counter == 4) 
            counter = 0;
            
        
        switch(counter)
        {
            case 0:
                for(int i = 0; i < numLEDs; i++)
                    green();
                break;
            case 1: // Sets LEDS RED
                for(int i = 0; i < numLEDs; i++)
                    red();
                break;
            case 2: // Sets LEDS GREEN
                for(int i = 0; i < numLEDs; i++)
                    yellow();
                break;
            case 3: // Sets LEDS BLUE
                for(int i = 0; i < numLEDs; i++)
                    blue();
                break;
            }
    }
    //Clearing LED strip on a hard press
    if (data > 975) 
    {
        for(int i = 0; i < numLEDs; i++)
            clear();
    }
        
    __delay_ms(500);
    
}
