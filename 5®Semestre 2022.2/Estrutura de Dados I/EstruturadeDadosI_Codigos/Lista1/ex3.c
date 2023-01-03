/* -----------------------------------------------------------------------------
Resposta ao exercício: Exercicio 3 -  Calcular o tamanho de uma string 
Autor: Eduardo Izidorio
Matrícula: 2020000315
----------------------------------------------------------------------------- */
#include <stdio.h>

int tamanho_string(char *str){
    int tam = 0, i = 0;
    while(str[i] != '\0'){   //Feito a contagem dos caracteres
        tam++;
        i++;
    }
    return tam;
}

int main(){
    char str1[] = {'E' , 'D' , 'U' , 'A' , 'R' , 'D' , 'O' , '\0'};
    char str2[] = "Izidorio";
    printf("%d\n", tamanho_string(str1));
    printf("%d\n", tamanho_string(str2));

    return 0;
}