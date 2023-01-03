#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_STR 100

void imprimir_forca(int estado){
    if(estado == 0){
    printf("\n----------");
    printf("\n|        |");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n-\n");
    } else if(estado == 1){
    printf("\n----------");
    printf("\n|        |");
    printf("\n|        0");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n-\n");
    } else if(estado == 2){
    printf("\n----------");
    printf("\n|        |");
    printf("\n|        0");
    printf("\n|        |");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n-\n");
    } else if(estado == 3){
    printf("\n----------");
    printf("\n|        |");
    printf("\n|        0");
    printf("\n|       /|");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n-\n");
    } else if(estado == 4){
    printf("\n----------");
    printf("\n|        |");
    printf("\n|        0");
    printf("\n|       /|\\");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n-\n");
    } else if(estado == 5){
    printf("\n----------");
    printf("\n|        |");
    printf("\n|        0");
    printf("\n|       /|\\");
    printf("\n|       /");
    printf("\n|");
    printf("\n|");
    printf("\n-\n");
    } else if(estado == 6){
    printf("\n----------");
    printf("\n|        |");
    printf("\n|        0");
    printf("\n|       /|\\");
    printf("\n|       / \\");
    printf("\n|");
    printf("\n| GAME OVER ");
    printf("\n-\n");
    } 
}

int main(){
    
    imprimir_forca(5);
    char p_sec[TAM_STR];

    printf("JOGADOR 1: \n");
    printf("Digite a palavra secreta: ");
    fgets(p_sec, TAM_STR, stdin);
    
    p_sec[strlen(p_sec)-1] = '\0';

    printf("Palavra sec: %s", p_sec);
    printf("Tamanho da Palavra: %d\n\n", strlen(p_sec));

    return 0;
}

//
//
//
//
//
//
//
//