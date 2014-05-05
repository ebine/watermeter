/*RECEIVER*/

void ser_init()
{
   SPEN=1;
   TXEN=1;
   BRGH=1;
   SPBRG=129;      
}
void ser_out(unsigned char x)
{
   TXREG=x;
   while(TXIF);
   TXIF=0;
   delay(500);
}

#include<pic.h>
#include<lcd.h>

void ser_init();

unsigned char data;
bit x;

void main()
{
	lcd_init();
	ser_init();
	read(0x80);
	lcd_dis("  PWD SERVER    ",16);
	read(0xc0);
	lcd_dis("METER VALUE:    ",16);
	read(0xcc);

	while(1)
	{
		if(x)
		{
			write(data);
			x=0;
		}
	}
}

void ser_init()
{
	CREN=1;
	BRGH=1;
	SYNC=0;
	SPBRG=25;
}

void interrupt rec(void)
{
	if(RCIF)
	{
		data=RCREG;
		x=1;
	}
}
