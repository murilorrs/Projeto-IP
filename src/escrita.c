#include <stdio.h>
#include "../include/leitura.h"

int main(){

    int ID;

    leArquivo(&ID);

    printf("%d", ID);

    return 0;
}