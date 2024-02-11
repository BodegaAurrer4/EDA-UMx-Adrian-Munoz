/*
 * File:   main.c
 * Author: Adriamuz
 *
 * Created on 8 de febrero de 2024, 07:54 AM
 */


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 20000000

#define player1button PORTCbits.RC0
#define player2button PORTCbits.RC1
#define izquierda PORTAbits.RA0
#define centro PORTAbits.RA1
#define derecha PORTAbits.RA2
#define player1led PORTDbits.RD0
#define player2led PORTDbits.RD1

int DELAY = 100;
int num1 = 0;
int num2 = 0;
int DPSW = 0;

int corridorp1();
int corridorp2();
void gamelogic();

int corridorp1(){
        LATBbits.LB0=1;
        num1 = 1;
        __delay_ms(DELAY);
        LATBbits.LB0=0;
        LATBbits.LB1=1;
        num1 = 2;
        __delay_ms(DELAY);
        LATBbits.LB1=0;
        LATBbits.LB2=1;
        num1 = 3;
        __delay_ms(DELAY);
        LATBbits.LB2=0;
        LATBbits.LB3=1;
        num1 = 4;
        __delay_ms(DELAY);
        LATBbits.LB3=0;
        LATBbits.LB4=1;
        num1 = 5;
        __delay_ms(DELAY);
        LATBbits.LB4=0;
        LATBbits.LB5=1;
        num1 = 6;
        __delay_ms(DELAY);
        LATBbits.LB5=0;
        LATBbits.LB6=1;
        num1 = 7;
        __delay_ms(DELAY);
        LATBbits.LB6=0;
        LATBbits.LB7=1;
        num1 = 8;
        __delay_ms(DELAY);
        LATBbits.LB7=0;
        LATBbits.LB6=1;
        num1 = 7;
        __delay_ms(DELAY);
        LATBbits.LB6=0;
        LATBbits.LB5=1;
        num1 = 6;
        __delay_ms(DELAY);
        LATBbits.LB5=0;
        LATBbits.LB4=1;
        num1 = 5;
        __delay_ms(DELAY);
        LATBbits.LB4=0;
        LATBbits.LB3=1;
        num1 = 4;
        __delay_ms(DELAY);
        LATBbits.LB3=0;
        LATBbits.LB2=1;
        num1 = 3;
        __delay_ms(DELAY);
        LATBbits.LB2=0;
        LATBbits.LB1=1;
        num1 = 2;
        __delay_ms(DELAY);
        LATBbits.LB1=0;
        LATBbits.LB0=1;
        num1 = 1;
        
        return num1;
}

int corridorp2(){
        LATBbits.LB0=1;
        num2 = 1;
        __delay_ms(DELAY);
        LATBbits.LB0=0;
        LATBbits.LB1=1;
        num2 = 2;
        __delay_ms(DELAY);
        LATBbits.LB1=0;
        LATBbits.LB2=1;
        num2 = 3;
        __delay_ms(DELAY);
        LATBbits.LB2=0;
        LATBbits.LB3=1;
        num2 = 4;
        __delay_ms(DELAY);
        LATBbits.LB3=0;
        LATBbits.LB4=1;
        num2 = 5;
        __delay_ms(DELAY);
        LATBbits.LB4=0;
        LATBbits.LB5=1;
        num2 = 6;
        __delay_ms(DELAY);
        LATBbits.LB5=0;
        LATBbits.LB6=1;
        num2 = 7;
        __delay_ms(DELAY);
        LATBbits.LB6=0;
        LATBbits.LB7=1;
        num2 = 8;
        __delay_ms(DELAY);
        LATBbits.LB7=0;
        LATBbits.LB6=1;
        num2 = 7;
        __delay_ms(DELAY);
        LATBbits.LB6=0;
        LATBbits.LB5=1;
        num2 = 6;
        __delay_ms(DELAY);
        LATBbits.LB5=0;
        LATBbits.LB4=1;
        num2 = 5;
        __delay_ms(DELAY);
        LATBbits.LB4=0;
        LATBbits.LB3=1;
        num2 = 4;
        __delay_ms(DELAY);
        LATBbits.LB3=0;
        LATBbits.LB2=1;
        num2 = 3;
        __delay_ms(DELAY);
        LATBbits.LB2=0;
        LATBbits.LB1=1;
        num2 = 2;
        __delay_ms(DELAY);
        LATBbits.LB1=0;
        LATBbits.LB0=1;
        num2 = 1;
        
        return num2;
}

void gamelogic(){
    if (izquierda == 1){
        DPSW++;
    } else if (izquierda == 0){
        DPSW = DPSW - 1;
    }
    if (centro == 1){
        DPSW++;
    } else if (centro == 0){
        DPSW = DPSW - 1;
    }
    if (derecha == 1){
        DPSW++;
    } else if (derecha == 0){
        DPSW = DPSW - 1;
    }
    
    if(DPSW == 1){
        if(izquierda == 1){
            if (player1button == 0){
                corridorp1();
                while(player1button == 0);
            }
            if (player2button == 0){
                corridorp2();
                while(player2button == 0);
            }
            if (num1<num2){
                LATDbits.LD0 = 1;
            } else if (num1>num2){
                LATDbits.LD1 = 1;
            } else {
                LATD = 1;
            }
        }
        if(derecha == 1){
            if (player1button == 0){
                corridorp1();
                while(player1button == 0);
            }
            if (player2button == 0){
                corridorp2();
                while(player2button == 0);
            }
            if (num1>num2){
                LATDbits.LD0 = 1;
            } else if (num1<num2){
                LATDbits.LD1 = 1;
            } else {
                LATD = 1;
            }
        }
    } else {
        LATB = 1;
        __delay_ms(400);
        LATB = 0;
        __delay_ms(400);
        while(DPSW != 1);
    }
    
    return;
}

void main(void){
    ADCON1 = 0X0F;
    TRISA = 1;
    TRISB = 0;
    TRISC = 1;
    TRISD = 0;
    
    while (1){
        gamelogic();
        __delay_ms(3000);
    }
    return;
}