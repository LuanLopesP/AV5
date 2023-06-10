#include <stdio.h>
#include <ctype.h>
#include <windows.h>

int main() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);

    char filename_in[100];
    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", filename_in);

    char filename_out[100];
    printf("Digite o nome do arquivo de saída: ");
    scanf("%s", filename_out);

    FILE* file_in = fopen(filename_in, "r");
    if (file_in == NULL) {
        printf("Não foi possível abrir o arquivo de entrada.\n");
        return 1;
    }

    FILE* file_out = fopen(filename_out, "w");
    if (file_out == NULL) {
        printf("Não foi possível abrir o arquivo de saída.\n");
        return 1;
    }

    char ch;
    while ((ch = fgetc(file_in)) != EOF) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||
                        ch == 'u') {
                ch = '*';
            }
        }
        fputc(ch, file_out);
    }

    fclose(file_in);
    fclose(file_out);

    printf("Arquivo de entrada copiado para o arquivo de saída com vogais substituídas por '*'.\n");

    return 0;
}