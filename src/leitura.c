#include <stdio.h>
#include <string.h>

#define PATH_PREFIX "../data/cargas/"  // Diretório onde os arquivos de entrada estão armazenados
#define MAX_FILENAME_SIZE 100   // Tamanho máximo permitido para o nome do arquivo
#define MAX_PATH_SIZE (MAX_FILENAME_SIZE + sizeof(PATH_PREFIX)) // Tamanho total da string. ex:(../data/cargas/DadosGraos-Carga1.txt) ||funcao sizeof retorna a quantidade de caracteres de uma string.


//a funcao leArquivo recebe varios valores em forma de ponteiros que vamos usar, para assim podermos usar em outros arquivos.
void leArquivo() {
    FILE *file; // declarando o ponteiro do tipo FILE
    char nomeDoArquivo[MAX_FILENAME_SIZE]; // declarando um vetor que vai receber o nome do arquivo que o usuário digitar || O [MAX_FILE_NAME] recebe nada mais que o valor 100 definido la em cima
    char caminhoCompleto[MAX_PATH_SIZE]; // declarando um vetor que vai receber a string completa do caminho

    int ID, DD, MM, protocolo, quantidadeDeAmostras, tipo;
    float peso, somatorioDoPesoDasImpurezas, somatorioDoPesoDasAmostras, percentualDeImpurezas;

    printf("Digite o nome do arquivo da carga:\n");
    fgets(nomeDoArquivo, MAX_FILENAME_SIZE, stdin); // Aqui eu usei fgets invés de scanf porque o scanf estava me retornando um "O" no final do nome do arquivo, aí o programa nao encontrava o caminho certo
    nomeDoArquivo[strcspn(nomeDoArquivo, "\n")] = '\0'; // Removendo o /n do final da string porque também estava atrapalhando na hora de encontrar o arquivo

    snprintf(caminhoCompleto, sizeof(caminhoCompleto), "%s%s", PATH_PREFIX, nomeDoArquivo); // Essa função snprintf vai juntar o PATH_PREFIX (../cargas/data/) com o nome do arquivo que o usuário digitar, e vai retornar na variável caminhoCompleto, que é o caminho inteiro do arquivo de entrada (../data/cargas/nome_do_arquivo)
    // printf("%s\n", caminhoCompleto); // Esse codigo comentado mostra no terminal o caminho completo para ter certeza que não houve erro de digitação

    file = fopen(caminhoCompleto, "r"); // abre o arquivo 

    // checa se o arquivo foi aberto corretamente
    if (file == NULL) {
        printf("O arquivo nao existe.");
    } else {//se abriu corretamente continua o codigo

        printf("\nDigite o dia do recebimento dessa carga:\n");
        scanf("%d", &DD);
        printf("\nDigite o mes do recebimento dessa carga:\n");
        scanf("%d", &MM);

        fscanf(file, "%d%d%f%d%d", &ID, &protocolo, &peso, &quantidadeDeAmostras, &tipo); // Usa fscanf para ler os 5 primeiros dados do arquivo
        // printf("\nID: %d\nProtocolo: %d\nPeso: %.2f\nQtd de Amostras: %d\nTipo: %d\n", ID, protocolo, peso, quantidadeDeAmostras, tipo);// apenas mostra no terminal

        char conteudoDoArquivo[200]; // declara um vetor que vai receber o conteúdo do arquivo => a unica finalidade é pra podermos usar o fgets mais pra frente, nao armazena dados relevantes
        // inicializa as variáveis que vão receber a soma de impurezas e umidade de cada amostra => usando desreferenciamento novamente pq estamos usando ponteiros
        somatorioDoPesoDasImpurezas = 0;
        somatorioDoPesoDasAmostras = 0; 

        fgets(conteudoDoArquivo, 200, file); // Como a gente precisa ler a partir da segunda linha (os dados de impureza e umidade começam lá), lemos aqui a primeira linha para pulá-la no próximo fgets

        // faz um loop para ler linha a linha do arquivo até acabar
        while (fgets(conteudoDoArquivo, 200, file) != NULL) {
            int idAmostra; // declaração do elemento 1 da linha
            float pesoDaAmostra, pesoDaImpureza, umidade; // declaração dos elementos 2 em diante da mesma linha

            //O laço ta lendo linha por linha, toda vez que ele passa por uma linha esse sscanf armazena um dado da linha nas variaveis, nessa ordem do sscanf
            if (sscanf(conteudoDoArquivo, "%d %f %f %f", &idAmostra, &pesoDaAmostra, &pesoDaImpureza, &umidade) == 4) { //estou usando sscanf pq essa funcao além de funcionar como um fscanf normal, ela checa se os 4 valores foram lidos corretamente.
                // faz a soma das impurezas e umidades das amostras a cada iteração
                somatorioDoPesoDasImpurezas += pesoDaImpureza;
                somatorioDoPesoDasAmostras += pesoDaAmostra;
            } else {
                printf("Nao foi possivel ler a linha do arquivo.\n");
            }
        }

    percentualDeImpurezas = somatorioDoPesoDasImpurezas / somatorioDoPesoDasAmostras; 

    }
    fclose(file); // fecha o arquivo de entrada

    

}
