
// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define _XTAL_FREQ 4000000
float calc_dist(void);

void main() {
    TRISB=0x00; //B portunun hepsi ç?k??
    PORTB=0x00; //B portu hepsi lojik-0
    TRISC1=0X00;
    unsigned char dist=0;
     
    
    while(1){
        dist = calc_dist()/5;
        switch(dist)
        {
            case 1:
                PORTB=0b00000001; 
             
                break;
                
            case 2:
                PORTB=0b010000;
                
                break; 
            
            default :     
                PORTB=0X00;
        }
          __delay_ms(100);              
        }
    return;
//          PORTB=0b00000001;
//        __delay_ms(1000);
//         PORTB=0b00000000;
//        __delay_ms(1000);
//        
    //bu di?er direncin oldugu yer
        
//         PORTB=0b00000100;  
//        __delay_ms(1000);
//        PORTB=0b00000000;
//        __delay_ms(1000);
        
        
        

    }

//Uzakl?k fonksiyonu
        float calc_dist(void)
{
    float  distance=0; // For Precision Critical Situations, You'll have to make it a ((Floating-Point)) variable
    TMR1=0;
    RC2=1;
    __delay_us(10);
    RC2=0;
    while(!RC3);
    TMR1ON=1;
    while(RC3);
    TMR1ON=0;
    distance = (TMR1/58.82); // Note: fractions will be discarded. But it's OK in our basic tutorial
    
         return distance;
    
    }             
//        TRISC1=0b00000001;
//        __delay_ms(1000);
//        TRISC1=0b00000000;
//        __delay_ms(1000);
        
//        if(PORTB==0b00000001){
//        TRISC1=0b00000001;
//        __delay_ms(1000);
//        }
       
        
        //PORTB=0b00000000;
       // __delay_ms(1000);
 
