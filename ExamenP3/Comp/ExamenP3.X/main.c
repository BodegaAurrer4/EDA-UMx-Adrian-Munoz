/*
 * File:   main.c
 * Author: Adriamuz
 *
 * Created on 15 de abril de 2024, 11:14 AM
 */


#include <xc.h>
#include "config.h"
#include <pic18f4550.h>
#include "LCD-XC4.h"
#define _XTAL_FREQ 20000000
void keyboard();
int key[4];
int cont;
int par;

void main(void) {
    ADCON1 = 0X0F;
    TRISD = 1;
    TRISA = 1;
    TRISC = 0;
    mOPEN_LCD;
    mLCD_HOME;
    mLCD_CLEAR;
    LATCbits.LC1=1;
    while(1){
        if(PORTAbits.RA2==1){
            while(PORTAbits.RA2==1);
            
            par=cont/2;
            if(cont-2*par==0){
                LATCbits.LC0=1;
                LATCbits.LC1=0;
            }
            if(cont-2*par==1){
                LATCbits.LC0=0;
                LATCbits.LC1=1;
            }
            cont++;
        }
        if(PORTAbits.RA0==1){
            text_display("Type password");
            mCURSOR_LINE2;
            text_display("Wait");
            __delay_ms(250);
            while(key[0]!=1 | key[1]!=2 | key[2]!=3 | key[3]!=4){
                mLCD_CLEAR;
                keyboard();
                if(key[0]!=1 | key[1]!=2 | key[2]!=3 | key[3]!=4){
                    text_display("Incorrect");
                    mCURSOR_LINE2;
                    text_display("Reintente");
                    LATCbits.LC1=1;
                    LATCbits.LC0=0;
                    __delay_ms(125);
                    key[0]=0;
                    key[1]=0;
                    key[2]=0;
                    key[3]=0;
                }
            }
            mLCD_CLEAR;
            key[0]=0;
            key[1]=0;
            key[2]=0;
            key[3]=0;
            LATCbits.LC1=0;
            LATCbits.LC0=1;
        }
        if(PORTAbits.RA1==1){
            LATCbits.LC0=0;
            LATCbits.LC1=1;
        }
        
    }
    __delay_ms(1000);
    return;
}
void keyboard(){
    int count=0;
    while(count<4){
        __delay_ms(10);
        LATDbits.LD0=1;
        LATDbits.LD1=0;
        LATDbits.LD2=0;
        LATDbits.LD3=0;
        if(PORTDbits.RD7==1){
            while(PORTDbits.RD5==1);
            key[count]=3;
            count++;
        }
        if(PORTDbits.RD6==1){
            while(PORTDbits.RD6==1);
            key[count]=2;
            count++;
        }
        if(PORTDbits.RD5==1){
            key[count]=1;
            while(PORTDbits.RD5==1);
            count++;
        }
        if(PORTDbits.RD4==1){
            count++;
        }
        __delay_ms(10);
        LATDbits.LD0 = 0;
        LATDbits.LD1 = 1;
        LATDbits.LD2 = 0;
        LATDbits.LD3 = 0;
        if(PORTDbits.RD7==1){
            key[count]=9;
            count++;
        }
        if(PORTDbits.RD6==1){
            key[count]=8;
            count++;
        }
        if(PORTDbits.RD5==1){
            key[count]=7;
            count++;
        }
        if(PORTDbits.RD4==1){
            count++;
        }
        __delay_ms(10);
        LATDbits.LD0 = 0;
        LATDbits.LD1 = 0;
        LATDbits.LD2 = 0;
        LATDbits.LD3 = 1;
        if(PORTDbits.RD7==1){
            count++;
        }
        if(PORTDbits.RD6==1){
            key[count]=0;
            count++;
        }
        if(PORTDbits.RD5==1){
            count++;
        }
        if(PORTDbits.RD4==1){
            count++;
        }
        if(PORTAbits.RA2==1){
            while(PORTAbits.RA2==1);
            key[0]=1;
            key[1]=2;
            key[2]=3;
            key[3]=4;
            count=4;
            
        }
    }
}