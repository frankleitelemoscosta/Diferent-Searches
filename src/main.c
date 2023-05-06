#include<stdio.h>
#include"Lista.h"


int main()
{
 	Lista l;
	Item aux;

	FLVazia(&l);

	aux.x = 10;
  aux.y = 5;
	LInsert(&l, aux);
	aux.x = 20;
	LInsert(&l, aux);
	aux.y = 30;
	LInsert(&l, aux);

	LImprime(&l);

	aux.x = 2;
	LRemove(&l, aux);

	LImprime(&l);



return 0;
}
