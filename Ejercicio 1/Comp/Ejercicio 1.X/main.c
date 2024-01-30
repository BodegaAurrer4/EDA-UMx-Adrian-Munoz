/*
 * File:   main.c
 * Author: Adriamuz
 *
 * Created on 29 de enero de 2024, 06:38 PM
 */


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 20000000 // Frecuencia de 20MHz

void main(void) {
    ADCON1 = 0X0F; // Todos los bits digitales
    
    TRISB = 0; // Todos los RB son salidas
    
    while(1){
        LATBbits.LB0 = 1;
        __delay_ms(1000);
        LATBbits.LB1 = 1;
        __delay_ms(1000);
        LATBbits.LB2 = 1;
        __delay_ms(1000);
        LATBbits.LB3 = 1;
        __delay_ms(1000);
        LATBbits.LB4 = 1;
        __delay_ms(1000);
        LATBbits.LB5 = 1;
        __delay_ms(1000);
        LATBbits.LB6 = 1;
        __delay_ms(1000);
        LATBbits.LB7 = 1;
        __delay_ms(1000);
        LATBbits.LB0 = 0;
        __delay_ms(1000);
        LATBbits.LB1 = 0;
        __delay_ms(1000);
        LATBbits.LB2 = 0;
        __delay_ms(1000);
        LATBbits.LB3 = 0;
        __delay_ms(1000);
        LATBbits.LB4 = 0;
        __delay_ms(1000);
        LATBbits.LB5 = 0;
        __delay_ms(1000);
        LATBbits.LB6 = 0;
        __delay_ms(1000);
        LATBbits.LB7 = 0;
        __delay_ms(1000);
    }
    return;
}