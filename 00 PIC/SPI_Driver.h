#include "mcc_generated_files/mcc.h"

#define delay NOP(); NOP();

#define CLK LATCbits.LATC1
//#define INPUT LATBbits.LATB5
#define OUT LATCbits.LATC7
#define CS LATBbits.LATB7

int temp = 0;
long int k = 0;

int adcData[10] = {0,0,0,0,0,0,0,0,0,0};

void timer();

void startBits();

//void sendBits();

void readData();

void readADC();

