/*
 * File:   main.c
 * Author: Adriamuz
 *
 * Created on 25 de enero de 2024, 08:08 AM
 */


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 20000000 // Frecuencia de 20MHz

#define btnSum PORTAbits.RA0 //Boton de suma

int sumValue = 0;

void main(void) {
    ADCON1 = 0X0F; //Todos los bits son digitales
    TRISB = 0; //Todos los RB son salidas
    TRISAbits.RA0 = 1; //Puerto RA0 como entrada
    
    while(1){
        if(btnSum == 1){
            sumValue++; // sumValue = sumValue + 1
            while(btnSum == 1);
        }
        LATB = sumValue; //El valor de sumValue es enviado a las salidas RB
    }
    
    return;
}