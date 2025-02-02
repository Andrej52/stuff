#include <stdio.h>
#include <string.h>

struct t_datum
{
 unsigned short den;
 unsigned short mesic;
 unsigned short rok;
};

void naplnDatum(struct t_datum *datum) { datum->den = 9; datum->mesic = 11; datum->rok =
2018; }


int main()
{

}