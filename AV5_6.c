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

    int letras[26] = {0}, c;
    while ((c = fgetc(arquivo)) != EOF) {
        if (isalpha(c)) {
            c = tolower(c);
            letras[c - 'a']++;
        }
    }
    fclose(arquivo);

    printf("O arquivo %s tem as seguintes letras:\n", nome_arquivo);
    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", i + 'a', letras[i]);
    }

    return 0;
}