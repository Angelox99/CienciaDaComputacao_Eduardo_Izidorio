/* -----------------------------------------------------------------------------
Resposta ao exercício: Exercicio 4 - Concatenar duas strings.
Autor: Eduardo Izidorio
Matrícula: 2020000315
----------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

int tamanho_string(char *str){
    int tam = 0, i = 0;
    while(str[i] != '\0'){
        tam++;
        i++;
    }
    return tam;
}
char* concatena_string(char* s1, char* s2) {
    int tamS3 = tamanho_string(s1) + tamanho_string(s2);
    char *s3 = malloc(tamS3 * sizeof(char));
    for(int i = 0; i < tamanho_string(s1); i++){
        s3[i] = s1[i];
    }
    for(int i = tamanho_string(s1), j = 0; i < tamanho_string(s2), j < tamanho_string(s2); i++, j++){
        s3[i] = s2[j];
    }
    return s3;
}

int main(){
    char str1[100];
    char str2[100];
    scanf("%s", str1);
    scanf("%s", str2);
    char *str3 = concatena_string(str1, str2);
    //printf("%s\n", str1);
    //printf("%s\n", str2);
    printf("%s\n", str3);

    return 0;
}