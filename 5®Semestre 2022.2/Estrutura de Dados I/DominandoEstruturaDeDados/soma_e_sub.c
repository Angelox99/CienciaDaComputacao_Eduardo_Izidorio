#include <stdio.h>

void soma_e_sub (int x, int y, int *soma, int *sub){
    *soma = x + y;
    *sub = x - y;

    puts("---a funcao---");
    printf("&x = %p, x = %d\n", &x, x);
    printf("&y = %p, y = %d\n", &y, y);
    printf("&*soma = %p, *soma = %d\n", &*soma, *soma);
    printf("&*sub = %p, *sub = %d\n\n", &*sub, *sub);
    
}

// int soma_e_sub(int x, int y, int *sub){
//     int soma = x + y;
//     *sub = x - y;

//     puts("---a funcao---");
//     printf("&x = %p, x = %d\n", &x, x);
//     printf("&y = %p, y = %d\n", &y, y);
//     printf("&*sub = %p, *sub = %d\n\n", &*sub, *sub);

//     return soma;
// }

int main(){
    int a = 10;
    int b = 20;
    int c;
    int d;

    puts("---Antes de chamar a funcao---");
    printf("&a = %p, a = %d\n", &a, a);
    printf("&b = %p, b = %d\n", &b, b);
    printf("&c = %p, c = %d\n", &c, c);
    printf("&d = %p, d = %d\n\n", &d, d);

    soma_e_sub (a, b, &c, &d);
    //c = soma_e_sub(a, b, &d);

    puts("---Depois de chamar a funcao---");
    printf("&a = %p, a = %d\n", &a, a);
    printf("&b = %p, b = %d\n", &b, b);
    printf("&c = %p, c = %d\n", &c, c);
    printf("&d = %p, d = %d\n\n", &d, d);
    
    return 0; 
}