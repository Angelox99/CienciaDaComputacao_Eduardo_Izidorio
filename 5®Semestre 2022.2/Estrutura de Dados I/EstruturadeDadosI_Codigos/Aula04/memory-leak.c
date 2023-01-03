//NUNCA RODAR ESSE CÓDIGO, JAMAIS!!!!!
#include <stdio.h>
#include <stdlib.h>

int main(){
    char *v;
    for(int i = 0; 1 < 1000000000; i++) {
        v = calloc(10, sizeof(char));
        free(v);
    }

    return 0;
}
