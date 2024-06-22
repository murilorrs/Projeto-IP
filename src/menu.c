#include <stdio.h>
#include "../include/leitura_arquivos.h"

int main()
{
    int opcaoGeral, sair, opcaoSaida, numero1controle;

    sair = 0;
    while (sair == 0)
    {

        while (1)
        {
            printf("-----------------Cooperativa Agricola-----------------\n1 - Analisar\n2 - Arquivar\n3 - Gerar relatorio\n4 - Sair\nopcao escolhida: ");

            scanf("%d", &numero1controle);
            if (numero1controle >= 1 && numero1controle <= 4)
            {
                break;
            }
            else
            {
                printf("Entrada invalida. Insira um valor valido.\n");
                while (getchar() != '\n')
                    ;
            }
        }
        opcaoGeral = numero1controle;

        if (opcaoGeral == 1)
        {
            printf("Escolheu a opcao 1\n");
            carregamento();
        }
        else if (opcaoGeral == 2)
        {
            printf("Escolheu a opcao 2\n");
            // gerar relatórios quantitativos função externa que vai arquivar
        }
        else if (opcaoGeral == 3)
        {
            printf("Escolheu a opcao 3\n");
            // gerar relatórios qualitativos, mas antes deve ser analisado se será de um mês específio ou de mês a mês
        }
        else if (opcaoGeral == 4)
        {
            printf("\nVoce tem certeza que deseja sair?\n1 - Sim\n2 - Nao\nopcao escolhida:");
            while (1)
            {
                scanf("%d", &opcaoSaida);

                if (opcaoSaida == 1)
                {
                    sair = 1;
                    break;
                }
                else if (opcaoSaida == 2)
                {
                    break;
                }
                else
                {
                    printf("Entrada invalida. Insira um valor dentro do intervalo.\n");
                    while (getchar() != '\n')
                        ;
                }
            }
        }
    }
}
