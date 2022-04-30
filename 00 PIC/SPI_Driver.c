#include "SPI_Driver.h"
#include "RGB.h"
 
int counter = 0;

void readADC()
{
    k = 0;
    
    //startBits();
    //TMR0_StartTimer();
    
    CS = 0;
    CLK = 0;
    OUT = 1;
    
    __delay_us(1);
    
    CLK = 1;
    //delay;
    
    __delay_us(1);
    
    CLK = 0;
    __delay_us(1);
    
    CLK = 1;
    __delay_us(1);
    
    CLK = 0;
    
    OUT = 0;
    __delay_us(1);
    
    CLK = 1;
    //delay;
    __delay_us(1);
    
    CLK = 0;
    OUT = 1;
    
    __delay_us(1);
    
    CLK = 1;
    
    //timer();
    
    //delay;
    __delay_us(1);
    
    CLK = 0;
    //delay;
    __delay_us(1);
    
    CLK = 1;
    
    //readData();
    
    //timer();
    
    //delay;
    __delay_us(1);
    
    CLK = 0;
    //delay;
    __delay_us(1);
    CLK = 1;
    
    
    /*
    for(int i = 0; i<10; i++)
    {
        //timer();
        
        //delay;
        NOP();
        NOP();
        CLK = 0;
        //delay;
        NOP();
        NOP();
        CLK = 1;
        
        adcData[i] = INPUT_GetValue();
    }
    */
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
    
    //delay;
    
    NOP();
    NOP();
    
    CLK = 0;
    CS = 1;
    __delay_us(1);
    
    CLK = 1;
    //delay;
    
    __delay_us(1);
    
    CS = 0;
    CLK = 0;
    //delay;
    
    __delay_us(1);
    
    CLK = 1;
    //timer();
    
    //delay;
   __delay_us(1);
    
    CLK = 0;
    //delay;
    __delay_us(1);
    
    CLK = 1;
    
    //delay;
    __delay_us(1);
    
    CLK = 0;
    OUT = 0;
    //delay;
    __delay_us(1);
    
    CLK = 1;
    //timer();
    
    //delay;
    __delay_us(1);
    
    CLK = 0;
    //delay;
    __delay_us(1);
    
    CLK = 1;
    
    
    
    CS = 1;
    
    
//    for (int i = 0; i < 10; i++)
//            k = 10 * k + adcData[i];
        
    uint16_t data = adcData[0];
    
    for(int i = 1; i < 10; i++)
    {
        data = data << 1;
        data = data | adcData[i];
    }
    
//    __delay_ms(500);
        
    
    if (data < 900 && data > 250) //Voltage Less than 3 (Estimated 200g Force or Less)0000000000
    {
        counter++;
        
        if(counter == 4) // 3 is the number of colours used (number of cases)
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
    
    if (data > 975) //Voltage Greater than 3 (Estimated 200g Force or More)
    {
        for(int i = 0; i < numLEDs; i++)
            clear();
    }
        
    __delay_ms(500);
    
    //TMR0_StopTimer();
}
