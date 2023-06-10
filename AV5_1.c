#include<stdio.h>
#include<stdlib.h>


int main(){
    FILE *arq;
   
    char caracter,inicio;
   
    arq = fopen("arq.txt","w");

    while(caracter!='0'){ 
        printf("Entre com os dados: ");
        fflush(stdin);
        scanf("%c",&caracter);
        fprintf(arq,"%c\n",caracter);
    }
    fclose(arq);
   
    arq = fopen("arq.txt","r");
   
    if(arq == NULL){
        printf("Erro na abertura do arquivo!\n");
        system("pause");
        exit(1);
    }
   
    rewind(arq);
    inicio = getc(arq);
   
    printf("\nLendo caracter por caracter:\n");
   
    while(inicio!=EOF){
        printf("%c",inicio);
        inicio = getc(arq);
    }
    fclose(arq);
}