/*
 * File:   main.c
 * Author: Adriamuz
 *
 * Created on 9 de febrero de 2024, 10:17 AM
 */


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 20000000

                    // 0   1  2   3   4    5    6    7   8    9    A    b    C   d   E    F
                    // 0   1  2   3   4    5    6    7   8    9    10   11   12  13  14   15
int display_array[] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 103, 119, 124, 57, 94, 121, 113};

void main(void) {
    ADCON1 = 0X0F;
    TRISB = 1;
    TRISD = 0;
    
    while(1){
        if(PORTB == 0){
            LATD = display_array[0];
        }
        if(PORTB == 1){
            LATD = display_array[1];
        }
        if(PORTB == 2){
            LATD = display_array[2];
        }
        if(PORTB == 3){
            LATD = display_array[3];
        }
        if(PORTB == 4){
            LATD = display_array[4];
        }
        if(PORTB == 5){
            LATD = display_array[5];
        }
        if(PORTB == 6){
            LATD = display_array[6];
        }
        if(PORTB == 7){
            LATD = display_array[7];
        }
        if(PORTB == 8){
            LATD = display_array[8];
        }
        if(PORTB == 9){
            LATD = display_array[9];
        }
        if(PORTB == 10){
            LATD = display_array[10];
        }
        if(PORTB == 11){
            LATD = display_array[11];
        }
        if(PORTB == 12){
            LATD = display_array[12];
        }
        if(PORTB == 13){
            LATD = display_array[13];
        }
        if(PORTB == 14){
            LATD = display_array[14];
        }
        if(PORTB == 15){
            LATD = display_array[15];
        }
    }
    return;
}