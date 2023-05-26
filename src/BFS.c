#include"Fila.h"

void CaminhamentoBFS(Matriz *M,signed short int *Ordem,Fila *F)
{

    ItemF dado;

    dado.Linha = 0;
    dado.Coluna = 0;

    for(int i = 0 ; i < *Ordem ; i++)
    {
        for(int j = 0 ; j < *Ordem ; j++)
        {
            M->MAT[i][j].validacao = false;
        }
    }

    FFVazia(F);

    //Para marcar a posição inicial como ja visitada e enfilheiras para que da próxima vez que for utilizada a fila encontre os vizinhos dessa casa 
        M->MAT[dado.Linha][dado.Coluna].validacao = true;
        Enfileira(F,dado);

    while(!isVazia(F))
    {
        Desenfileira(F,&dado);

        if(M->MAT[dado.Linha][dado.Coluna].item == '?')
        {
            printf("Foi encontrado a interrogação (linha,Coluna) (%d,%d)\n",dado.Linha,dado.Coluna);
            return;
        }
        else if(M->MAT[dado.Linha][dado.Coluna].item == '*')
        {
            M->MAT[dado.Linha][dado.Coluna].item = '1';
            while(!isVazia(F))
            {
                Desenfileira(F,&dado);
            }
            for(int i = 0 ; i < *Ordem ; i++)
            {
                for(int j = 0 ; j < *Ordem ; j++)
                {
                    M->MAT[i][j].validacao = false;
                }
            }
            FFVazia(F);
            dado.Linha = 0;
            dado.Coluna = 0;
            M->MAT[dado.Linha][dado.Coluna].validacao = true;
            Enfileira(F,dado);
        }

        //criando um pequeno vetor com as possibilidades de caminhamento    
            ItemF vizinhos[] = {
                {dado.Linha + 1, dado.Coluna},   // Vizinho abaixo
                {dado.Linha, dado.Coluna + 1},   // Vizinho esquerda
                {dado.Linha + 1, dado.Coluna + 1},
            };

            for(int i = 0 ; i < 3 ; i++)
            {
                int linha = vizinhos[i].Linha;
                int coluna = vizinhos[i].Coluna;

                /*for(int i = 0 ; i < *Ordem ; i++)
                {
                    for(int j = 0 ; j < *Ordem ; j++)
                    {
                        if(i != linha || j != coluna){
                        printf(" %c",M->MAT[i][j].item);
                        }
                        else{
                            printf(" @");
                        }
                        
                    }
                    printf("\n");
                }
                printf("\n");

                getchar();
                getchar();
                */    
                if(linha >= 0 && linha < *Ordem && coluna >= 0 && coluna < *Ordem && M->MAT[linha][coluna].item != '#' && M->MAT[linha][coluna].validacao != true)
                {
                    M->MAT[linha][coluna].validacao = true;
                    Enfileira(F,vizinhos[i]);
                }
            }
    }

    //para reiniciar todas as variaveis de validação
        ResetandoValidacao(M,Ordem);

}