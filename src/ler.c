//ARQUIVO COM PROPOSITO DE ENSINO E NAO FAZ PARTE DO PROJETO FINAL (LOGO MAIS SERÁ REMOVIDO)
#include <stdio.h>

int main(){
    //Declarando o ponteiro do tipo FILE
    FILE *file;

    //Abre o arquivo lerDataBases no modo read (leitura)
    file = fopen("../data/lerDataBase.txt", "r");

    //Verifica se o arquivo lerDataBases.txt existe
    if(file == NULL){
        printf("Arquivo nao existe");
        return 0;
    }

    //Cria um vetor com espaco pra 100 caracteres
    char conteudoDoArquivo [100];

    //A função fgets recebe 3 parametros. Nome do vetor, tamanho, e o ponteiro que aponta pro arquivo
    //Equanto essa não retornar nulo, ela continua lendo.
    while(fgets(conteudoDoArquivo, 100, file) != NULL){
        //imprime o contedudo do lerDataBase.txt
        printf("%s", conteudoDoArquivo);//%s porque o printf vai retornar um vetor de caracteres
    }

    //fecha o arquivo
    fclose(file);

    return 0;
}