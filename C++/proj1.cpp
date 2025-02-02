#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	int cislo1, cislo2, operace1, operace2;
	float podil;
	
	printf("Zadej prvni cele cislo:\n");
	scanf("%d",&cislo1);
	fflush(stdin);
	
	printf("Zadej druhe cele cislo:\n");
	scanf("%d",&cislo2);
	fflush(stdin);
	
	
	printf("Zadano: A = %d, B = %d\n",cislo1,cislo2);
	printf("Celociselne deleni:\t\t A/B = %d/%d = %d\n",cislo1,cislo2,cislo1/cislo2);
	printf("Zbytek po celociselnem deleni:\t A%%B = %d/%d = %d\n",cislo1,cislo2,cislo1%cislo2);
	printf("Realne deleni:\t\t\t A/B = %d.0/%d.0 = %f\n",cislo1,cislo2,(float)cislo1/(float)cislo2);
	printf("Realne deleni:\t\t\t A/B = %f/%f = %f\n",(float)cislo1,(float)cislo2,(float)cislo1/(float)cislo2);
	
	printf("Soucet cisel:\t\t\t A+B = %d+%d = %d\n",cislo1,cislo2,cislo1+cislo2);
	printf("Soucin cisel:\t\t\t A*B = %d*%d = %d\n",cislo1,cislo2,cislo1*cislo2);
	
	printf("Binarni soucet a soucin:\t A|B = %d|%d = %d; A&B = %d&%d = %d\n",cislo1,cislo2,cislo1|cislo2,cislo1,cislo2,cislo1&cislo2);
	printf("Logicky soucet a soucin:\t A||B = %d||%d = %d; A&&B = %d&&%d = %d\n",cislo1,cislo2,cislo1||cislo2,cislo1,cislo2,cislo1&&cislo2);
	
	podil = (float)cislo1/(float)cislo2;
	printf("Realne deleni:\t\t\t A/B = %f/%f = %f\n",(float)cislo1,(float)cislo2,podil);
	printf("Cela cast realneho deleni:\t  %d\n",(int)podil);
	printf("Zaokruhleny vysledek deleni:\t  %.0f\n",podil);
	printf("Desetinna cast podilu:\t\t  %.3f\n",podil-(int)podil);
	
	operace1 = cislo1+cislo2;
	printf("Soucet cisel:\t\t\t A+B = %d+%d = %d\n",cislo1,cislo2,operace1);

	operace2 = cislo1*cislo2;
	printf("Soucin cisel:\t\t\t A*B = %d*%d = %d\n",cislo1,cislo2,operace2);
	
	//printf("1. zadene cele cislo: %d\n",cislo1);
	//printf("2. zadene cele cislo: %d\n",cislo2);
	
	printf("Pro ukonceni stiskni ENTER.\n");
	getchar();
	return 0;
}