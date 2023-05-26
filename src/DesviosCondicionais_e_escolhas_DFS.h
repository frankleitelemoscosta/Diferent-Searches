#ifndef __DESVIOSCONDICIONAIS_E_ESCOLHAS_DFS_H
#define __DESVIOSCONDICIONAIS_E_ESCOLHAS_DFS_H
#include"matriz.h"
#include"PilhaDFS.h"


void Selecionando(Matriz *M,signed short int *Ordem,int *Linha,int *Coluna,signed short int *escolha,Pilha *Ponteiro, Item *Ponteiro_Item );
void DesviodeParedes(Matriz *M,signed short int *Ordem,int *Linha,int *Coluna,signed short int *escolha,Pilha *Ponteiro, Item *Ponteiro_Item);


#endif