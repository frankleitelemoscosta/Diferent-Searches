#include "matriz.h"
#include<stdio.h>
#include<stdlib.h>

void Alocacao(Matriz *M,signed short int *Ordem){

    //alocando as linhas
        M->MAT = (ItemM**)malloc(*Ordem * sizeof(ItemM*));

    //alocando memória paras as colunas
        for(int i = 0 ; i < *Ordem ; i++)
        {
            M->MAT[i] = (ItemM*)malloc(*Ordem * sizeof(ItemM));
        }
}

void Preencher(FILE **File, Matriz *M, signed short int *Ordem){
    	
    //acessa o arquivo de entrada e lê cada caracter contido nele, até que chegue ao limite de linhas e colunas
        for (int i = 0; i < *Ordem; i++)
		{
			for (int j = 0; j < *Ordem; j++)
			{
				fscanf(*File,"%s",&M->MAT[i][j].item);
                M->MAT[i][j].validacao = false;
			}
		}
    //fim
        fclose(*File);
}

void MostrandoMatriz(Matriz *M, signed short int *Ordem,int *Linha,int *Coluna)
{
    //mostra elemento por elemento da matriz
        for (int i = 0; i < *Ordem; i++)
            {
                for (int j = 0; j < *Ordem; j++)
                {
                    if( i != *Linha || j != *Coluna)
                    printf("[%c] ",M->MAT[i][j].item);
                    else
                    printf("[@] ");
                }
                printf("\n");
        }
    //fim 
}

//fim do código