#include "../include/leitura_arquivos.h"
#include "../include/database.h"
#include "../include/menu.h"
#include "../include/relatorios.h"

void carregamento() {

  FILE *file;               // Ponteiro do arquivo, deixei o nome genérico pois precisaremos apenas de um por enquanto.
  char nomeArquivo[100];    // Variável para armazenar o nome do arquivo
  char caminhoArquivo[150]; // Buffer pra armazenar o caminho do arquivo concatenado

  printf("Digite o nome do arquivo:\n=> ");
  scanf("%s", nomeArquivo); // Ler e guardar o nome do arquivo a ser aberto
  limpaTerminal();

  snprintf(caminhoArquivo, 150, "%s%s", PREFIXO, nomeArquivo);

  file = fopen(caminhoArquivo, "r"); // Função para abertura do arquivo em modo de leitura (read) -- Estudar pra conseguir fazer o usuário inserir o nome do arquivo e ele conseguir ser inserido no
                                     // GENERICO (não é variável, é só pra eu saber depois mesmo)

  if (file == NULL) {
    printf("!!!!! O arquivo informado nao existe !!!!!\n\n");
    return;
  } // Verifica se o arquivo digitado existe, se não existir exibe a mensagem
  // Caso contrário continuará o código normalmente

  int mes, ano;
  printf("Digite o mes de recebimento da carga:\n=>");
  scanf("%d", &mes);
  printf("Digite o ano de recebimento da carga:\n=>");
  scanf("%d", &ano);

  int identificacao_carga, numero_protocolo, numero_amostras, tipo_produto;
  float peso_bruto; // Declaração das variáveis da primeira linha dos arquivos

  fscanf(file, "%d %d %f %d %d", &identificacao_carga, &numero_protocolo, &peso_bruto, &numero_amostras, &tipo_produto); // Lê os arquivos da primeira linha e armazena nas variiáveis

  // printf("idcarga = %d, numero_protocolo = %d, pesoBruto = %f, numero_amostras = %d, tipo produto = %d\n", identificacao_carga, numero_protocolo, peso_bruto, numero_amostras, tipo_produto);
  // //Verificar se armazenou certinho (DESCOMENTE CASO QUEIRA VER)

  char conteudoTemporario[100]; // vetor para armazenarmos as strings temporárias lidas pelo fgets

  fgets(conteudoTemporario, 100, file); // Esse comando é só para iniciarmos a leitura a partir da segunda linha (já que o fgets lê uma linha a cada execução).

  // Declara as variáveis que vão ser utilizadas pra ler os dados das linhas posteriores a primeira
  int identificacaoAmostra, pesoImpurezas;
  float pesoBrutoAmostra, grauUmidade;

  // Fim da declaração

  float diferencaPesoImpureza = 0;
  float multiplicacaoImpurezaDiferenca;
  float pic, guc, pesoLimpo;
  float somatorioPesoB = 0, somatorioPesoI = 0;
  int faixaA[50] = {}, faixaB[50] = {}, faixaC[50] = {};
  int quantidadeA = 0, quantidadeB = 0, quantidadeC = 0;

  while (fgets(conteudoTemporario, 100, file) != NULL) // Enquanto o conteúdo lido no arquivo não for nulo, continuará lendo as linhas
  {

    // Aqui cada vez que o laço roda ele armazena os dados de cada amostra nas variáveis temporárias, dentro desse while faremos os cálculos com cada variável
    sscanf(conteudoTemporario, "%d %f %d %f", &identificacaoAmostra, &pesoBrutoAmostra, &pesoImpurezas, &grauUmidade);

    somatorioPesoB += (pesoBrutoAmostra * 1000);
    somatorioPesoI += pesoImpurezas;

    diferencaPesoImpureza += (pesoBrutoAmostra * 1000) - pesoImpurezas;
    multiplicacaoImpurezaDiferenca += (pesoBrutoAmostra * 1000 - pesoImpurezas) * grauUmidade;

    if (grauUmidade >= 0 && grauUmidade <= 8.5) {
      faixaA[quantidadeA] = identificacaoAmostra;
      quantidadeA++;
    } else if (grauUmidade > 8.5 && grauUmidade <= 15) { // Alterei o >= para > para evitar sobreposição
      faixaB[quantidadeB] = identificacaoAmostra;
      quantidadeB++;
    } else if (grauUmidade > 15 && grauUmidade <= 25) { // Alterei o >= para > para evitar sobreposição
      faixaC[quantidadeC] = identificacaoAmostra;
      quantidadeC++;
    } else {
      printf("Grau de umidade fora do intervalo esperado: %f\n", grauUmidade); // Mensagem de debug
    }
  }

  guc = multiplicacaoImpurezaDiferenca / diferencaPesoImpureza;
  pic = somatorioPesoI / somatorioPesoB * 100;
  pesoLimpo = peso_bruto - ((pic * peso_bruto) / 100);

  fclose(file);
  limpaTerminal();
  relatorioDeCarregamento(numero_protocolo, numero_amostras, mes, ano, guc, pesoLimpo, tipo_produto, quantidadeA, quantidadeB, quantidadeC, faixaA, faixaB, faixaC, pic);
  arquivar(identificacao_carga, numero_protocolo, mes, ano, tipo_produto, peso_bruto, pic, guc, pesoLimpo);

  return;
}