#include "../include/leituraDB.h"
#include "../include/menu.h"
#include "../include/relatorios.h"

// Dados armazenados na struct. Para acessar use d.nomeDaVariavel. Ex: d.origem => origem daquele mês
typedef struct {
  int origem;
  int carga;
  int mess;
  int ano;
  int tipo;
  float peso;
  float pesoLimpo;
  float percImpurezas;
  float percUmidade;
} Dados;

void leitura(int *mes, int *opcaoRelatorioQuantitativo, int *opcaoRelatorio) {
  Dados d;

  FILE *file;
  file = fopen("../data/database/bd.dat", "rb");

  if (file == NULL) {
    printf("O arquivo não foi aberto corretamente\n");
    return;
  }
  if (*opcaoRelatorio == 1) // Se o usuário escolher o tipo de relatório 1 => exibe o cabeçalho do relatório mensal
    cabecalhoRelatorioMes();

  else // Se o usuário escolher o tipo de relatório 2 => exibe o cabeçalho do relatório geral
    cabecalhoRelatorioGeral();

  // Loop que vai ler os dados em binário
  while (fread(&d, sizeof(Dados), 1, file) == 1) {
    if (*opcaoRelatorio == 1 && *opcaoRelatorioQuantitativo == 1) { // checa o tipo de relatório que o usuário quer
      if (*mes == d.mess)
        mesEspecifico(d.origem, d.carga, d.percUmidade); // Exibe o relatório de um mes específico

    } else if (*opcaoRelatorio == 1 && *opcaoRelatorioQuantitativo == 2)
      mesAMes(d.origem, d.carga, d.percUmidade); // Exibe o relatório de todos os meses

    else
      relatorioGeral(d.origem, d.peso, d.pesoLimpo, d.tipo, d.percUmidade); // Exibe o relatório geral
  }

  fclose(file);

  rodapeGeral();
}