#include "../include/leitura_arquivos.h"

void limpaTerminal();

int main() {
  int opcaoGeral, sair, opcaoSaida, numero1controle;

  sair = 0;
  while (sair == 0) {

    while (1) {
      printf("-----------------Cooperativa Agricola-----------------\n1 - Analisar\n2 - Gerar relatorio\n3 - Sair\n");

      scanf("%d", &numero1controle);
      if (numero1controle >= 1 && numero1controle <= 4) {
        break;
      } else {
        printf("Entrada invalida. Insira um valor valido.\n");
        while (getchar() != '\n')
          ;
      }
    }
    opcaoGeral = numero1controle;

    if (opcaoGeral == 1) {
      limpaTerminal();
      carregamento();

    } else if (opcaoGeral == 2) {
      limpaTerminal();
    } else if (opcaoGeral == 3) {
      printf("\nVoce tem certeza que deseja sair?\n1 - Sim\n2 - Nao\nopcao escolhida:");

      while (1) {
        scanf("%d", &opcaoSaida);

        if (opcaoSaida == 1) {
          sair = 1;
          break;
        } else if (opcaoSaida == 2) {
          break;
        } else {
          printf("Entrada invalida. Insira um valor dentro do intervalo.\n");
          while (getchar() != '\n')
            ;
        }
      }
    }
  }
}

void limpaTerminal() {

  printf("\033[H");
  printf("\033[J");
  for (int i = 0; i < 100; i++) {
    printf("\n");
  }

  printf("\033[H");
  fflush(stdout);
}