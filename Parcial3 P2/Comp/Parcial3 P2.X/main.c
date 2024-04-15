/*
 * File:   main.c
 * Author: Adriamuz
 *
 * Created on 14 de marzo de 2024, 08:45 AM
 */


#include <xc.h>
#include "config.h"
#include "LCD-XC4.h"
#define _XTAL_FREQ 20000000

void ADC_init(void);
int ADC_read(int);

int v1 = 0;

void main(void) {
    mOPEN_LCD;
    ADC_init();
    while(1){
        v1 = ADC_read(0);
        mLCD_HOME;
        mLCD_CLEAR;
        text_display(v1);
        __delay_ms(1000);
    }
    return;
}

void ADC_init(void){
    TRISA = 0xFF; // ENTRADAS
    ADCON1 = 0x0E; // ANALOG A0 / A1
    ADCON2 = 0xB5; // JUSTIFICADO A LA DERECHA CON 16 TAD Y FOSC/16
    // LIMPIEZA DE REGISTROS
    ADRESH = 0; 
    ADRESL = 0; 
}

int ADC_read(int chanel){
    int digital = 0;
    ADCON0 = (ADCON0 & 0b11000011)|((chanel << 2) & 0b00111100);
    ADCON0 |=((1<<ADON)| (1 << GO));
    while(ADCON0bits.GO_nDONE==1);
    digital = (ADRESH*256)|(ADRESL);
    return digital;
}