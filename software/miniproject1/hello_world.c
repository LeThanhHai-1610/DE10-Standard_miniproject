#include <stdio.h>
#include <sys/alt_timestamp.h>
#include <sys/alt_alarm.h>
#include <altera_avalon_pio_regs.h>
#include <system.h>
#include <unistd.h>
#include <stdint.h>
#include <math.h>

#define ADC (*(volatile int*)0x4081000)
#define SW  (*(volatile int*)0x4081080)
static int b=0x0c;
const int num[12] = {0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x2e,0x56};
const int table[10] ={0x48,0x45,0x4c,0x4c,0x4f,0x57,0x4f,0x52,0x4c,0x44};
const int v[]={0x56,0x6f,0x6c,0x74,0x61,0x67,0x65,0x3a};
void SendCommand (alt_u8 cmd){
	IOWR_ALTERA_AVALON_PIO_DATA(GPIO_BASE,0x0100 | cmd);
	delay_ms(40);
	IOWR_ALTERA_AVALON_PIO_DATA(GPIO_BASE,0x0000 | cmd);
	delay_ms(40);
	//IOWR_ALTERA_AVALON_PIO_DATA(GPIO_BASE,0x0100 | cmd);
	//delay_ms(50);
}
void SendData (alt_u8 data){
	IOWR_ALTERA_AVALON_PIO_DATA(GPIO_BASE,0x0500 | data);
	delay_ms(40);
	IOWR_ALTERA_AVALON_PIO_DATA(GPIO_BASE,0x0400 | data);
	delay_ms(40);
	//IOWR_ALTERA_AVALON_PIO_DATA(GPIO_BASE,0x0500 | data);
	//delay_ms(50);
}

alt_u32 blink(void* context){
static int i=1;
	if (IORD_ALTERA_AVALON_PIO_DATA(SW_BASE)==0x03){
		IOWR_ALTERA_AVALON_PIO_DATA(LEDR_BASE,i);
		i=i<<1;
		if(i==1024)
			i = 1;}
	if (IORD_ALTERA_AVALON_PIO_DATA(SW_BASE)==0x01){
		SendCommand(b);
		delay_ms(50);
		b=b^0x04;}
	if (IORD_ALTERA_AVALON_PIO_DATA(SW_BASE)==0x00){
		IOWR_ALTERA_AVALON_PIO_DATA(LEDR_BASE,0);
		SendCommand(0x08);
	}
	return 0.5*alt_ticks_per_second();
}


alt_u32 adc(void* context){
	    int c=0, d=0, e=0, f=0;
		int *p=&ADC;
		if (SW==0x02){
			SendCommand(0x0c);
			p=&ADC;
			int t=(5*(*p)*1000)/pow(2,12);
			printf("%d ",t);
			if (t>3000)IOWR_ALTERA_AVALON_PIO_DATA(LEDR_BASE,1023);
			else IOWR_ALTERA_AVALON_PIO_DATA(LEDR_BASE,0);
			//delay_ms(200);
			division(t,&c,&d,&e,&f);
			SendCommand(0xc9);
			SendData(num[c]);
			SendData(num[10]);
			SendData(num[d]);
			SendData(num[e]);
			SendData(num[f]);
			delay_ms(50);
		}
		if (IORD_ALTERA_AVALON_PIO_DATA(SW_BASE)==0x00){
				IOWR_ALTERA_AVALON_PIO_DATA(LEDR_BASE,0);
				SendCommand(0x08);
		}
return 0.01*alt_ticks_per_second();
}

void delay_ms(int a)
{
	float t1,t2;
	int b = (a*0.001*50000000);
	t1 = alt_timestamp_start();
	t1 = alt_timestamp();

	t2 = (t1 + b) ;
	 while(t1<t2)
	 {
	    t1 = (alt_timestamp());
	 }
}
int division(int count, int *c, int *d, int *e, int *f)
{
		    *c = count / 1000;
			*d = (count - 1000 * *c)/100;
			*e = (count - *c * 1000 - *d * 100) / 10;
			*f = (count - *c * 1000 - *d * 100 - *e * 10);
}
int main()
{

	SendCommand(0x38); // 8 bit, 2 line 5x7 dots
	SendCommand(0x000F);  // display on cursor blinking
	SendCommand(0x0001);   // clear display (also clear DDRAM content
	SendCommand(0x0006);   // entry mode
	SendCommand(0x83);  //line 1 start from position 3
	for(int i=0;i<10;i++){
		SendData(table[i]);
	}
	SendCommand(0xc0);
	for(int i=0;i<8;i++){
	    SendData(v[i]);
	}
    SendCommand(0xce);
    SendData(num[11]);
	static alt_alarm alarm1;
	alt_alarm_start(&alarm1,alt_ticks_per_second()/2,blink, NULL);
    static alt_alarm alarm2;
    alt_alarm_start(&alarm2,0.01*alt_ticks_per_second(),adc, NULL);

}






