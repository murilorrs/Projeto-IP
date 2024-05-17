#include <stdio.h>

int main(){

    FILE *file;
    file = fopen("../data/DataBase.txt", "a");//abrindo o diretório no modo append(modificar)

    fprintf(file, "\nHello, World!\n");//primeira mensagem escrita no diretório
    fprintf(file, "Segunda mensagem no arquivo\n");//escrevendo outra mensagem

    fclose(file);//fechando o arquivo(boas práticas)


    return 0;
}