
#include "main.h"
#include <xc.h>
void __interrupt() isr(void)
{
    if(INTF==1)
    {
        RD0 = !RD0;
        INTF=0;
    }
    
}
