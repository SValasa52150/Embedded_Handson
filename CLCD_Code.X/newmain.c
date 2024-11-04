
#include <xc.h>
#pragma config WDTE = OFF //WATCH DOG TIMER ENABLE BIT (WDT DISABLED)
#define _XTAL_FREQ                  20000000

/*details reg thr ports used & addresses
 rd0-rd7 data lines
 re1 - we are supposed to tell clcd that we are done giving input through clock
 registor select bit for data/instructions is RE2
 0x80-0x8e -- line 1 addresses of clcd
 0xc0-0xce -- line 1 addresses of clcd
 */


clcd_write(char mode, unsigned char data)
{
    RE2=mode;
    PORTD=data;
    RE1=1;
    __delay_us(100);
    RE1=0;
    __delay_us(4100);//clcd will not take more than 4.1 msec to process the data
}

void init_clcd_controller(void)
{
   __delay_us(30);
   clcd_write(0,0x33);
   __delay_us(4100);
   clcd_write(0,0x33);
   __delay_us(100);
   clcd_write(0,0x33);
   __delay_us(1);
   clcd_write(0,0x38);//choose 2 lines and 5x8 dots
   clcd_write(0,0x01);//clear the display
   clcd_write(0,0x0c); //turn on the display and turnoff the cursor
}
void clcd_putch(char ch, char addr)
{
    clcd_write(0,addr);//mode is instruction
    clcd_write(1,ch);//mode is data
}
void clcd_putstr(char *str, char addr)
{
    clcd_write(0,addr);//mode is instruction and no need to increment the addr all the time
    while(*str)
    {
        clcd_write(1,*str);
        str++;
    }
}
void init_config(void) {
    //initializations here
    TRISD = 0x00;
    TRISE1=0;
    TRISE2=0;
    init_clcd_controller();//initialize clcd controller in 8bit mode
}

void main(void) {
    init_config();
    while (1) {
        //write actual code here
        clcd_putch('A',0x80);
        clcd_putch('B',0x81);
        clcd_putch('C',0x82);
        clcd_putch('d',0x83);
        clcd_putstr(".....",0x84);
        clcd_putch('z',0x8e);
        clcd_putstr("hello world",0xc0);

    }
}
