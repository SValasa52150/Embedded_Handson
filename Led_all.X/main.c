/*
 * File:   main.c
 * Author: DELL
 *
 * Created on 1 November, 2024, 3:18 PM
 */


#include <xc.h> //header file which holds the addresses and we can directly use the registers with their names
#pragma config WDTE = OFF //WATCH DOG TIMER ENABLE BIT (WDT DISABLED)
#include "main.h"
void init_config(void) {
    TRISB = 00000000;
    TRISD = 00000000;
    PORTB=00000000;
    PORTD=0xFF;
}

void main(void) {
    init_config();
    while (1) {
        PORTB = ~PORTB;
        PORTD = ~PORTD;
        for (unsigned long int i=0; i <100000; i++);
    }
}
