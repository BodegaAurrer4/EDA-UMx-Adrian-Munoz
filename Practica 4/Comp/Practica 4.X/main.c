/*
 * File:   main.c
 * Author: Adriamuz
 *
 * Created on 8 de febrero de 2024, 09:08 PM
 */


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 20000000

                    // 0   1  2   3   4    5    6    7   8    9    A    b    C   d   E    F
                    // 0   1  2   3   4    5    6    7   8    9    10   11   12  13  14   15
int display_array[] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 103, 119, 124, 57, 94, 121, 113};

void main(void) {
    ADCON1 = 0X0F;
    TRISD = 0;
    
    for(int i=0; i<=15; i++){
        LATD = display_array[i];
        __delay_ms(1000);
    }
    return;
}
