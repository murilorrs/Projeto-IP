#include <stdio.h>
#include <string.h>

#define PATH_PREFIX "../data/cargas/"  // Diretório onde os arquivos de entrada estão armazenados
#define MAX_FILENAME_SIZE 100   // Tamanho máximo permitido para o nome do arquivo
#define MAX_PATH_SIZE (MAX_FILENAME_SIZE + sizeof(PATH_PREFIX))//Tamanho total da string. ex:(../data/cargas/DadosGraos-Carga1.txt)

int leArquivo(int *ID) {
    FILE *file; //declarando o ponteiro do tipo FILE
    char nomeDoArquivo[MAX_FILENAME_SIZE]; //declarando um vetor que vai receber o nome do arquivo q o usuário digitar.
    char caminhoCompleto[MAX_PATH_SIZE]; //declarando um vetor que vai receber a string completa do caminho.

    int ID, protocolo, mes, dia, tipo, quantidadeDeAmostras, impurezas, umidade, DD, MM;
    float peso;

    printf("Digite o nome do arquivo da carga:\n");
    fgets(nomeDoArquivo, MAX_FILENAME_SIZE, stdin); //Aqui eu usei fgets invés de scanf pq o scanf tava me retornando um "O" no final do nome do arquivo, aí o programa nao encontrava o caminho certo

    nomeDoArquivo[strcspn(nomeDoArquivo, "\n")] = '\0'; //Removendo o /n do final da string pq também tava atrapalhando na hora de encontrar o arquivo. 

    snprintf(caminhoCompleto, sizeof(caminhoCompleto), "%s%s", PATH_PREFIX, nomeDoArquivo); //Essa função snprintf vai juntar o PATH_PREFIX (../cargas/data/) com o nome do arquivo que o usuário digitar, e vai retornar na variável caminhoCompleto o caminho inteiro do arquivo de entrada (../data/cargas/nome_do_arquivo)
    // printf("%s\n", caminhoCompleto); //Só mostra no terminal o caminho completo pra ter certeza que nao teve erro de digitação

    file = fopen(caminhoCompleto, "r");//abre o arquivo 

    //checa se o arquivo foi aberto corretamente
    if(file == NULL){
        printf("O arquivo nao existe.");
    }else{

    printf("Digite o dia e mes do recebimento dessa carga");
    scanf("%d%d", &DD, &MM);

    fscanf(file, "%d%d%f%d%d", &ID, &protocolo, &peso, &quantidadeDeAmostras, &tipo);//Usa fscanf pra ler os 4 primeiros dados que são diferentes dos demais abaixo
    printf(" ID:%d\n Protocolo:%d\n Peso:%.2f\n Qtd de Amostras:%d\n Tipo:%d\n\n", ID, protocolo, peso, quantidadeDeAmostras, tipo );

    char conteudoDoArquivo[200];//declara um vetor que vai receber o conteudo do arquivo.
    float somaImpureza = 0, somaUmidade = 0; //declara as variáveis que vao receber a soma de impurezas e umidade de cada amostra

    fgets(conteudoDoArquivo, 100, file);// Como a gente precisa ler a partir da segunda linha (os dados de imupreza e umidade começam la), lemos aqui a primeira linha pra pularmos ela no próximo fgets

    //faz um loop pra ler linha a linha do arquivo até acabar
    while(fgets(conteudoDoArquivo, 100, file) != NULL){
        int idAmostra;//declaracao do elemento da primeira coluna
        float valor2, impureza, umidade; //declaracao dos elementos da segunda coluna em diante.
        
        if(sscanf(conteudoDoArquivo, "%d %f %f %f", &idAmostra, &valor2, &impureza, &umidade) == 4){//sscanf pra checar se os arquivos lidos estao corretos.

            //faz a soma das impurezas e umidades das amostras.
            somaImpureza += impureza;
            somaUmidade += umidade;
        }
    }

    printf("Impurezas: %.2f\nUmidade: %.2f", somaImpureza, somaUmidade);//imprime no terminal

}
    fclose(file); //fecha o arquivo de entrada
}