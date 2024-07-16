//ARQUIVO COM PROPOSITO DE ENSINO E NAO FAZ PARTE DO PROJETO FINAL (LOGO MAIS SERÁ REMOVIDO)
#include <stdio.h>

int main(){

    FILE *file;

    //abrindo o diretório no modo append(modificar)
    file = fopen("../data/escreverDataBase.txt", "w");

    //primeira mensagem escrita no diretório
    fprintf(file, "Hello, World!\n");

    //escrevendo outra mensagem
    fprintf(file, "Segunda mensagem no arquivo\n");

    //fechando o arquivo(boas práticas)
    fclose(file);


    return 0;
}