#ifndef _LCD_H_

#define _LCD_H_


unsigned char k=0,j=0;
unsigned char save=0;

void lcd_init(void);
void lcd_cmd(unsigned char cmd);
void latch(void);
void dely_ns(unsigned char tim);
void lcd_char(unsigned char single);
void lcd_string(unsigned char str[32]);
void lcd_string_signed(char* str);
void lcd_showvalue(unsigned char num);
void lcd_gotoxy(unsigned char row,unsigned char column);
void delay_ms(unsigned int ms);
void lcd_clear();

void lcd_init(void)	//init the lcd
{	
	delay_ms(20);
	save=PORTB;
	DDRB=0xFF;
	delay_ms(15);
	PORTB=0x20;
	lcd_cmd(0x01);
	lcd_cmd(0x02);
	lcd_cmd(0X80);
	delay_ms(20);
}

void latch(void)
{
PORTB&=~0x04;
dely_ns(200);  
PORTB|=0x04;
dely_ns(200);  
PORTB&=~0x04;
}

void dely_ns(unsigned char tim)
{
	for(j=0;j<tim;j++)
	{
		for(k=0;k<11;k++)
		{};
	}
}

void lcd_cmd(unsigned char cmd)
{
	PORTB&=~0x07;
	PORTB=((cmd&0xF0));			
	latch();
	PORTB=(((cmd&(0x0F))*16));	
	latch();
}


void lcd_char(unsigned char single)
{
	PORTB=0x01;
	PORTB=0x00;
	PORTB=(single&0xF0)|0x01;						
	latch();
	PORTB=((single&(0x0F))*16)|0x01;
	latch();
}

void lcd_string(unsigned char str[32])
{
	unsigned char k=0;
	PORTB=0x01;
	PORTB=0X00;
		while(str[k]!='\0')	//Till null character is encountered
		{
			if(k==16)
				lcd_cmd(0XC0);
			PORTB=((str[k])&0xF0)|0x01;
			latch();
			PORTB=((str[k]&(0x0F))*16)|0x01;
			latch();
			k++;
		}
}
void lcd_string_signed(char* str)
{
	unsigned char k=0;
	PORTB=0x01;
	PORTB=0X00;
		while(str[k]!='\0')	//Till null character is encountered
		{
			if(k==16)
				lcd_cmd(0XC0);
			PORTB=((str[k])&0xF0)|0x01;
			latch();
			PORTB=((str[k]&(0x0F))*16)|0x01;
			latch();
			k++;
		}
}

void lcd_showvalue(unsigned char num)	//prints the decimal 3digit value of num
{
	unsigned char H=0,T=0,O=0;
	H=num/100;
	T=(num - (H*100))/10;
	O=(num - (H*100) - (T*10));
	
	lcd_char(H+48);
	lcd_char(T+48);
	lcd_char(O+48);
}

void lcd_gotoxy(unsigned char row,unsigned char column)			//move cursor to the specified position
{
   if(row==0)
    {
	 lcd_cmd(0x80+column);
	}
   else if(row==1)
	{
	 lcd_cmd(0xC0+column);	
	}	
}


void delay_ms(unsigned int ms)
{
	int i;

	while (ms-- > 0)
	{
		
		for (i = 0; i < 3276; ++i)
			asm("nop");
	}
}

void lcd_clear()
{
 lcd_cmd(0x01);
}
#endif 