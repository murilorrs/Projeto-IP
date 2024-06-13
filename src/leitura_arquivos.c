#include <stdio.h>
#include <stdlib.h>
#define PREFIXO "../data/cargas" //Caso esteja executando no vscode utilize "../../data/" pois o vscode executa o terminal na pasta output.

int main () {

  FILE *file; //Ponteiro do arquivo, deixei o nome genérico pois precisaremos apenas de um por enquanto.
  char nomeArquivo[100]; // Variável para armazenar o nome do arquivo
  char caminhoArquivo[150]; // Buffer pra armazenar o caminho do arquivo concatenado

  printf("Digite o nome do arquivo: ");
  scanf("%s", nomeArquivo); //Ler e guardar o nome do arquivo a ser aberto

  snprintf(caminhoArquivo, 150, "%s%s", PREFIXO, nomeArquivo);

  file = fopen(caminhoArquivo, "r"); //Função para abertura do arquivo em modo de leitura (read) -- Estudar pra conseguir fazer o usuário inserir o nome do arquivo e ele conseguir ser inserido no GENERICO (não é variável, é só pra eu saber depois mesmo)

  if (file == NULL)
  {
    printf("O arquivo informado não existe.");
    return 0;
  } // Verifica se o arquivo digitado existe, se não existir exibe a mensagem
  // Caso contrário continuará o código normalmente

  int identificacao_carga, numero_protocolo, numero_amostras, tipo_produto;
  float peso_bruto; // Declaração das variáveis da primeira linha dos arquivos

  fscanf(file, "%d %d %f %d %d", &identificacao_carga, &numero_protocolo, &peso_bruto, &numero_amostras, &tipo_produto); // Lê os arquivos da primeira linha e armazena nas variiáveis

  // printf("idcarga = %d, numero_protocolo = %d, pesoBruto = %f, numero_amostras = %d, tipo produto = %d\n", identificacao_carga, numero_protocolo, peso_bruto, numero_amostras, tipo_produto); //Verificar se armazenou certinho (DESCOMENTE CASO QUEIRA VER)

  char conteudoTemporario [100]; //vetor para armazenarmos as strings temporárias lidas pelo fgets

  fgets(conteudoTemporario, 100, file); //Esse comando é só para iniciarmos a leitura a partir da segunda linha (já que o fgets lê uma linha a cada execução).


  // Declara as variáveis que vão ser utilizadas pra ler os dados das linhas posteriores a primeira
  int identificacaoAmostra, pesoImpurezas;
  float pesoBrutoAmostra, grauUmidade; 
  // Fim da declaração

  
  while (fgets (conteudoTemporario, 100, file) != NULL) // Enquanto o conteúdo lido no arquivo não for nulo, continuará lendo as linhas
  {
    //Aqui cada vez que o laço roda ele armazena os dados de cada amostra nas variáveis temporárias, dentro desse while faremos os cálculos com cada variável
    sscanf(conteudoTemporario, "%d %f %d %f", &identificacaoAmostra, &pesoBrutoAmostra, &pesoImpurezas, &grauUmidade); 

    // printf("%d %f %d %f\n", identificacaoAmostra, pesoBrutoAmostra, pesoImpurezas, grauUmidade); CASO QUEIRA ANALISAR O QUE ESTA SENDO LIDO SÓ DESCOMENTAR ISSO AQUI
    
  }

  fclose(file); // Fecha o arquivo
  
  return 0;
}
