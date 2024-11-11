/*
 * File:   main.c
 * Author: DELL
 *
 * Created on 19 October, 2024, 8:32 PM
 */


#include <xc.h>
#pragma config WDTE = OFF //WATCH DOG TIMER ENABLE BIT (WDT DISABLED)
void init_uart();
static void init_config()
{
	init_uart();
	GIE = 1;
	PEIE =1; //pheripherall interrupt enable
	RCIE = 1; //enable serial port interrupt / receive interrupt enable bit

	

} 
unsigned char getchar()
{
	while (RCIF != 1)
	{
		continue;
	}
	RCIF = 0;
	return RCREG;
}
void putchar (unsigned char ch)
{
	TXREG = ch;
	while (TXIF != 1)
	{
		continue;
	}
	TXIF=0;
	
}
void puts(const char *s)
{
	while (*s)
	{
		putchar(*s++);
	}
}
char data;
void main()
{
	init_config();
	while(1)
	{
		//data = getchar();
		if (data != '\0')
		{
			putchar(data);
			data = '\0';
		}
		
		
		//CODE TO TOGGLE THE LED
		
	}
}
extern char data;
void isr()
{
	if (RCIF == 1)
	{
		data = RCREG;
	}
}
void init_uart()
{
	//transmit status and controll reg initialize
	TXEN=1;//enable data transmission
	BRGH = 1;//high baud rate select bit
	//receive status and controll reg initialize
	SPEN = 1;//enable serial port
	CREN = 1;//enable continuous reception
	
	SPBRG = 129;//baud rate reg
	puts("UART TEST CODE \n\r");
}
