#include"PilhaDFS.h"
#include"matriz.h"//temporario até terminar os testes, assim que acabar deve ser apagado
#include<stdbool.h>


void Selecionando(Matriz *M,signed short int *Ordem,int *Linha,int *Coluna,signed short int *escolha,Pilha *Ponteiro, Item *Ponteiro_Item){

    bool sinal = false;

    //para decidir onde deve se caminhar
        if((*Linha + 1) < *Ordem)
        {
            (M->MAT[*Linha + 1][*Coluna].item != '#' && M->MAT[*Linha + 1][*Coluna].validacao != true && sinal == false)?(*escolha = 2,sinal = true):(printf("\n"));
        }
        if((*Coluna - 1) > -1)
        {
            (M->MAT[*Linha][*Coluna - 1].item != '#' && M->MAT[*Linha][*Coluna - 1].validacao != true && sinal == false)?(*escolha = 4,sinal = true):(printf("\n"));
        }
        if(((*Linha + 1) < *Ordem) && ((*Coluna + 1) < *Ordem))
        {
            (M->MAT[*Linha + 1][*Coluna + 1].item != '#' && M->MAT[*Linha + 1][*Coluna + 1].validacao != true && sinal == false)?(*escolha = 3,sinal = true):(printf("\n"));
        }
        if(((*Coluna + 1) < *Ordem))
        {
            (M->MAT[*Linha][*Coluna + 1].item != '#' && M->MAT[*Linha][*Coluna + 1].validacao != true && sinal == false)?(*escolha = 1,sinal = true):(printf("\n"));
        }
        if((*Linha - 1) > -1)
        {
            (M->MAT[*Linha - 1][*Coluna].item != '#' && M->MAT[*Linha - 1][*Coluna].validacao != true && sinal == false)?(*escolha = 5,sinal = true):(printf("\n"));
        }
    //fim da tomada de decisão

    if(sinal == true)
    {
        printf("Entrou");
        Pop(Ponteiro,Ponteiro_Item);
        *Linha = Ponteiro->top->data.Linha ;
        *Coluna = Ponteiro->top->data.Coluna;
    }
    

}

void Reset(){

}

void CaminhamentoDFS(Matriz *M,signed short int *Ordem){
    
    //variaveis de ambiente
        signed short int escolha = 1;
        int Linha = 0;
        int Coluna = 0;
        bool parada = true;
        Pilha Ponteiro;
        Item Ponteiro_Item;
    //fim das variaveis

    FPVazia(&Ponteiro);

    while(parada == true){

        M->MAT[Linha][Coluna].validacao = true;

    //se for encontrado o interrogação o loop é quebrado com o break
        (M->MAT[Linha][Coluna].item == '?')?(exit(-1)):(parada = true);

        if((Linha + 1) < *Ordem && escolha == 2)
        {
            (M->MAT[Linha + 1][Coluna].item == '#')?(Selecionando(M,Ordem,&Linha,&Coluna,&escolha,&Ponteiro,&Ponteiro_Item)):(printf("\n"));
        }
        else if(escolha == 2){
            Selecionando(M,Ordem,&Linha,&Coluna,&escolha,&Ponteiro,&Ponteiro_Item);
        }
        if((Coluna - 1) > -1 && escolha == 4)
        {
            (M->MAT[Linha][Coluna - 1].item == '#')?(Selecionando(M,Ordem,&Linha,&Coluna,&escolha,&Ponteiro,&Ponteiro_Item)):(printf("\n"));
        }
        else if(escolha == 4){
            Selecionando(M,Ordem,&Linha,&Coluna,&escolha,&Ponteiro,&Ponteiro_Item);
        }
        if(((Linha + 1) < *Ordem) && ((Coluna + 1) < *Ordem) && escolha == 3)
        {
            (M->MAT[Linha + 1][Coluna + 1].item == '#')?(Selecionando(M,Ordem,&Linha,&Coluna,&escolha,&Ponteiro,&Ponteiro_Item)):(printf("\n"));
        }
        else if(escolha == 3){
            Selecionando(M,Ordem,&Linha,&Coluna,&escolha,&Ponteiro,&Ponteiro_Item);
        }
        if(((Coluna + 1) < *Ordem) && escolha == 1)
        {
            (M->MAT[Linha][Coluna + 1].item == '#')?(Selecionando(M,Ordem,&Linha,&Coluna,&escolha,&Ponteiro,&Ponteiro_Item)):(printf("\n"));
        }
        else if(escolha == 1){
            Selecionando(M,Ordem,&Linha,&Coluna,&escolha,&Ponteiro,&Ponteiro_Item);
        }
        if((Linha - 1) > -1 && escolha == 5)
        {
            (M->MAT[Linha - 1][Coluna].item == '#')?(Selecionando(M,Ordem,&Linha,&Coluna,&escolha,&Ponteiro,&Ponteiro_Item)):(printf("\n"));
        }
        else if(escolha == 5){
            Selecionando(M,Ordem,&Linha,&Coluna,&escolha,&Ponteiro,&Ponteiro_Item);
        }

    //aqui se faz a escolha para onde andar
        (escolha == 1)?(Coluna = Coluna + 1):((escolha == 2)?(Linha = Linha + 1):((escolha == 3)?(Linha = Linha + 1, Coluna = Coluna + 1):((escolha == 4)?(Coluna = Coluna - 1):((escolha == 5)?(Linha = Linha - 1):(printf(" "))
        ))));

        Ponteiro_Item.Linha = Linha;
        Ponteiro_Item.Coluna = Coluna;

        Push(&Ponteiro,Ponteiro_Item);

        PImprime(&Ponteiro);

        MostrandoMatriz(M,Ordem,&Linha,&Coluna);//apenas para teste, assim que acabar deve ser apagado

        getchar();//apenas para teste, assim que acabar deve ser apagado
        getchar();//apenas para teste, assim que acabar deve ser apagado

        (M->MAT[Linha][Coluna].item == '*')?(Reset()):(printf("\n"));
    }

    
}