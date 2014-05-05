#include<pic.h>
#include<lcd.h>

#define sw0 RB0
#define sw1 RB1
#define sw2 RB2
#define sw3 RB3
#define sw4 RB4
#define sw5 RB5
#define sw6 RB6
#define sw7 RB7
#define sw8 RC0
#define sw9 RC1
#define in0 RA0
#define in1 RA1
#define in2 RA2
#define in3 RA3

void ser_init();
void ser_out(unsigned char);

unsigned char data;
bit x;

unsigned int val[4];

void main()
{
   lcd_init();
   ser_init();
   ADCON1=0x60;
   TRISB=0xff;
   TRISC=0x83;
   TRISA=0xaF;
   TRISE=0x30;
   read(0x80);
   lcd_dis(ARROW PNTR BASED, 16);
   read(0xC0);
   lcd_dis(  METER READING , 16);
   delay(65000);
   delay(65000);
   read(0x01);
   read(0x80);
   lcd_dis( METER READING ,16);
   read(0xc5);
   while(1)
   {
      if(in0)
      {
         if(sw0) { read(0xc5); write (0+0x30); val[0]='0';  }
         if(sw1) { read(0xc5); write (1+0x30); val[0]='1';  }
         if(sw2) { read(0xc5); write (2+0x30); val[0]='2';  }
         if(sw3) { read(0xc5); write (3+0x30); val[0]='3';  }
         if(sw4) { read(0xc5); write (4+0x30); val[0]='4';  }
         if(sw5) { read(0xc5); write (5+0x30); val[0]='5';  }
         if(sw6) { read(0xc5); write (6+0x30); val[0]='6';  }
         if(sw7) { read(0xc5); write (7+0x30); val[0]='7';  }
         if(sw8) { read(0xc5); write (8+0x30); val[0]='8';  }
         if(sw9) { read(0xc5); write (9+0x30); val[0]='9';  }
         else   { read(0xc5); write (0+0x30); }
      }
      if(in1)
      {
         if(sw0) { read(0xc6); write (0+0x30); val[1]='0';  }
         if(sw1) { read(0xc6); write (1+0x30); val[1]='1';  }
         if(sw2) { read(0xc6); write (2+0x30); val[1]='2';  }
         if(sw3) { read(0xc6); write (3+0x30); val[1]='3';  }
         if(sw4) { read(0xc6); write (4+0x30); val[1]='4';  }
 if(sw5) { read(0xc6); write (5+0x30); val[1]='5';  }
         if(sw6) { read(0xc6); write (6+0x30); val[1]='6';  }
         if(sw7) { read(0xc6); write (7+0x30); val[1]='7';  }
         if(sw8) { read(0xc6); write (8+0x30); val[1]='8';  }
         if(sw9) { read(0xc6); write (9+0x30); val[1]='9';  }
         else   { read(0xc6); write (0+0x30); }
      }
      if(in2)
      {
         if(sw0) { read(0xc7); write (0+0x30); val[2]='0';  }
         if(sw1) { read(0xc7); write (1+0x30); val[2]='1';  }
         if(sw2) { read(0xc7); write (2+0x30); val[2]='2';  }
         if(sw3) { read(0xc7); write (3+0x30); val[2]='3';  }
         if(sw4) { read(0xc7); write (4+0x30); val[2]='4';  }
         if(sw5) { read(0xc7); write (5+0x30); val[2]='5';  }
         if(sw6) { read(0xc7); write (6+0x30); val[2]='6';  }
         if(sw7) { read(0xc7); write (7+0x30); val[2]='7';  }
         if(sw8) { read(0xc7); write (8+0x30); val[2]='8';  }
         if(sw9) { read(0xc7); write (9+0x30); val[2]='9';  }
         else   { read(0xc7); write (0+0x30); }
      }

      if(in3)
      {
         if(sw0) { read(0xc8); write (0+0x30); val[3]='0';  }
         if(sw1) { read(0xc8); write (1+0x30); val[3]='1';  }
         if(sw2) { read(0xc8); write (2+0x30); val[3]='2';  }
         if(sw3) { read(0xc8); write (3+0x30); val[3]='3';  }
         if(sw4) { read(0xc8); write (4+0x30); val[3]='4';  }
         if(sw5) { read(0xc8); write (5+0x30); val[3]='5';  }
         if(sw6) { read(0xc8); write (6+0x30); val[3]='6';  }
         if(sw7) { read(0xc8); write (7+0x30); val[3]='7';  }
         if(sw8) { read(0xc8); write (8+0x30); val[3]='8';  }
         if(sw9) { read(0xc8); write (9+0x30); val[3]='9';  }
 else   { read(0xc8); write (0+0x30); }
      }
         if(RE0)
         {
            read(0xCC);
            for(i=0;i=3;i++)
            {
               write(val[i]);
               ser_out(val[i]);
               delay(15000);
            }
         }           
 }
}


