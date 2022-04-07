#include "libraries.h"

void exibeCadastro(struct TCadastro cadastro){
  printf(CYN"\t\t\tO nome do proprietário do veículo é: %s\n", cadastro.dono);
  printf(CYN"\t\t\tO número do proprietário do veículo é: %d\n", cadastro.numero);
  printf(CYN"\t\t\tO tipo de veículo é: %s\n", cadastro.tipo);
  printf(CYN"\t\t\tO modelo de veículo é: %s\n", cadastro.modelo);
  printf(CYN"\t\t\tO ano do veículo é: %d\n", cadastro.ano);
  printf(CYN"\t\t\tA cor do veículo é: %s\n", cadastro.cor);
  printf(CYN"\t\t\tA placa do veículo é: %s\n", cadastro.placa);
  printf(CYN"\t\t\tA quilometragem atual do veículo é: %d\n\n", cadastro.quilometragem);
}
