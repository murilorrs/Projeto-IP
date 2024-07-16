//ARQUIVO COM PROPOSITO DE ENSINO E NAO FAZ PARTE DO PROJETO FINAL (LOGO MAIS SERÁ REMOVIDO)
#include <stdio.h>

int main(){
    //Declara um ponteiro do tipo FILE
    FILE *file;

    //abre o arquivo no modo append (atualizar)
    file = fopen("../data/atualizarDataBase.txt", "a");

    //adicona uma nova msg no arquivo
    fprintf(file, "\nEssa mensagem foi adicionada apos executar o programa atualizar.c :D");

    //fecha o arquivo
    fclose(file);


    return 0;
}