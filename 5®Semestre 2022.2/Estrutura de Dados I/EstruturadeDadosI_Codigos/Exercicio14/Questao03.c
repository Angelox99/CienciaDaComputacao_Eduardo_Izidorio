/* ---------------------------------------------
* Autor: Eduardo Henrique de Almeida Izidorio
* Matricula: 2020000315
* Questao 03 - Implemente um programa para realizar a busca de uma palavra em um dicionário
------------------------------------------------ */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void insert_array(char v[100][100], int v_size)
{
    int bin;
    scanf("Lixo: %d", &bin); // Variável lixo por conta do console dar dupla entrada de valores.
    for (int i = 0; i < v_size; i++)
    {
        char *word;
        scanf(" %s", word);
        strcpy(v[i], word);
    }
}

void print_array(char v[100][100], int v_size)
{
    printf("\n");
    int i = 0;
    while (i < v_size)
    {
        printf("%s, ", v[i]);
        i++;
    }
    printf("\n");
}

int binary_recursive_search(char v[100][100], int v_size, int index, char word[100], int word_size)
{
    int i = 0;
    while (i < word_size)
    {
        // printf("%c <> %c: %d de %d\n",v[index][i], word[i], i, word_size);
        if (v[index][i] != word[i])
        {
            return binary_recursive_search(v, v_size, index + 1, word, word_size);
        }
        i++;
    }

    return index;
}

int main()
{

    char word_for_search[100];
    printf("Escolha a palavra para pesquisar: ");
    scanf(" %s", word_for_search);
    printf("\n");

    int v_size;
    printf("Escolha o tamanho do dicionario (100 max.): ");
    scanf(" %d", &v_size);
    printf("\n");
    char v[v_size][100];

    insert_array(v, v_size);

    print_array(v, v_size);

    int position = binary_recursive_search(v, v_size, 0, word_for_search, strlen(word_for_search));

    printf("Posicao: %d", position);

    return 0;
}