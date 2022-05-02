#include "mcc_generated_files/mcc.h"

#define CLK LATCbits.LATC1
#define OUT LATCbits.LATC7
#define CS LATBbits.LATB7

int temp = 0;
long int k = 0;

int adcData[10] = {0,0,0,0,0,0,0,0,0,0};

//Reads data from the ADC and sets colour of the lights
void readADC();

