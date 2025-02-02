#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>

int main (int argc, char *argv[])
{
	srand(time(NULL));
	char volba;
	int MATa[3][3];
	float MATb[3][3], MATab[3][3];
	int i, j, max, indexR, indexS;
	int pom = 0;
	
	do
	{
		//menu
		printf("a - 2 matice - generovani+tisk - rozsah 5-100\n");
		printf("b - 2 matice - tisk vedle sebe\n");
		printf("c - soucet 2 matic - tisk+vysledek\n");
		printf("d - tisk 1.matice + maximum a jeho indexy\n");
		printf("q - konec\n");
		//zadani volby
		printf("Zadej svoji volbu: ");
		scanf("%c", &volba);
		fflush(stdin);
		
		switch(volba)
		{
			case 'a': printf("Zadana volba je %c: 2 matice - generovani+tisk - rozsah 5-100\n",volba);
				pom = 1;
				for (i=0; i<3; i++)
				{
					for (j=0; j<3; j++)
					{
						MATa[i][j]= 5+rand()%96;	//rozsah 5-100
						printf("%5d", MATa[i][j]);
						MATb[i][j]= MATa[i][j]/10.0;							
					}
					printf("\n");
				}
				printf("\n");
				
				for (i=0; i<3; i++)
				{
					for (j=0; j<3; j++)
					{
						printf("%7.3f", MATb[i][j]);	
					}
					printf("\n");
				}
			
				printf("Pro pokracovani stiskni ENTER.\n");
				getchar();
				system("cls");			
				break;
					
			case 'b': printf("Zadana volba je %c\n",volba);
				if (pom == 1)
				{
					for (i=0; i<3; i++)
					{
						printf("%5d", MATa[i][j]);	
					}
					printf(" ");
					
					for (j=0; j<3; j++)
					{
						printf("%7.3f", MATb[i][j]);	
					}
					printf("\n");	
				
				for (i=0; i<3; i++)
				{
					for (j=0; j<3; j++)
					{
						printf("%5d", MATa[i][j]);	
					}
					printf(" ");
					
					for (j=0; j<3; j++)
					{
						printf("%7.3f", MATb[i][j]);	
					}
					printf("\n");
				}
				}else
				printf("Nejprve volba a.\n");
			
				printf("Pro pokracovani stiskni ENTER.\n");
				getchar();
				system("cls");				
				break;	
				
			case 'c': printf("Zadana volba je %c\n",volba);
				for (i=0; i<3; i++)
				{
					for (j=0; j<3; j++)
					{
						printf("%5d", MATa[i][j]);	
					}
					printf(" ");
					
					for (j=0; j<3; j++)
					{
						printf("%7.3f", MATb[i][j]);	
					}
					printf("\n");
				}
				
				for (i=0; i<3; i++)
				{
					for (j=0; j<3; j++)
					{	
						//printf("%9.3f", MATa[i][j]+MATb[i][j]);
						
						MATab[i][j]=MATa[i][j]+MATb[i][j];
						printf("%9.3f", MATab[i][j]);							
					}
					printf("\n");
				}
			
				printf("Pro pokracovani stiskni ENTER.\n");
				getchar();
				system("cls");				
				break;
					
			case 'd': printf("Zadana volba je %c\n",volba);
				max = MATa[0][0];
				for (i=0; i<3; i++)
				{
					for (j=0; j<3; j++)
					{
						printf("%5d", MATa[i][j]);
						if (MATa[i][j]>max)
						{
							max = MATa[i][j];
							indexR = i;
							indexS = j;
						}							
					}
					printf("\n");
				}
				printf("Maximalni hodnota v matici je %d\n", max);
				printf("Indexy maxima [%d][%d]\n", indexR, indexS);
				printf("Maximum je na %d.radku a %d.sloupci\n", indexR+1, indexS+1);
			
				printf("Pro pokracovani stiskni ENTER.\n");
				getchar();
				system("cls");				
				break;	
				
			case 'q': printf("Zadana volba je %c\n",volba);
			
				printf("Konec programu.\n");
				getchar();
				system("cls");
				break;	
				default: printf("Chyba. Zadej znovu\n",volba);	
		}
		
	}while(volba != 'q');

	system("cls");
	return 0;
}
