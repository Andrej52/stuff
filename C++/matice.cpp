#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // tisk  ,generovani  z toszahu   RNG a sum avg min max matice
    int MATa[3][3];
    float MATb[3][3],MATab[3][3];
    char volba;
    do
    {
       // print menu
    printf("a - 2 matice - generovani + tisk - rozsah 5-100\n");
	printf("b - 2 matice - tisk vedle sebe\n");
	printf("c - soucet 2 matic - tisk+vysledek\n");
    printf("d - priemer  matice - tisk+vysledek\n");
    printf("e - maxmin  matice - tisk+vysledek\n");
     printf("q - ende slusch konec \n");
    // zadanie volby
    printf("Zadej svoji volbu: ");
	scanf("%c", &volba);
    system("cls");	
    fflush(stdin);	

    if(volba == 'a')
    {
        for (int  i = 0; i < 3; i++)
        {
            for (int  j = 0; j < 3; j++)
            {
                // random generuje cisla 
                MATa[i][j]= 5+rand()%96;
                printf("%5d", MATa[i][j]);
                MATb[i][j]= MATa[i][j]/10.0;
            }
            printf("\n");
        }
        printf("\n");
        for (int i=0; i < 3; i++)
		{
			for (int j=0; j < 3; j++)
			{
				printf("%7.3f", MATb[i][j]);	
			}
				printf("\n");
			}
    }
    else if (volba == 'b')
    {                 // vypise maticu 
 					for (int i=0; i<3; i++)
					{
                        int j=0;
						printf("%5d", MATa[i][j++]);	
					}
					printf(" ");
					
					for (int j=0; j<3; j++)
					{
                        int i=0;
						printf("%7.3f", MATb[i++][j]);	
					}
					printf("\n");	
				
				for (int i=0; i<3; i++)
				{
					for (int j=0; j<3; j++)
					{
						printf("%5d", MATa[i][j]);	
					}
					printf(" ");
					
					for (int j=0; j<3; j++)
					{
						printf("%7.3f", MATb[i][j]);	
					}
					printf("\n");
				}
        
    }
    else if (volba == 'c')
    {
         for (int  i = 0; i < 3; i++)
        {
            for (int  j = 0; j < 3; j++)
            {
                // scituje jednotlive hodnoty matice na  indeox a zapisuje od novej matice
               MATab[i][j]= MATa[i][j] + MATb[i][j];
               printf("%3f ", MATab[i][j]);
               printf(" ");

            }
            printf("\n");
        }
    }
     else if (volba == 'd')
    {
        float resulta =0;
        float resultb =0;

        for (int  i = 0; i < 3; i++)
        {
             // print matA
            for (int  j = 0; j < 3; j++)
            {
                // scituje a uklada postupne cez iteracie hodnoty matice 
                resulta += MATa[i][j];

            }

            // print matB
            for (int  j = 0; j < 3; j++)
            {
                // scituje a uklada postupne cez iteracie hodnoty matice 
                resultb +=  MATb[i][j];
            }
        }
            printf("Vsledok mat A je %2f\n", resulta);
            printf("Vysledok mat B je :%2f\n", resultb);

            // ulozene hodnoty matice vydeli velkostou matice
            printf("Vsledok priemeru mat A je %2f\n", resulta/9);
            
            // ulozene hodnoty matice vydeli velkostou matice
            printf("Vysledok priemeru  mat B je :%2f\n", resultb/9);
    }
     else if (volba == 'e')
    {
        int max = MATa[3][3];
        int min = MATa[0][0];
        int h,l,g,u;
        
        for (int  i = 0; i < 3; i++)
        {
            // i  loopuje cez  riadky
            for (int  j = 0; j < 3; j++)
            {   
                // j loopuje cez  stlpce
                printf("%5d", MATa[i][j]);

                // loopuje adresy matice kym nenajde zadanu hodnotu max
				if (MATa[i][j] > max)
				{
                    // ulozi hodnotu do max a  ulozi jej indexy
					max = MATa[i][j];
                    h=i;
                    l=j;
				}
                else if (MATa[i][j] < min )
                {
                    // ulozi hodnotu do min a  ulozi jej indexy
                   	min = MATa[i][j];
                    g=i;
                    u=j; 
                }   
			}
            printf("\n");
        }
        
        printf("Maximalni hodnota v matici je %d\n", max);
		printf("Indexy maxima [%d][%d]\n", h, l);
        printf("Min hodnota v matici je %d\n", min);
		printf("Indexy min [%d][%d]\n", g, u);
        printf("\n");
    }
    else if (volba == 'q')
    {
        break;
    }
    } while (volba != 'q');
    
    return 0;
}

