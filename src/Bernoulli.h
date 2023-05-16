#ifndef BERNOULLI_H 
#define BERNOULLI_H
#include"matriz.h"
#include"time.h"
#include"stdlib.h"

void CaminhamentoBernoulli(Matriz *M,signed short int *Ordem);
void EscolhaRandomica(short int *numeroColuna,short int *numeroLinha);
void MudancadePosicao(Matriz *M,int *Coluna,int *Linha,signed short int *Ordem);
void EvitandoParedes(Matriz *M,short int *numeroLinha,short int *numeroColuna,int *Coluna,int *Linha,short int *LinhaAtual,short int *ColunaAtual,signed short int *Ordem);

#endif