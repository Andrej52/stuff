#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 5;
    int b= 2;
    float c = a/b;// vypocita klasicke   a/b kde je to jako int ale prida  tomu desatiny
    float d = (float)a / (float) b;  // pretypova ne A a B z INT na Float 
    printf("zakladna  hodnota A je %d \n" , a);
    printf("zakladna  hodnota B je %d \n" , b);
    printf("A/B: %d \n" , a/b);
    printf("zostatok  A/B je :%d \n" , a%b);
    printf("float C: %f \n" , c);
    printf("float D: %f \n" , d); 

    //printf("  A/B je :%d \n" ,a%%b);  toto mi dava debugger jako vadne

    return 0;

}