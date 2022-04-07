#include "libraries.h"

void flush_in();

struct TCadastro cadastraCarro(){
    struct TCadastro cadastro;
    printf(NEGRITO BLU"==========================================================================================================\n"RESET);
    printf(NEGRITO YEL"\t\t Bem vindo ao cadastro de veículos!\n"RESET);
    printf(CYN "\t\t Aqui você irá adicionar novos carros a fila para serem lavados posteriormente!\n" RESET);
    printf(NEGRITO BLU"==========================================================================================================\n\n"RESET);
    int op, cont=0;
            printf(YEL"\t\t\tInforme o nome do proprietário do veículo: \n"RESET);
            fgets(cadastro.dono, 20, stdin);
            cadastro.dono[strcspn(cadastro.dono, "\n")] = 0;
            printf(YEL"\t\t\tInsira o número do dono do veículo:\n"RESET);
            scanf("%d", &cadastro.numero);
            flush_in();
            printf(YEL"\t\t\tInforme o tipo de veículo (carro/moto):\n"RESET);
            fgets(cadastro.tipo, 10, stdin);
            cadastro.tipo[strcspn(cadastro.tipo, "\n")] = 0;
            printf(YEL"\t\t\tDigite o modelo do veículo:\n"RESET);
            fgets(cadastro.modelo, 10, stdin);
            cadastro.modelo[strcspn(cadastro.modelo, "\n")] = 0;
            printf(YEL"\t\t\tQual é o ano do veículo?\n"RESET);
            scanf("%d", &cadastro.ano);
            flush_in();
            printf(YEL"\t\t\tQual é a cor do veículo?\n"RESET);
            fgets(cadastro.cor, 10, stdin);
            cadastro.cor[strcspn(cadastro.cor, "\n")] = 0;
            printf(YEL"\t\t\tInforme a placa do veículo:\n"RESET);
            fgets(cadastro.placa, 10, stdin);
            cadastro.placa[strcspn(cadastro.placa, "\n")] = 0;
            printf(YEL"\t\t\tDigite a quilometragem atual do veículo: \n" RESET);
            scanf("%d", &cadastro.quilometragem);
            flush_in();
            return(cadastro);    
}
