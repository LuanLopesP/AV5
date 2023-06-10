#include <stdio.h>
#include <ctype.h>

int main() {
    //system("dir");
    char nome_arquivo[100];
    printf("Digite o nome do arquivo: ");
    scanf("%s", nome_arquivo);

    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int count = 0;
    char c;
    while ((c = fgetc(arquivo)) != EOF) {
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }

    printf("O arquivo tem %d vogais.\n", count);

    fclose(arquivo);
    return 0;
}