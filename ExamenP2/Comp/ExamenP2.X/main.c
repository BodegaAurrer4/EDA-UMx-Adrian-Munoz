/*
 * File:   main.c
 * Author: Adriamuz
 *
 * Created on 6 de marzo de 2024, 05:55 PM
 */


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 20000000

void ADC_init(void); // ADC
int ADC_read(int); // VALOR 0-1023

int v1 = 0;
int v2 = 0;
int v3 = 0;
int v4 = 0;
int v5 = 0;
int bomb = 0;
int dif=0;
                    // 0   1  2   3   4    5    6    7   8    9    A    b    C   d   E    F
                    // 0   1  2   3   4    5    6    7   8    9    10   11   12  13  14   15
int display_array[] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 103, 119, 124, 57, 94, 121, 113};

void main(void) {
    TRISD = 0; // DISPLAYS
    TRISCbits.RC0 = 0; // LED INDICADOR
    TRISCbits.RC1 = 1; // BOTON DE ARRANQUE/PARO
    TRISCbits.RC2 = 0; // BOMBA (LED)
    TRISEbits.RE0 = 0; // DISPLAY ENTERO
    TRISEbits.RE1 = 0; // DISPLAY DECIMAL
    ADC_init();
    while(1){
        v1 = ADC_read(0);
        v2 = ADC_read(1);
        v3 = ((v1+v2)/2)/10.23; // 1 - 1023
        // PARA MOSTRAR LAS LECTURAS DE ADC
        v4 = v3/10; 
        LATD = display_array[v4]; //DISPLAY DECIMAL
        LATEbits.LATE0 = 0;
        LATEbits.LATE1 = 1;
        __delay_ms(50);
        v5 = v3 -(v4*10);
        LATD = display_array[v5]; //DISPLAY ENTERO
        LATEbits.LATE0 = 1;
        LATEbits.LATE1 = 0;
        __delay_ms(50);
        if(PORTCbits.RC1==1)
        {
           
            bomb =bomb+1;
            while(PORTCbits.RC1==1);
        }
        __delay_ms(20);
        if(bomb==1)
        {
            LATCbits.LATC2 = 1;
        }
        __delay_ms(10);
        if(bomb==2)
        {
            bomb=0;
            LATCbits.LATC2 = 0;
        }
        __delay_ms(10);
        if(v3 <=10 ){
            LATCbits.LATC2 = 0;
            LATCbits.LATC0 = 1;
            bomb=0;
        }
        dif=ADC_read(0)-ADC_read(1);
        if(dif <0)
        {
            dif=-dif;
        }
        if(dif>=100 ){
            LATCbits.LATC2 = 0;
            bomb=0;
            LATCbits.LATC0 = 1;
        }
        if(v3 >10)
        {
            LATCbits.LATC0 = 0;
        }
        
        
    }
   
    return;
}
void ADC_init(void){
    TRISA = 0xFF; // ENTRADAS
    ADCON1 = 0x0D; // ANALOG A0 / A1
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