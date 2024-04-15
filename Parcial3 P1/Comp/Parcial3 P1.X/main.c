/*
 * File:   main.c
 * Author: Adriamuz
 *
 * Created on 14 de marzo de 2024, 07:36 AM
 */


#include <xc.h>
#include "config.h"
#include "LCD-XC4.h"
#define _XTAL_FREQ 20000000

void main(void) {
    ADCON1 = 0X0F;
    mOPEN_LCD;
    while(1){
    mLCD_HOME;
    mLCD_CLEAR;
    text_display("N WORD");
    mCURSOR_LINE2;
    text_display("ISHOWMEAT");
    __delay_ms(1000);
    }
    return;
}