/*
 * File:   main.c
 * Author: Adriamuz
 *
 * Created on 31 de enero de 2024, 05:06 PM
 */


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 20000000 //Frecuencia de 20 MHz


void main(void) {
    ADCON1 = 0X0F;
    
    TRISB = 0;
    
    while(1){
        LATBbits.LB0 = 1;
        LATBbits.LB1 = 1;
        LATBbits.LB2 = 1;
        LATBbits.LB3 = 1;
        LATBbits.LB4 = 1;
        LATBbits.LB5 = 1;
        LATBbits.LB6 = 1;
        LATBbits.LB7 = 1;
    }
    return;
}
