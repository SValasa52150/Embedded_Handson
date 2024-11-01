

#include <xc.h>
#pragma config WDTE = OFF //WATCH DOG TIMER ENABLE BIT (WDT DISABLED)
#include "main.h"
void init_config(void) {
    TRISD = 0b00000000 ;
    LED_D = 0b11111111;
    TRISB = TRISB|0b00000011;//little endian model---- rb0 & are inputs now

}
void main(void) {
    init_config();
    int flag = 1;
     int c = 50000;
    while (1) {

        //level triggering
          if (RB1==0 && flag==1){
            flag=0;
            LED_D= ~LED_D;
            for(unsigned long int i=0;i<50000;i++);//blocking delay
        }
          else if (RB1==1){
            flag = 1;
        }
        //edge triggering with non blocking delay
        if (RB0==0)
        {
            if (c-- == 0){
                c=50000;

                LED_D= ~LED_D;
            }
        }
        

    }
}
