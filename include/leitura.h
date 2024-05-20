#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include <stdio.h> // Inclui a biblioteca padrão do C para entrada e saída de dados

// Declaração da função para abrir um arquivo
FILE* abrirArquivo(const char* nomeArquivo, const char* modo);

// Declaração da função para fechar um arquivo
void fecharArquivo(FILE* arquivo);

#endif // FILE_OPERATIONS_H
