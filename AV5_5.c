#include <stdio.h>

int main(void) {
    char nome_arquivo[50], caractere;
    printf("Digite o nome do arquivo: ");
    scanf("%s", nome_arquivo);
    printf("Digite o caractere: ");
    scanf(" %c", &caractere);

    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nome_arquivo);
        return 1;
    }

    int ocorrencias = 0, c;
    while ((c = fgetc(arquivo)) != EOF) {
        if (c == caractere) {
            ocorrencias++;
        }
    }
    fclose(arquivo);

    printf("O arquivo %s tem %d ocorrencia(s) do caractere '%c'.\n", nome_arquivo, ocorrencias, caractere);

    return 0;
}