
#include <xc.h>
#pragma config WDTE = OFF //WATCH DOG TIMER ENABLE BIT (WDT DISABLED)
#include "external_intrpthdr.h"
#include "main.h"
void init_config(void) {
    TRISD = 0b00000000;
    PORTD = 0b00000000;
    TRISB = 0b00000011;
    GIE=1;
    ext_interrupt();
}

void main(void) {
    init_config();
    int c=0;
    while (1) {
        if (c<5)
        {
            if(RB1==0)
            {
            LED1 = !LED1;
            for (unsigned long int i=0; i<100000; i++);//polling where drawback can be observed at rd1 pin and for interrupt rdo works as expected
            }
            c++;
            for (unsigned long int ll=0; ll<100000; ll++);
        }
        else
        {
            c=0;
            SLEEP();//diff for diff uc/compilers
        }

    }
}
