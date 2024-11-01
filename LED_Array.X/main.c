
#include <xc.h>
#pragma config WDTE = OFF //WATCH DOG TIMER ENABLE BIT (WDT DISABLED)
#include "main.h"
void init_config(void) {
    TRISD=0b00000000;
    TRISB=0x00;
    LED_B=0xFF;
    LED_D = 0b00000000;
    

}

void main(void) {
    init_config();
    for (unsigned long int i = 0;i<100000;i++);
    LED_B = LED_B & 0b11111110;
    for (unsigned long int i = 0;i<100000;i++);

    while (1) 
    {
        //write actual code here
        int p = 0;
        while (p<8)
        {
            LED_B = (LED_B << 1)|0b00000001;
            LED_D = (LED_D << 1)|0b00000001;
            p=p++;
            for (unsigned long int l = 0;l<100000;l++);
            if (LED_B==0b11111111)
            {
                LED_B = 0b00000000;
            
            }
            
        }
    }
}
