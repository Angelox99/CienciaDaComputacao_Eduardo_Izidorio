#include <stdio.h>
#include <stdlib.h>

int main(){
    int v1[5] = {0, 1, 2, 3, 4};
    int *v2, *p;
    int i;

    p = v1;  //P esta recebendo o endereço de v1[0].
    p[3] = p[4] = 10;  //p[3] e p[4] vão receber o valor 10.

    v2 = (int*) malloc(5 * sizeof(int)); //alocando na memória heap 5 elementos de tamanho inteiro.

    for (i = 0; i < 5; i++){ // i vai ficar mudar o valor a cada passada, até chegar em 5.
        v2[i] = v1[i];  //copiando no v2 os vetores de v1.
    }
    // printf("&v2[i] = %p, v2[i] = %d\n", &v2[i], v2[i]);
    
    free(v2); //Limpa a memória heap.
    v2 = NULL; //aponta para NULL.


    return 0;
}