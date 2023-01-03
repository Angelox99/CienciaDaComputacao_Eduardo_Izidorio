/* -----------------------------------------------------------------------------
Resposta ao exercício: Exercicio 2 - Mude o programa anterior para ordenar o vetor usando o algoritmo da bolha.
Autor: Eduardo Izidorio
Matrícula: 2020000315
----------------------------------------------------------------------------- */

#include <stdio.h>

//funcao troca, para fazer com que os vetores troquem de lugar
void troca(int *x, int *y){
   int temp = *x;
   *x = *y;
   *y = temp; 
}

int main(){
    int vet[10];
    int *p = vet;

//Insirindo 10 valores no vetor, digitado pelo usuario
    printf("Insira 10 numeros:\n");
    for(int i = 0; i < 10; i++){
        scanf("%d \n ", vet + i);
    }

//Imprimi os 10 valores inseridos pelo usuario
    printf("\n Imprimindo os 10 numeros:\n");
    for(int i = 0; i < 10; i++){
        printf("[%d]", *(p + i));
    }
    printf("\n");

//Ordenando os valores com o BubbleSort
    printf("\n Ordenando com BubbleSort\n");
    for(int j =0; j < 10; j++){
        for(int i = 0; i < 10-1; i++){
        if(vet[i] > vet[i + 1])
            troca(&vet[i], &vet[i + 1]);
    }
    }

//Imprimindo os 10 valores em Ordem depois do bubbleSort
    printf("\n Imprimindo os 10 numeros:\n");
    for(int i = 0; i < 10; i++){
        printf("[%d]", *(p + i));
    }
    return 0;
}