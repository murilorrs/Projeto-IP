#include "../include/leituraDB.h"
#include "../include/leitura_arquivos.h"

void limpaTerminal();

int main() {
  int opcaoGeral = 0, sair = 0, opcaoSaida = 0, numero1controle, mesEscolhido, opcaoRelatorio, opcaoRelatorioQuantitativo;
  char entradaUserMenu[100], entradaUserAnalisar[100], entradaUserRelatorio[100], entradaUserRquant[100], entradaUserMes[100], entradaUserSaida[100];
  int converteMenu, converteAnalisar, converteRelatorio, converteRquant, converteMes, converteSaida;
  sair = 0;
  while (sair == 0) {

    while (1) {
      printf("\n-----------------Cooperativa Agricola-----------------\n1 - Analisar\n2 - Gerar relatorio\n3 - Sair\n");

      fgets(entradaUserMenu, sizeof(entradaUserMenu), stdin); // numero1controle
      fflush(stdin);
      entradaUserMenu[strcspn(entradaUserMenu, "\n")] = '\0';

      converteMenu = sscanf(entradaUserMenu, "%d", &numero1controle);

      if (converteMenu == 1) { // verifica se deu para converter a entrada do usuário em número
        if (numero1controle >= 1 && numero1controle <= 3) {
          break;
        } else {
          printf("Entrada invalida. Insira um valor valido (1 a 3).\n");
        }
      } else {
        printf("Entrada invalida. Insira um valor numerico 1.\n");
      }
    }
    opcaoGeral = numero1controle;

    if (opcaoGeral == 1) {
      limpaTerminal();
      carregamento();

    } else if (opcaoGeral == 2) {

      while (1) {
        limpaTerminal();
        printf("\nEscolha uma opcao de relatorio:\n");
        printf("1: Quantitativo mensal\n");
        printf("2: Geral\n=> ");

        fgets(entradaUserAnalisar, sizeof(entradaUserAnalisar), stdin);
        fflush(stdin);
        entradaUserAnalisar[strcspn(entradaUserAnalisar, "\n")] = '\0';
        converteAnalisar = sscanf(entradaUserAnalisar, "%d", &opcaoRelatorio);
        if (converteAnalisar == 1) {
          if (opcaoRelatorio >= 1 && opcaoRelatorio <= 2) {
            break;
          } else {
            printf("Entrada invalida. Insira um valor valido (1 a 2).\n");
          }
        } else {
          printf("Entrada invalida. Insira um valor numerico 2. \n");
        }
      }
      if (opcaoRelatorio == 1) {

        while (1) {
          printf("\nEscolha o modelo de relatorio quantitativo:\n");
          printf("1: Mes especifico\n");
          printf("2: Mes a mes\n=> ");
          fgets(entradaUserRquant, sizeof(entradaUserRquant), stdin);
          fflush(stdin);
          entradaUserRquant[strcspn(entradaUserRquant, "\n")] = '\0';
          converteRquant = sscanf(entradaUserRquant, "%d", &opcaoRelatorioQuantitativo);
          if (converteRquant == 1) {
            if (opcaoRelatorioQuantitativo >= 1 && opcaoRelatorioQuantitativo <= 2) {
              break;
            } else {
              printf("Entrada invalida. Insira um valor valido (1 a 2).\n");
            }
          } else {
            printf("Entrada invalida. Insira um valor numerico 3.\n");
          }
        }

        if (opcaoRelatorioQuantitativo == 1) {
          limpaTerminal();

          while (1) {
            printf("\nQual o mes desejado?\n");
            printf("1: Janeiro\n");
            printf("2: Fevereiro\n");
            printf("3: Marco\n");
            printf("4: Abril\n");
            printf("5: Maio\n");
            printf("6: junho\n");
            printf("7: julho\n");
            printf("8: Agosto\n");
            printf("9: Setembro\n");
            printf("10: Outubro\n");
            printf("11: Novembro\n");
            printf("12: Dezembro\n=> ");
            fgets(entradaUserMes, sizeof(entradaUserMes), stdin);
            fflush(stdin);
            entradaUserMes[strcspn(entradaUserMes, "\n")] = '\0';
            converteMes = sscanf(entradaUserMes, "%d", &mesEscolhido);
            if (converteMes == 1) {
              if (mesEscolhido >= 1 && mesEscolhido <= 12) {
                break;
              } else {
                limpaTerminal();
                printf("!!! Entrada invalida. Insira um valor valido (1 a 12). !!!\n");
              }
            } else {
              limpaTerminal();
              printf("!!! Entrada invalida. Insira um valor numerico 4. !!!\n");
            }
          }

          limpaTerminal();
          leitura(&mesEscolhido, &opcaoRelatorioQuantitativo, &opcaoRelatorio);
        }

        if (opcaoRelatorioQuantitativo == 2) {
          limpaTerminal();
          leitura(&mesEscolhido, &opcaoRelatorioQuantitativo, &opcaoRelatorio);
        }
      } else {
        limpaTerminal();
        leitura(&mesEscolhido, &opcaoRelatorioQuantitativo, &opcaoRelatorio);
      }

    } else if (opcaoGeral == 3) {

      while (1) {
        printf("\nVoce tem certeza que deseja sair?\n1 - Sim\n2 - Nao\nopcao escolhida:");
        fgets(entradaUserSaida, sizeof(entradaUserSaida), stdin);
        fflush(stdin);
        entradaUserSaida[strcspn(entradaUserSaida, "\n")] = '\0';
        converteSaida = sscanf(entradaUserSaida, "%d", &opcaoSaida);
        if (converteSaida == 1) {
          if (opcaoSaida >= 1 && opcaoSaida <= 2) {
            if (opcaoSaida == 1) {
              sair = 1;
              break;
            } else if (opcaoSaida == 2) {
              break;
            }
          } else {
            printf("Entrada invalida. Insira um valor dentro do intervalo (1 a 2).\n");
          }
        } else {
          printf("Entrda invalida. Insira um valor numerico 5.\n");
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
}
