#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, n = 5;
    int* v;
    v =(int*) malloc(n * sizeof(int));

    for (i = 0; i < 5; i++){
        v[i] = i;
    }
    printf("&v = %p, v = %d, v[i] = %p, i = %d ", &v, v, v[i], i);

    return 0;
}