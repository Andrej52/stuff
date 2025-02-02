#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main (int argc, char *argv[])
{
	int volba, krok, nacteno, pocet, i;
	float x, stupne;
	setlocale(LC_ALL, "");
	
	do
	{
		//menu
		printf("1 - sin(x) a cos(x) pre 0-360 - krok 1\n");
		printf("2 - sin(x) a cos(x) pre 0-360 - pre zadany krok\n");
		printf("3 - sin(x) a cos(x) pre zadany uhol\n");
		printf("0 - koniec\n");
		
		//zadavanie volby
		printf("Zadaj svoju volbu: ");
		scanf("%d", &volba);
		fflush(stdin);
		//printf("Zadana volba je %d\n", volba);
	
		switch(volba)
		{
			case 1: printf("Volba = %d\n", volba);
			printf("x\t sin(x)\t cos(x)\n");
	
				for(i=0;i<51;i++)
				{
					x = i*M_PI/360.0;
					printf("%4d %f %f\n", i, sin(x), cos(x));
		
					if(i%20 == 0 && i != 0)
					{
						printf("Pre pokraèovanie stlaè ENTER.\n");
						getchar();
						system("cls");
						printf("x\t sin(x)\t cos(x)\n");
					}
				}
				printf("Pre pokraèovanie stlaè ENTER.\n");
			    getchar();
			    
				system("cls");
				break;
				
			case 2: printf("Volba = %d\n", volba);
			
				printf("Zadaj krok: ");
				do
				{
					nacteno = scanf("%d", &krok);
					fflush(stdin);
					if(nacteno !=1)
					printf("Chyba. Zadaj znovu. \n");
				}
				while(nacteno !=1);
				
				printf("x\t sin(x)\t cos(x)\n");
				pocet = 0;
				
				for(i=0;i<361;i=i+krok)
				{
					x = i*M_PI/360.0;
					printf("%4d %f %f\n", i, sin(x), cos(x));
		
					if(pocet == 20)
					{
						printf("Pre pokraèovanie stlaè ENTER.\n");
						getchar();
						system("cls");
						printf("x\t sin(x)\t cos(x)\n");
						pocet = 0;
					}
					if(i != 0)
					pocet++;
				}
				printf("Pre pokraèovanie stlaè ENTER.\n");
				getchar();
				
				system("cls");
				break;
				
			case 3: printf("Volba = %d\n", volba);
				
				printf("Zadaj stupne: ");
				do
				{
					nacteno = scanf("%f", &stupne);
					fflush(stdin);
					if(nacteno !=1)
					printf("Chyba. Zadaj znovu. \n");
				}
				while(nacteno !=1);
				
				printf("x\t sin(x)\t cos(x)\n");
				
				x = stupne*M_PI/360.0;
				printf("%3.0f %f %f\n", stupne, sin(x), cos(x));
				
				printf("Pre pokraèovanie stlaè ENTER.\n");
				getchar();
				
				system("cls");
				break;
				
			case 0: printf("Volba = %d\n", volba);
				printf("Koniec programu.\n");
				system("cls");
				break;
				
			default: printf("Chyba. Zadaj znovu.\n", volba);
		}
	}
	
	while(volba != 0);
	
	system("pause");
	return 0;
}
