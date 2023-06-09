#ifndef __MATRIZ_H
#define __MATRIZ_H
#include<stdio.h>
#include<stdbool.h>
typedef struct ItemM
{
    char item;
    bool validacao;
}ItemM;

typedef struct Matriz
{
    ItemM **MAT;
}Matriz;

void Alocacao(Matriz *M,signed short int *Order);
void Preencher(FILE **File, Matriz *M, signed short int *Ordem);
void MostrandoMatriz(Matriz *M, signed short int *Ordem, int *Linha, int *Coluna);
void ResetandoValidacao(Matriz *M, signed short int *Ordem);
void Reset(Matriz *M, signed short int *Ordem,int *Linha,int *Coluna);

#endif