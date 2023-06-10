#include <stdio.h>

int main() {
    char nome_arquivo[50];
    int num_linhas = 0;
    char c;

    printf("Digite o nome do arquivo: ");
    scanf("%s", nome_arquivo);

    FILE *arquivo = fopen(nome_arquivo , "r");

    if (arquivo) {
        while ((c = getc(arquivo)) != EOF) {
            if (c == '\n') {
                num_linhas++;
            }
        }
        printf("O arquivo %s possui %d linhas.\n", nome_arquivo, num_linhas);

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo.\n");
    }

    return 0;
}