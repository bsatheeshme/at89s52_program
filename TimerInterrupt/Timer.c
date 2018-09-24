// Source: http://www.8051projects.net/plugins/forum/forum_viewtopic.php?41545.0#post_41554

/*
Crystal_Freq	Machine Frequency	Time(microSec)					Time(ms)
12000000	12	1000000	     	1		65536	15536	1		50	  	3CB0	TH0=0X3C	TL0=0XB0
11059200	12	921600	     	1.085069444	65536	19456	1.085069444	50		4C00	TH0=0X4C	TL0=0X00
16000000	12	1333333.333	0.75		65536	0	0.75		49.152		0	TH0=0X00	TL0=0X00
*/

#include<reg51.h>
 
unsigned char count;
void timer () interrupt 1
{
  TH0=0X3C;
  TL0=0XB0;
  count++;
}
void main (void)
{
count=0;
  TMOD=0X01;
  TH0=0X3C;
  TL0=0XB0;
  IE=0X82;      // enable timer 0 interrupt 
  TR0=1;          //run timer 0
while (1)
{
if (count==20)
count=0;
// it mean delay is 1 sec
}
}

