//data lined port d
//controll lines port ra2-ra5...
#include <xc.h>
#pragma config WDTE = OFF //WATCH DOG TIMER ENABLE BIT (WDT DISABLED)
#include "main.h"
void init_config(void) {
    TRISD = 0b00000000; //PORT D AS OUTPUT
    SSD = 0b00000000; //INITIALLY ALL OFF
    TRISA = TRISA & 0B00000011; //LED'S HAVE COMMON CATHODE WITH RA2-5 CNCTD AS AN INPUT TO TRANSISTOR... SO FOR MC RA IS O/P
}
//approach2
/*void hhh(unsigned char data[])
{
    for (unsigned char p=0; p<4; p++)
    {
        PORTA = (PORTA & 0x03) | (0x04 << p);
        SSD = data[p];
       
    }
     for (int q=0;q<100;q++);
}*/
//end approach2
void main(void) {
    init_config();
    
    while (1) {
       
        //write actual code here
        //APPROACH1
        PORTA = (PORTA & 0b00000011)|(1<<2);
        SSD = 0b00000110;
        for (int i=0;i<100;i++);
        PORTA = (PORTA & 0b00000011)|(1<<3);
        SSD = 0b01011011;
        for (int j=0;j<100;j++);
        PORTA = (PORTA & 0b00000011)|(1<<4);
        SSD = 0b01001111;
        for (int k=0;k<100;k++);
        PORTA = (PORTA & 0b00000011)|(1<<5);
        SSD = 0b01100110;
        for (int l=0;l<100;l++);
        //end of approach 1
        
        //approach2
        // unsigned char disVal[MAX] = [ONE,TWO,THREE,FOUR];
        //hhh(disVal);
        //end approach2

    }
    return;
}
