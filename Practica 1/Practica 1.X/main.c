/*
 * File:   main.c
 * Author: Adriamuz
 *
 * Created on 18 de enero de 2024, 08:28 AM
 */


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 20000000 // Frecuencia de 20MHz

void main(void) {
    ADCON1 = 0X0F; // Todos los bits son digitales.
    
    TRISAbits.RA0 = 0; // 0-> OUTPUT, 1-> INPUT
    
    while(1){
        LATAbits.LA0 = 1; // Enciende
        __delay_ms(1000);
        LATAbits.LA0 = 0; // Apaga
        __delay_ms(1000);
    }
    return;
}
