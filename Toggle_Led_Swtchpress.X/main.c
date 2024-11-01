/*
 * File:   main.c
 * Author: DELL
 *
 * Created on 1 November, 2024, 5:10 PM
 */


#include <xc.h>
#pragma config WDTE = OFF //WATCH DOG TIMER ENABLE BIT (WDT DISABLED)
#include    "main.h"


void init_config(void) {
    TRISD = 0b00000000 ;
    LED_D = 0b11111111;
    TRISB0 = 1;

}

void main(void) {
    init_config();
    while (1) {
        if (RB0==0){
            LED_D= ~LED_D;
        }
        //write actual code here

    }
}
