#include<stdio.h>
#include"Lista.c"


int main()
{
  Lista L;
  Item aux;
  int num=0, x=0,y=0;
  while(num!=10){
    aux.x=x;
    aux.y=y;
    LInsert(&L,aux);
    num++;x++;y++;
  }
LImprime(&L);



return 0;
}
