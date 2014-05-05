LCD DISPLAY

#include<pic.h>

#define rs RC4
#define en RC5
unsigned int i, j, k, a, b, c, d;
void delay(unsigned int j)
{
   while(j--);
}
void read (unsigned char addr)
{
   en=0;
   rs=0;
   PORTD=addr;
   delay(1000);
   en=0;
}
void write (unsigned char data)
{
   en=1;
   rs=0;
   PORTD=data;
   delay(1000);
   en=1;
}
void lcd_init()
{
   TRISC=0;
   TRISD=0;
   read(0x83);
   read(0x60);
   read(0xc0);
   read(0x01);
}
void lcd_dis(const unsigned char* word, unsigned int k)
{

   for(i=0;i<k;i++)
   {
      write(word[i]);
   }
}
void hex_dec(unsigned int x)
{
   a=x/1000;
   x=x%1000;
   b=x/100;
   x=x%100;
   c=x/10;
   x=x%10;
   d=x;
   write(a+0x30);   
   write(b+0x30);
   write(c+0x30);
   write(d+0x30);
}
