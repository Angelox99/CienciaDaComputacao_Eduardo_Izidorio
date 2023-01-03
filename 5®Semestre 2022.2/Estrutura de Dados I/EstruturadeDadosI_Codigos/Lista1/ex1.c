/* -----------------------------------------------------------------------------
Resposta ao exercício: Exercicio 1 - leia 10 inteiros, armazene-os em um vetor, e escreva na ordem contrária a de leitura.
Autor: Eduardo Izidorio
Matrícula: 2020000315
----------------------------------------------------------------------------- */

#include <stdio.h>

int main(){
    int vet[10];
    int *p = vet;

//Insirindo 10 valores dentro do vetor
    printf("Insira 10 numeros:\n");
    for(int i = 0; i < 10; i++){
        //scanf("%d \n ", vet + i);
        scanf("%d", p + i);
        //scanf("%d", &vet[i]);
    }
//Leitura dos vetores na ordem
    printf("Vetores na ordem inserida:\n");
    for(int i = 0; i < 10; i++){
        printf("[%d]", *(vet + i));
    }
    printf("\n");

//Fazendo a Leitura dos valores do vetor de tras para frente
    printf("\n Imprimindo os 10 numeros na ordem contraria:\n");
    for(int i = 9; i >= 0; i--){
        printf("[%d]", *(p + i));
    }
    return 0;
}