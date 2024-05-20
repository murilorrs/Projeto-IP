#include <stdio.h>
#include "file_header.h"

#define PATH_PREFIX "../data/cargas/"  // Diretório onde os arquivos de entrada estão armazenados
#define MAX_FILENAME_SIZE 100   // Tamanho máximo permitido para o nome do arquivo
#define MAX_PATH_SIZE (MAX_FILENAME_SIZE + sizeof(PATH_PREFIX))//Tamanho total da string. ex:(../data/cargas/DadosGraos-Carga1.txt)

int main() {
    FILE *file; //declarando o ponteiro do tipo FILE
    char nomeDoArquivo[MAX_FILENAME_SIZE]; //declarando um vetor que vai receber o nome do arquivo q o usuário digitar.
    char caminhoCompleto[MAX_PATH_SIZE]; //declarando um vetor que vai receber a string completa do caminho.

    printf("Digite o nome do arquivo:\n");
    fgets(nomeDoArquivo, MAX_FILENAME_SIZE, stdin); //Aqui eu usei fgets invés de scanf pq o scanf tava me retornando um "O" no final do nome do arquivo, aí o programa nao encontrava o caminho certo

    nomeDoArquivo[strcspn(nomeDoArquivo, "\n")] = '\0'; //Removendo o /n do final da string pq também tava atrapalhando na hora de encontrar o arquivo. 

    snprintf(caminhoCompleto, sizeof(caminhoCompleto), "%s%s", PATH_PREFIX, nomeDoArquivo); //Essa função snprintf vai juntar o PATH_PREFIX (../cargas/data/) com o nome do arquivo que o usuário digitar, e vai retornar na variável caminhoCompleto o caminho inteiro do arquivo de entrada (../data/cargas/nome_do_arquivo)
    printf("%s\n", caminhoCompleto); //Só mostra no terminal o caminho completo pra ter certeza que nao teve erro de digitação

    file = fopen(caminhoCompleto, "r");//abre o arquivo 

    //checa se o arquivo foi aberto corretamente
    if(file == NULL){
        printf("O arquivo nao existe.");
        return 0;
    }

    char conteudoDoArquivo[400]; //Declara um vetor que vai receber o conteudo do arquivo.
    while(fgets(conteudoDoArquivo, sizeof(conteudoDoArquivo), file) != NULL){
        printf("%s", conteudoDoArquivo);
    }

    fclose(file);


    return 0;
}