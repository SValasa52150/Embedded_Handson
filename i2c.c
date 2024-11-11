//pic16f877a uc is capable of communicating in uart,i2c,spi and can
//rtc available on the uc is capable of communicating in i2c mode only
//objective : uc should read complete time from the rtc and display on the clcd
//rc3- serial clock , rc4- serial data

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
	init_i2c();
	

} 

char data;
void main()
{
	init_config();
	while(1)
	{

		
	}
}
void init_uart() 
{
	//initialize sspstat
	SMP = 1;//Any fluctuations in voltage
	//initialize sspcon1
	SSPEN = 1;//enable data clock line
	SSPM3=1;//as all sspm3,sspm2,sspm1,sspm0 are zero by default and we needed to make our uc to functiona as a master and the values ranges for master and slave depending on the addr mode tooo	
	//initialize sspcon2
	//initialize sspadd
	SSPADD = 49 ;//(Fosc/(4*baud)) - 1;//20mh - fosc and baud rate = 100k so o/p = 49	
	
}
//bus is idle
void init_bus_Idle()
{
	while (R/nw	|| (SSPCON2 & Ox1F)!= 0 );//wit untill no activity on the bus
}
//transmit start bit
void init_trans_start_Bit()
{
	init_bus_Idle();
	SEN = 1;
}
//transmit a stop bit
void init_Trans_stop_bit()
{
	init_bus_Idle();
	PEN = 1;
}
// transmit repeat start bit
void init_Trans_repeat_start _bit()
{
	init_bus_Idle();
	RSEN =1;
}


char init_write(char datawr)
{
	init_bus_Idle();
	SSPBUF =datawr;
	return !ACKSTAT;//returns true if slave has consumed the data
}

char init_read(char ack)
{
	init_bus_Idle();
	RCEN = 1; //Enable receive
	init_bus_Idle();
	if (ack == 0)
	{
		ACKDT == 1; //no ack req by the slave
	}
	else
	{
		ACKDT == 0; // ack req by the slave
	}
	ACKEN = 1; //generate ack seq an this gets transmitted
	return SSPBUF;
} 

