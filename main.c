#include <xc.h>         /* XC8 General Include File */
#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */
#include <pic.h>

#pragma config IOSCFS = 8MHZ    // Internal Oscillator Frequency Select bit (8 MHz)
#pragma config MCPU = OFF       // Master Clear Pull-up Enable bit (Pull-up disabled)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config CP = OFF         // Code protection bit (Code protection off)
#pragma config MCLRE = OFF      // GP3/MCLR Pin Function Select bit (GP3/MCLR pin function is digital I/O, MCLR internally tied to VDD)

#define MHz 000000
#define _XTAL_FREQ 8MHz

static void Delay_us(unsigned int DELAY_CNT) {
    for (unsigned int i = 0; i < DELAY_CNT; i++) {
        __delay_us(1);
    }
}

void main(void) {
    
    long int i;
        
    OPTION = 0b11000000;
    TRISGPIO = 0b1100; // input GP3, GP2 / output GP1,GP0    
    ANS0 = 0;   // GP0 = digital
    ANS1 = 0;   // GP1 = digital
    
    GP2=0; GP1=0; GP0=0;

    while(1) {
        
        if((GP3 == 0)&&(GP2 == 0)) {  // optimize to MG996R // MAX
            GP0=1;
            Delay_us(180);
            GP0=0;
            Delay_us(1500-180);   
        };
        
        if((GP3 != 0)&&(GP2 == 0)) {
            GP0=1;
            Delay_us(150);
            GP0=0;
            Delay_us(1500-150);   
            };
         
        if((GP3 == 0)&&(GP2 != 0)) {
            GP0=1;
            Delay_us(125);
            GP0=0;
            Delay_us(1500-125);   
            };
         
        if((GP3 != 0)&&(GP2 != 0)) {
            GP0=1;
            Delay_us(110);
            GP0=0;
            Delay_us(1500-110);   
            };
            
//        if((GP3 != 0)&&(GP2 != 0)) { // MIN
//            GP0=1;
//            Delay_us(50);
//            GP0=0;
//            Delay_us(1500-50);   
//            };
         
    };  //  while(1)
}
