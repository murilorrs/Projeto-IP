#ifndef RELATORIOS_H
#define RELATORIOS_H

void cabecalhoRelatorioMes();
void mesEspecifico(int origem, int cargas, float gUmidade);
void mesAMes(int origem, int cargas, float gUmidade);

void cabecalhoRelatorioGeral();
void relatorioGeral(int origem, float pesoTotal, float pesoLimpo, int tipo, float gUmidade);

void relatorioDeCarregamento(int protocolo, int quantidadeDeAmostras, int mes, int ano, float percentualUmidade, float pesoLimpo, int transgenico, int quantidadeA, int quantidadeB, int quantidadeC,
                             int faixaA[], int faixaB[], int faixaC[], float percentualImpureza);

#endif