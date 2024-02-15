/*
 * File:   main.c
 * Author: Adriamuz
 *
 * Created on 15 de febrero de 2024, 08:33 AM
 */


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 20000000

                    // 0   1  2   3   4    5    6    7   8    9    A    b    C   d   E    F
                    // 0   1  2   3   4    5    6    7   8    9    10   11   12  13  14   15
int display_array[] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 103, 119, 124, 57, 94, 121, 113};

void main(void) {
    ADCON1 = 0X0F;
    TRISAbits.RA0 = 0;
    TRISAbits.RA1 = 0;
    TRISAbits.RA2 = 0;
    TRISAbits.RA3 = 0;
    TRISBbits.RB0 = 1;
    TRISBbits.RB1 = 1;
    TRISBbits.RB2 = 1;
    TRISBbits.RB3 = 1;
    TRISD = 0;
    
    while(1){
        LATAbits.LA0 = 1;
        if(PORTBbits.RB0 == 1){
            LATD = display_array[1];
        }else if(PORTBbits.RB1 == 1){
            LATD = display_array[2];
        }else if(PORTBbits.RB2 == 1){
            LATD = display_array[3];
        }else if(PORTBbits.RB3 == 1){
            LATD = display_array[10];
        }
        __delay_ms(1);
        LATAbits.LA0 = 0;
        LATAbits.LA1 = 1;
        if(PORTBbits.RB0 == 1){
            LATD = display_array[4];
        }else if(PORTBbits.RB1 == 1){
            LATD = display_array[5];
        }else if(PORTBbits.RB2 == 1){
            LATD = display_array[6];
        }else if(PORTBbits.RB3 == 1){
            LATD = display_array[11];
        }
        __delay_ms(1);
        LATAbits.LA1 = 0;
        LATAbits.LA2 = 1;
        if(PORTBbits.RB0 == 1){
            LATD = display_array[7];
        }else if(PORTBbits.RB1 == 1){
            LATD = display_array[8];
        }else if(PORTBbits.RB2 == 1){
            LATD = display_array[9];
        }else if(PORTBbits.RB3 == 1){
            LATD = display_array[12];
        }
        __delay_ms(1);
        LATAbits.LA2 = 0;
        LATAbits.LA3 = 1;
        if(PORTBbits.RB0 == 1){
            LATD = display_array[14];
        }else if(PORTBbits.RB1 == 1){
            LATD = display_array[0];
        }else if(PORTBbits.RB2 == 1){
            LATD = display_array[15];
        }else if(PORTBbits.RB3 == 1){
            LATD = display_array[13];
        }
        __delay_ms(1);
        LATAbits.LA3 = 0;
    }
    
    return;
}