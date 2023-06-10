#include <stdio.h>
#include <ctype.h>

int main(void) {
    char nome_arquivo[50];
    printf("Digite o nome do arquivo: ");
    scanf("%s", nome_arquivo);

    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nome_arquivo);
        return 1;
    }

    int vogais = 0, consoantes = 0, c;
    while ((c = fgetc(arquivo)) != EOF) {
        if (isalpha(c)) {
            c = tolower(c);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vogais++;
            } else {
                consoantes++;
            }
        }
    }
    fclose(arquivo);

    printf("O arquivo %s tem:\n", nome_arquivo);
    printf("%d vogais.\n", vogais);
    printf("%d consoantes.\n", consoantes);

    return 0;
}