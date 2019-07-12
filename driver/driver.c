#include <regx51.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QKOD (4)

#define R1 P1_0
#define R2 P1_1
#define R3 P1_2
#define R4 P1_3
#define C1 P1_4
#define C2 P1_5
#define C3 P1_6
#define C4 P1_7

#define Q1 P0_0
#define Q2 P0_1
#define Q3 P0_2
#define Q4 P0_3
#define Q5 P0_4
#define Q6 P0_5
#define Q7 P0_6
#define Q8 P0_7

#define Q9  P2_0
#define Q10 P2_1
#define Q11 P2_2
#define Q12 P2_3
#define Q13 P2_4
#define Q14 P2_5
#define Q15 P2_6
#define Q16 P2_7

char codesaved[QKOD];
char codein[QKOD];
char a;
char b;

void Delay(int a)
{
  unsigned int i, j;
  for(i=0;i<a;i++)
  {
     for(j=0;j<100;j++) {}
  }
}
char read_key()
{
  int a=2;
  C1=1;
  C2=1;
  C3=1;
  C4=1;
  R1=0;
  R2=1;
  R3=1;
  R4=1;
  if(C1==0){Delay(a);while(C1==0);return '7';}
  if(C2==0){Delay(a);while(C2==0);return '8';}
  if(C3==0){Delay(a);while(C3==0);return '9';}
  if(C4==0){Delay(a);while(C4==0);return '/';}
  R1=1;
  R2=0;
  R3=1;
  R4=1;
  if(C1==0){Delay(a);while(C1==0);return '4';}
  if(C2==0){Delay(a);while(C2==0);return '5';}
  if(C3==0){Delay(a);while(C3==0);return '6';}
  if(C4==0){Delay(a);while(C4==0);return '*';}
  R1=1;
  R2=1;
  R3=0;
  R4=1;
  if(C1==0){Delay(a);while(C1==0);return '1';}
  if(C2==0){Delay(a);while(C2==0);return '2';}
  if(C3==0){Delay(a);while(C3==0);return '3';}
  if(C4==0){Delay(a);while(C4==0);return '-';}
  R1=1;
  R2=1;
  R3=1;
  R4=0;
  if(C1==0){Delay(a);while(C1==0);return 'C';}
  if(C2==0){Delay(a);while(C2==0);return '0';}
  if(C3==0){Delay(a);while(C3==0);return '=';}
  if(C4==0){Delay(a);while(C4==0);return '+';}
  return 0;
}
void clear16seg()
{
	P0_0=1; P0_1=1; P0_2=1; P0_3=1; P0_4=1; P0_5=1; P0_6=1; P0_7=1;
	P2_0=1; P2_1=1; P2_2=1; P2_3=1; P2_4=1; P2_5=1; P2_6=1; P2_7=1;
}
void write_key(char b)
{
	clear16seg();
	switch(b)
	{
		case '7':
			Q1=0; Q2=0; Q11=0; Q15=0;
			break;
		case '8':
			Q1=0; Q2=0; Q3=0; Q4=0; Q5=0; Q6=0; Q7=0; Q8=0; Q16=0; Q12=0;
			break;
		case '9':
			Q1=0; Q2=0; Q3=0; Q4=0; Q5=0; Q6=0; Q8=0; Q16=0; Q12=0;
			break;
		case '+':
			Q10=0; Q14=0; Q16=0; Q12=0;
			break;
		case '4':
			Q4=0; Q8=0; Q16=0; Q12=0;
			break;
		case '5':
			Q1=0; Q2=0; Q4=0; Q5=0; Q6=0; Q8=0; Q16=0; Q12=0;
			break;
		case '6':
			Q1=0; Q2=0; Q4=0; Q5=0; Q6=0; Q7=0; Q8=0; Q16=0; Q12=0;
			break;
		case '-':
			Q16=0; Q12=0;
			break;
		case '1':
			Q11=0; Q3=0; Q4=0;
			break;
		case '2':
			Q1=0; Q2=0; Q3=0; Q5=0; Q6=0; Q7=0; Q16=0; Q12=0;
			break;
		case '3':
			Q1=0; Q2=0; Q3=0; Q4=0; Q5=0; Q6=0; Q16=0; Q12=0;
			break;
		case '*':
			Q16=0; Q9=0; Q10=0; Q11=0; Q12=0; Q13=0; Q14=0; Q15=0;
			break;
		case 'C':
			Q1=0; Q2=0; Q5=0; Q6=0; Q7=0; Q8=0;
			break;
		case '0':
			Q1=0; Q2=0; Q3=0; Q4=0; Q5=0; Q6=0; Q7=0; Q8=0;
			break;
		case '=':
			Q16=0; Q12=0; Q6=0; Q5=0;
			break;
		case '/':
			Q15=0; Q11=0;
			break;
		default:
			clear16seg();
			break;
	}
	Delay(500);
}
void policeiscoming()
{ 
	int k;
	int a=400;
	clear16seg();Delay(2*a);
	Q8=0; Q1=0; Q2=0; Q3=0; Q16=0; Q12=0; Q7=0;
	Delay(a); clear16seg();
	Q8=0; Q1=0; Q2=0; Q3=0; Q4=0; Q5=0; Q6=0; Q7=0;
	Delay(a); clear16seg();
	Q8=0; Q5=0; Q6=0; Q7=0;
	Delay(a); clear16seg();
	Q10=0; Q14=0;
	Delay(a); clear16seg();
	Q8=0; Q1=0; Q2=0; Q5=0; Q6=0; Q7=0;
	Delay(a); clear16seg();
	Q8=0; Q1=0; Q2=0; Q16=0; Q12=0; Q5=0; Q6=0; Q7=0;
	Delay(a); clear16seg(); Delay(2*a);
	Q10=0; Q14=0;
	Delay(a); clear16seg();
	Q8=0; Q1=0; Q2=0; Q16=0; Q4=0; Q5=0; Q6=0; Q12=0;
	Delay(a); clear16seg(); Delay(2*a);
	Q8=0; Q1=0; Q2=0; Q5=0; Q6=0; Q7=0;
	Delay(a); clear16seg();
	Q8=0; Q1=0; Q2=0; Q3=0; Q4=0; Q5=0; Q6=0; Q7=0;
	Delay(a); clear16seg();
	Q8=0; Q1=0; Q2=0; Q3=0; Q4=0; Q10=0; Q14=0; Q7=0;
	Delay(a); clear16seg();
	Q10=0; Q14=0;
	Delay(a); clear16seg();
	Q8=0; Q7=0; Q9=0; Q13=0; Q4=0; Q4=0; Q3=0; 
	Delay(a); clear16seg();
	Q8=0; Q1=0; Q2=0; Q12=0; Q4=0; Q5=0; Q6=0; Q7=0;
	Delay(a); clear16seg(); Delay(2*a);
	for(k=0;k<5;k++)
	{
		Delay(2*a);
		Q9=~Q9; Q11=~Q11; Q7=~Q7; Q6=~Q6; Q5=~Q5; Q4=~Q4;
		Delay(2*a); clear16seg();
	}
}
void guesscode()
{
	int a=400;
	Delay(a); clear16seg();
	Q8=0; Q1=0; Q2=0; Q12=0; Q4=0; Q5=0; Q6=0; Q7=0;
	Delay(a); clear16seg();
	Q8=0; Q4=0; Q3=0; Q5=0; Q6=0; Q7=0;
	Delay(a); clear16seg();
	Q8=0; Q1=0; Q2=0; Q12=0; Q16=0; Q5=0; Q6=0; Q7=0;
	Delay(a); clear16seg();
	Q8=0; Q1=0; Q2=0; Q16=0; Q4=0; Q5=0; Q6=0; Q12=0;
	Delay(a); clear16seg();
	Q8=0; Q1=0; Q2=0; Q16=0; Q4=0; Q5=0; Q6=0; Q12=0;
	Delay(a); clear16seg(); Delay(2*a);
	Q8=0; Q7=0; Q1=0; Q2=0; Q5=0; Q6=0;
	Delay(a); clear16seg();
	Q8=0; Q7=0; Q1=0; Q2=0; Q5=0; Q6=0; Q3=0; Q4=0;
	Delay(a); clear16seg();
	Q8=0; Q7=0; Q9=0; Q15=0;
	Delay(a); clear16seg();
	Q8=0; Q7=0; Q1=0; Q2=0; Q5=0; Q6=0; Q16=0; Q12=0;
	Delay(a); clear16seg();
}
void okwrite()
{
	int a=400;
	clear16seg();
	Delay(2*a);
	Q14=0; Q10=0; Q2=0; Q3=0; Q4=0; Q5=0;
	Delay(a); clear16seg();
	Q14=0; Q10=0; Q11=0; Q13=0;
	Delay(a); clear16seg(); Delay(a);
}
int strcompare(char *ac, char *bc)
{
	int p=0;
	int i;
	for(i=0;i<QKOD;i++)
	{
	   if(ac[i]==bc[i]) p+=1;
	}
	return p;
}
void initINT0()
{
	INT0 = 0;
	IT0  = 1;
	EX0  = 1;
	EA   = 1;
}
void external0_isr(void) interrupt 0
{
		int comp;
		unsigned int i;
		guesscode();
		while(INT0==0)
		{  
			i=0;
			while(i<4)
			{
				a=read_key();
				write_key(a);
				if(a!=0)
				{
				 codein[i]=a;
		     i+=1;
				}	
			}
			comp=strcompare(codein,codesaved);
			if(comp==QKOD)
			{
				while(1) 
				{
					okwrite();
				}
			}
			else
			{
				while(1)
				{
					policeiscoming();
				}
		  }
		}
}
void main ()
{
	unsigned int i;
	initINT0();
	while(1)
	{
		i=0;
		while(i<4)
		{
		   b=read_key();
		   write_key(b);
		   if(b!=0)
		   {
				  codesaved[i]=b;
		      i+=1;
		   }	
		 }
		okwrite();
	}
}
