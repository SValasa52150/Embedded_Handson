
#include "main.h"
#include <xc.h>
void ext_interrupt(void) {
    INTE=1;
    INTEDG=0;
    INTF=0;
}
