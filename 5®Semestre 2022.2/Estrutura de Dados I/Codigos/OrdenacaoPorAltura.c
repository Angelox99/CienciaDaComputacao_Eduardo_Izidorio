#include <stdio.h>
void bubbleSort(int vetor[], int tamanho)
{
    int aux, i, j, cont = 0;
    for (j = tamanho - 1; j >= 1; j--)
    {
        for (i = 0; i < j; i++)
        {
            if (vetor[i] > vetor[i + 1])
            {
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
                cont++;
            }
        }
    }
    printf("Trocas: %d\n", cont);
}

int main()
{
    int vet[20] = {900, 901, 902, 903, 904, 905, 906, 907, 908, 909, 910, 911, 912, 913, 914, 915, 916, 917, 918, 919};
    int vet2[20] = {919, 918, 917, 916, 915, 914, 913, 912, 911, 910, 909, 908, 907, 906, 905, 904, 903, 902, 901, 900};
    int vet3[20] = {901, 902, 903, 904, 905, 906, 907, 908, 909, 910, 911, 912, 913, 914, 915, 916, 917, 918, 919, 900};
    int vet4[20] = {918, 917, 916, 915, 914, 913, 912, 911, 910, 909, 908, 907, 906, 905, 904, 903, 902, 901, 900, 919};

    for (int i = 0; i < 20; i++)
    {
        printf("%d ", vet[i]);
    }
    puts(" ");
    bubbleSort(vet, 20);
    for (int i = 0; i < 20; i++)
    {
        printf("%d ", vet[i]);
    }

    puts(" ");
    bubbleSort(vet2, 20);
    for (int i = 0; i < 20; i++)
    {
        printf("%d ", vet2[i]);
    }

    puts(" ");
    bubbleSort(vet3, 20);
    for (int i = 0; i < 20; i++)
    {
        printf("%d ", vet3[i]);
    }

    puts(" ");
    bubbleSort(vet4, 20);
    for (int i = 0; i < 20; i++)
    {
        printf("%d ", vet4[i]);
    }
    return 0;
}