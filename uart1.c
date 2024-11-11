static void init_config()
{
	init_uart();

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

void main()
{
	init_config();
	while(1)
	{
		data = getchar();
		putchar(data);
	}
}
void init_uart(unsigned long baud)
{
	TXEN=1;
	BRGH = 1;
	SPEN = 1;
	CREN = 1;
	SPBRG= (FOSC/(16*baud))-1;
	puts("UART TEST CODE \n\r")
}