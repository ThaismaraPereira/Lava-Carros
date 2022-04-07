#include "libraries.h"

jmp_buf RETORNO;
void flush_in();
struct TCadastro cadastraCarro();
void exibeCadastro();

void menu(){
    struct TCadastro *filaPrincipal;
    struct TCadastro *filaReserva;
    int escolha, capacidade, retorno,contP=0, contR=0;

    printf(NEGRITO BLU"==========================================================================================================\n"RESET);
    printf(YEL NEGRITO "\t\tBem vindo ao LavaGest!\n\n" RESET);
    printf(CYN ITALICO "\t\tEste sotware irá lhe auxiliar na gestão de seu lavarcar\n");
    printf("\t\tPreparamos tudo para facilitar sua organização, basta seguir alguns passos simples...\n");
    printf("\t\tPreparado(a)? Então vamos nessa!\n\n" RESET);
    printf(NEGRITO BLU"==========================================================================================================\n\n"RESET);
    printf(YEL "\t\tAdicione uma capacidade de lavagem:\n\t\t" RESET);
    scanf("%d", &capacidade);
    printf(BLU NEGRITO "==========================================================================================================\n\n"RESET);
    if(capacidade<=0){
        system("clear");
        printf(RED NEGRITO "\n\nA capacidade deve ser maior que 0!!!\n\n" RESET);
    }

    filaPrincipal = malloc(capacidade*sizeof(struct TCadastro));
    filaReserva = malloc(3*sizeof(struct TCadastro));

    retorno = setjmp(RETORNO);

    printf(YEL NEGRITO"\n\t\tEscolha uma das opções a seguir:\n\n"RESET);
    printf(NEGRITO"\t\t\t[1]-> "RESET CYN"Cadastrar novo veículo\n"RESET);
    printf(NEGRITO"\t\t\t[2]-> "RESET LGREEN"Concluir lavagem\n"RESET);
    printf(NEGRITO"\t\t\t[3]-> "RESET CYN"Verificar fila\n"RESET);
    printf(NEGRITO"\t\t\t[4]-> "RESET LGREEN"Verificar fila de espera\n"RESET);
    printf(NEGRITO"\t\t\t[5]-> "RESET CYN"Encerrar programa\n\t\t\t"RESET);
    fflush(stdin);
    scanf("%d", &escolha);
    printf(NEGRITO BLU"==========================================================================================================\n\n"RESET);

    switch(escolha){
        case 1:
            system("clear");
              flush_in();
              if (contP<capacidade){
              filaPrincipal[contP++] = cadastraCarro(filaPrincipal);
              printf(RED"Veículo cadastrado na fila principal com sucesso!\n"RESET);
              getchar();
              system("clear");
              longjmp(RETORNO, 1);}else 
                if((capacidade>=contP)&&(contR<3)){
                  filaReserva[contR++] = cadastraCarro(filaReserva);
                  printf(RED"Veículo cadastrado na fila de reserva com sucesso!\n"RESET);
                  getchar();
                  system("clear");
                  longjmp(RETORNO, 1);
                }    else{
                    printf(RED NEGRITO"Capacidade máxima atingida!\n");
                    longjmp(RETORNO, 1);
          }                  
        break;
        case 2:
            system("clear");
            printf(RED"Concluindo lavagem...\n\n"RESET);
            if(contP-->0){
              for(int i=0; i<contP; i++){
                filaPrincipal[i]=filaPrincipal[i+1];
              }
              
                if(contR>0){
                  filaPrincipal[contP++]=filaReserva[0];
                  for(int y=0; y<contR; y++){
                    filaReserva[y] = filaReserva[y+1];
                    }
                  contR--;
                  }
              printf(YEL"Um veículo foi lavado\n"RESET);
              } else{
              printf(RED"Não há carros para serem lavados. Favor adicionar carros a fila\n"RESET);
            }
            longjmp(RETORNO, 2); 
        break;
        case 3:
            system("clear");
            printf(RED"Verificando fila...\n\n"RESET);
            int cont = 0;
            if(contP<=0){printf(RED"A fila principal está vazia!\n\n"RESET);
            }else{
              for(cont = 0; contP>cont; cont++){
                printf(YEL"\t\t\tEsse é o veículo Nº %d da fila principal\n" RESET, cont+1);
                exibeCadastro(filaPrincipal[cont]);
              }
            }
            longjmp(RETORNO, 3); 
        break;
        case 4:
            system("clear");
            printf(RED"Verificando fila de espera...\n\n");
            int aux = 0;
            if(contR<=0){printf(RED"A fila reserva está vazia!\n\n"RESET);
            }else{
              for(aux = 0; contR>aux; aux++){
                printf(YEL"\t\t\tEsse é o veículo Nº %d da fila reserva\n" RESET, aux+1);
                exibeCadastro(filaReserva[aux]);
              }
            } 
            longjmp(RETORNO, 4); 
        break;
        case 5:
            system("clear");
            printf(RED NEGRITO"Encerrando o programa...\n" RESET);
            system("pause");
            exit(0);
        break;
        default:
            system("clear");
            printf(RED NEGRITO"Opção Inválida!\n\n\n" RESET);
            longjmp(RETORNO, 5); 
    }
} 
