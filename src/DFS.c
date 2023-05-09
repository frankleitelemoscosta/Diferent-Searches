#include"PilhaDFSeBFS.h"


void CaminhamentoDFS(Matriz *M/*,signed short int *Ordem*/){
    
    //variaveis de ambiente
        signed short int escolha = 1;
        int Linha = 0;
        int Coluna = 0;
    //fim das variaveis

    //aqui se faz a escolha para onde andar
        (escolha == 1)?(Coluna = Coluna + 1):((escolha == 2)?(Linha = Linha + 1):(Linha = Linha + 1, Coluna = Coluna + 1));
    

    M->MAT[Linha][Coluna]
}