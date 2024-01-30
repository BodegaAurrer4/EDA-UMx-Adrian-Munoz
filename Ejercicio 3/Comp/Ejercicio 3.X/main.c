/*
 * File:   main.c
 * Author: Adriamuz
 *
 * Created on 29 de enero de 2024, 02:06 PM
 */


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 20000000 // Frecuencia de 20MHz

#define btnSum PORTAbits.RA0 //Boton de suma
#define btnRes PORTAbits.RA1 //Boton de resta
#define btnRst PORTAbits.RA2 //Boton RESET

int SumValue = 0;

void main(void) {
    ADCON1 = 0X0F; //Todos los bits son digitales
    TRISB = 0; //Todos los RB como salidas
    TRISAbits.RA0 = 1;
    TRISAbits.RA1 = 1;
    TRISAbits.RA2 = 1; //Bits RA como entrada
    
    while (1){
        if (btnSum == 1){
            SumValue++;
            while(btnSum == 1);
        }
        if (btnRes == 1){
            SumValue = SumValue - 1;
            while(btnRes == 1);
        }
        if (btnRst == 1){
            SumValue = 0;
            while(btnRst == 1);
        }
        LATB = SumValue;
    }
    return;
}
