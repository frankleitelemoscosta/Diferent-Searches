#include"DesviosCondicionais_e_escolhas_DFS.h"

void Selecionando(Matriz *M,signed short int *Ordem,int *Linha,int *Coluna,signed short int *escolha,Pilha *Ponteiro, Item *Ponteiro_Item){

    bool sinal = false;
    bool aux = false;

    do{
    //para decidir onde deve se caminhar
        if((*Linha + 1) < *Ordem)
        {
            if(M->MAT[*Linha + 1][*Coluna].item != '#' && M->MAT[*Linha + 1][*Coluna].validacao != true && sinal == false)
            {
                sinal = true;
                *escolha = 2;
            }
        }
        if((*Coluna - 1) > -1)
        {
            if(M->MAT[*Linha][*Coluna - 1].item != '#' && M->MAT[*Linha][*Coluna - 1].validacao != true && sinal == false)
            {
                sinal = true;
                *escolha = 4;
            }
        }
        if(((*Linha + 1) < *Ordem) && ((*Coluna + 1) < *Ordem))
        {
            if(M->MAT[*Linha + 1][*Coluna + 1].item != '#' && M->MAT[*Linha + 1][*Coluna + 1].validacao != true && sinal == false)
            {
                sinal = true;
                *escolha = 3;
            }
        }
        if(((*Coluna + 1) < *Ordem))
        {
            if(M->MAT[*Linha][*Coluna + 1].item != '#' && M->MAT[*Linha][*Coluna + 1].validacao != true && sinal == false)
            {
                sinal = true;
                *escolha = 1;
            }
        }
        if((*Linha - 1) > -1)
        {
            if(M->MAT[*Linha - 1][*Coluna].item != '#'&& M->MAT[*Linha - 1][*Coluna].validacao != true && sinal == false)
            {
                sinal = true;
                *escolha = 5;
            }
        }
        if(((*Linha - 1) > -1) && ((*Coluna - 1) > -1))
        {
            if(M->MAT[*Linha - 1][*Coluna - 1].item != '#'&& M->MAT[*Linha - 1][*Coluna - 1].validacao != true && sinal == false)
            {
                sinal = true;
                *escolha = 6;
            }
        }
        if(((*Linha - 1) > -1) && ((*Coluna + 1) > *Ordem))
        {
            if(M->MAT[*Linha - 1][*Coluna + 1].item != '#'&& M->MAT[*Linha - 1][*Coluna + 1].validacao != true && sinal == false)
            {
                sinal = true;
                *escolha = 7;
            }
        }
        if(((*Linha + 1) < *Ordem) && ((*Coluna - 1) > -1))
        {
            if(M->MAT[*Linha + 1][*Coluna - 1].item != '#'&& M->MAT[*Linha + 1][*Coluna - 1].validacao != true && sinal == false)
            {
                sinal = true;
                *escolha = 8;
            }
        }
    //fim da tomada de decisão
    aux = false;

    if(sinal == false)
    {
        Pop(Ponteiro,Ponteiro_Item);
        *Linha = Ponteiro->top->data.Linha ;
        *Coluna = Ponteiro->top->data.Coluna;
        aux = true;
    }
    }while(aux == true);
    

}

void DesviodeParedes(Matriz *M,signed short int *Ordem,int *Linha,int *Coluna,signed short int *escolha,Pilha *Ponteiro, Item *Ponteiro_Item){

    //verifica se não andara em uma parede ou em uma casa ja visitada
        if((*Linha + 1) < *Ordem && *escolha == 2)//abaixo
        {
            if(M->MAT[*Linha + 1][*Coluna].item == '#' || M->MAT[*Linha + 1][*Coluna].validacao == true)
            {
                Selecionando(M,Ordem,Linha,Coluna,escolha,Ponteiro,Ponteiro_Item);
            }
        }
        else if((*Coluna - 1) > -1 && *escolha == 4)//a esquerda
        {
            if(M->MAT[*Linha][*Coluna - 1].item == '#' || M->MAT[*Linha][*Coluna - 1].validacao == true)
            {
                Selecionando(M,Ordem,Linha,Coluna,escolha,Ponteiro,Ponteiro_Item);
            }
        }
        else if(((*Linha + 1) < *Ordem) && ((*Coluna + 1) < *Ordem) && *escolha == 3)//diagonal inferior direita
        {
            if(M->MAT[*Linha + 1][*Coluna + 1].item == '#' || M->MAT[*Linha + 1][*Coluna + 1].validacao == true)
            {
                Selecionando(M,Ordem,Linha,Coluna,escolha,Ponteiro,Ponteiro_Item);
            }
        }
        else if(((*Coluna + 1) < *Ordem) && *escolha == 1)//a direita
        {
            if(M->MAT[*Linha][*Coluna + 1].item == '#' || M->MAT[*Linha][*Coluna + 1].validacao == true)
            {
                Selecionando(M,Ordem,Linha,Coluna,escolha,Ponteiro,Ponteiro_Item);
            }
        }
        else if(((*Linha - 1) > -1) && *escolha == 5)//acima
        {
            if(M->MAT[*Linha - 1][*Coluna].item == '#' || M->MAT[*Linha - 1][*Coluna].validacao == true)
            {
                Selecionando(M,Ordem,Linha,Coluna,escolha,Ponteiro,Ponteiro_Item);
            }
        }
        else if(((*Linha - 1) > -1) && ((*Coluna - 1) > -1) && *escolha == 6)//diagonal superior esquerda
        {
            if(M->MAT[*Linha - 1][*Coluna - 1].item == '#' || M->MAT[*Linha - 1][*Coluna - 1].validacao == true)
            {
                Selecionando(M,Ordem,Linha,Coluna,escolha,Ponteiro,Ponteiro_Item);
            }
        }
        else if((((*Linha - 1) > -1) || ((*Coluna + 1) < *Ordem)) && *escolha == 7)//diagonal superior direita
        {
            if(M->MAT[*Linha - 1][*Coluna + 1].item == '#' || M->MAT[*Linha - 1][*Coluna + 1].validacao == true)
            {
                Selecionando(M,Ordem,Linha,Coluna,escolha,Ponteiro,Ponteiro_Item);
            }
        }
        else if((((*Linha + 1) < *Ordem) || ((*Coluna - 1) > -1)) && *escolha == 8)//diagonal inferior esquerda
        {
            if(M->MAT[*Linha + 1][*Coluna - 1].item == '#' || M->MAT[*Linha + 1][*Coluna - 1].validacao == true)
            {
                Selecionando(M,Ordem,Linha,Coluna,escolha,Ponteiro,Ponteiro_Item);
            }
        }
        if(((*Linha + 1) >= (*Ordem-1)) && *escolha == 2)
        {
            Selecionando(M,Ordem,Linha,Coluna,escolha,Ponteiro,Ponteiro_Item);
        }
        else if((*Coluna - 1) < 0 && *escolha == 4)
        {
            Selecionando(M,Ordem,Linha,Coluna,escolha,Ponteiro,Ponteiro_Item);
        }
        else if((((*Linha + 1) >= (*Ordem-1)) || ((*Coluna + 1) >= (*Ordem-1))) && *escolha == 3)
        {
            Selecionando(M,Ordem,Linha,Coluna,escolha,Ponteiro,Ponteiro_Item);
        }
        else if(((*Coluna + 1) >= (*Ordem-1)) && *escolha == 1)
        {
            Selecionando(M,Ordem,Linha,Coluna,escolha,Ponteiro,Ponteiro_Item);
        }
        else if(((*Linha - 1) < 0) && *escolha == 5)
        {                
                Selecionando(M,Ordem,Linha,Coluna,escolha,Ponteiro,Ponteiro_Item);
        }
        else if(((*Linha - 1) < 0) && ((*Coluna - 1) < 0) && *escolha == 6)
        {
                Selecionando(M,Ordem,Linha,Coluna,escolha,Ponteiro,Ponteiro_Item);
        }
        else if(((*Linha - 1) < 0) && ((*Coluna + 1) >= (*Ordem-1)) && *escolha == 7)
        {
                Selecionando(M,Ordem,Linha,Coluna,escolha,Ponteiro,Ponteiro_Item);
        }
        else if((((*Linha + 1) >= (*Ordem-1)) || ((*Coluna - 1) < 0)) && *escolha == 8)
        {
                Selecionando(M,Ordem,Linha,Coluna,escolha,Ponteiro,Ponteiro_Item);
        }

}