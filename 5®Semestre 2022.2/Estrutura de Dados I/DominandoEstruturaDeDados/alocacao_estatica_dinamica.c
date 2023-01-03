#include <stdio.h>
#include <stdlib.h> // Contém o NULL, Calloc, Malloc, free


int main(){
    //alocacao de um vetor estático(memória Stack)
    int vs[5] = {0, 10, 20, 30, 40};

    puts("---- VETOR ESTATICO ----");
    printf("&vs = %p vs = %p\n", &vs, vs);

    for (int i = 0; i < 5; i++) {
        printf("&vs[%d] = %p, vs[%d] = %d\n", i, &vs[i], i, vs[i]);
    }
    puts("\n");
    
    
    //alocacao de um vetor dinamico usando malloc(memória Heap)
    puts("---- VETOR DINAMICO COM MALLOC ----");

    int *vh_mal = (int *) malloc(5 * sizeof(int));  //todos os elementos possuem "lixo de memória"

    printf("&vh_mal = %p vh_mal = %p\n", &vh_mal, vh_mal);

    for (int i = 0; i < 5; i++) {
        printf("&vh_mal[%d] = %p, vh_mal[%d] = %d\n", i, &vh_mal[i], i, vh_mal[i]);
    }
    puts("\n");
    
    //alocacao de um vetor dinamico usando Calloc(memória Heap)
    // todo o bloco alocado possui bits 0, isto é,
    //Garante que todos os elementos alocados(do vetor) terão valor 0
    puts("---- VETOR DINAMICO COM CALLOC ----");

    int *vh_cal = (int *) calloc(5, sizeof(int));

    printf("&vh_cal = %p vh_cal = %p\n", &vh_cal, vh_cal);

    for (int i = 0; i < 5; i++) {
        printf("&vh_cal[%d] = %p, vh_cal[%d] = %d\n", i, &vh_cal[i], i, vh_cal[i]);
    }
    puts("\n");

    //NÃO ESTAMOS DESALOCANDO OS VETORES DINÂNICOS
    
    return 0;
}