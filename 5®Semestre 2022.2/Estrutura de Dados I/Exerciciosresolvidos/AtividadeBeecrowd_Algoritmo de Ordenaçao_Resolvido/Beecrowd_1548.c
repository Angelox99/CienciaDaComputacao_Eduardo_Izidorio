/* --------------------------------------------------------
* Exercício: beecrowd 1548 - Fila do Recreio
* Autor: Eduardo Henrique de Almeida Izidorio
* Matrícula: 2020000315
----------------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>

int comp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}
int main()
{
    int N, M, resposta;
    int original[1000], ordenado[1000];
    scanf("%d", &N); // número de elementos
    for (int k = 0; k < N; ++k)
    {
        scanf("%d", &M);
        for (int i = 0; i < M; ++i)
        {
            scanf("%d", &original[i]);
            ordenado[i] = original[i];
        }
        qsort(ordenado, M, sizeof(int), comp);
        resposta = 0;
        for (int i = 0; i < M; ++i)
        {
            if (original[i] == ordenado[i])
                ++resposta;
        }
        printf("%d\n", resposta);
    }
    return 0;
}