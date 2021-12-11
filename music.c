#include <reg51.h>
sbit  buzzer = P3^7;                                                                   
unsigned char  i=0;                                                                     
unsigned char  tone_H, tone_L;                                                          
void  delay1(unsigned int);                                                          
unsigned char code song[]={3, 3, 7, 7, 8,8 ,7,6,6,5,5,4,4,3 ,15};           
unsigned int code beat[]={500,500,500,500,500,500,1000, 500,500,500,500,500,500,1000};                 
unsigned int code tone[]={956, 852, 759, 716, 638,                                // So(0), La(1) Si(2) Do(3)
                           568, 536, 506, 478, 426, 379, 10};                    // Re(4) Mi (5) Fa(6) So(7) La(8)

void main()
{ 
  buzzer=1;                                                                           
  IE=0x82;                                                                              
  TMOD=0x01;                                                                             
  while(song[i]!=15)                                                                   
    {
    TH0=tone_H=(65536-tone[song[i]])/256;                                        
    TL0= tone_L=(65536-tone[song[i]]) % 256;                                    
    TR0=1;                                                                    
    delay1(beat[i]);                                                             
    i++;                                                                      
    TR0=0;                                                                     
    buzzer=1;                                                                 
    }
}
                                                                     
void tone_timer(void) interrupt 1
{
  TH0=tone_H;                                                             
  TL0=tone_L;                                                          
  buzzer=~buzzer;                                                         
}                                                                   

void delay1(unsigned int x)                                                         
{
  unsigned int  i,j;                                                              
  for (i=0;i<x;i++)
    {
    for (j=0;j<90;j++);                                                               
    }
}                                                  
