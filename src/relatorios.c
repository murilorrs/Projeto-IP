// IMPORTANTE: Todas as leituras já estão sendo feitas corretamente e as funções abaixo ja estão sendo chamadas no lugar correto, dentro do arquivo src/leituraDB.
// Resta implementar a lógica para a impressao dos relatórios no terminal.
#include "../include/relatorios.h"

// *********************RELATORIOS MENSAIS:*************************

void cabecalhoRelatorioMes() {
  limpaTerminal();
  printf("\nCOOPERATIVA AGRICOLA GRAO_DO_VALE V1.0\n");
  printf("ANO: 2024\n");
  printf("--------------------------------------------------------------------------\n");

  printf("Origem    Carga(s)    GU Faixa 1    GU Faixa 2    GU Faixa 3    GU Extra\n");
  printf("-------+------------+-------------+-------------+--------------+-----"
         "-----\n");
}

void mesEspecifico(int origem, int cargas, float gUmidade) {
  printf("%03d        %03d", origem, cargas);

  if (gUmidade >= 0 && gUmidade <= 8.5)
    printf("            X\n\n");
  else if (gUmidade >= 8.6 && gUmidade <= 15)
    printf("                          X\n\n");
  else if (gUmidade >= 15 && gUmidade <= 25)
    printf("                                       X\n\n");
  else
    printf("                                                     X\n\n");
}

void mesAMes(int origem, int cargas, float gUmidade) {
  // logica para o relatório de todos os meses
  // Deve exibir todos os dados do banco de dados, seguindo o modelo de relatório mensal que está no PDF
  printf("cheguei ate aqui: mes a mes\n");
}

// ********************RELATORIO GERAL:*******************

void cabecalhoRelatorioGeral() {
  // Lógica pro cabeçalho do relatório geral segundo o modelo de relatório geral que está no PDF
  printf("cheguei ate aqui: geral cabeçalho\n\n");
}

void relatorioGeral(int origem, float pesoTotal, float pesoLimpo, int tipo, float gUmidade) {
  // Lógica pro relatório geral
  // Deve exibir todos os dados que estão no DB, seguindo o modelo de relatório geral que está no PDF
  printf("cheguei ate aqui: geral\n");
}

// ********************RELATORIO DE CARREGAMENTO(feito)****************************

void relatorioDeCarregamento(int protocolo, int quantidadeDeAmostras, int mes, int ano, float percentualUmidade, float pesoLimpo, int transgenico, int quantidadeA, int quantidadeB, int quantidadeC,
                             int faixaA[], int faixaB[], int faixaC[], float percentualImpureza) {

  printf("%f\n", percentualImpureza);
  printf("\nCOOPERATIVA AGRICOLA GRAO_DO_VALE V1.0\n");
  printf("ANO: 2024\n");
  printf("---------------------------------------------------------------");
  printf("\nOrigem: %d           Num. de amostras: %d        Data: %d/%d\n", protocolo, quantidadeDeAmostras, mes, ano);
  printf("Umidade(%%): %.2f%%    Peso limpo(t): %.2f       Transgenico: %s\n\n", percentualUmidade, pesoLimpo, (transgenico == 1) ? "Sim" : "Não");
  printf("Umidade: Faixa 1                            Quant.:%d\n", quantidadeA);
  printf("Ident. das Amostras: ");

  for (int i = 0; i < quantidadeA; i++) {
    printf("%d - ", faixaA[i]);
  }

  printf("\n\n");

  printf("Umidade: Faixa 2                            Quant.:%d\n", quantidadeB);
  printf("Ident. das Amostras: ");

  for (int i = 0; i < quantidadeB; i++) {
    printf("%d - ", faixaB[i]);
  }

  printf("\n\n");
  printf("Umidade: Faixa 3                            Quant.:%d\n", quantidadeC);
  printf("Ident. das Amostras: ");

  for (int i = 0; i < quantidadeC; i++) {
    printf("%d - ", faixaC[i]);
  }

  printf("\n\n");
}