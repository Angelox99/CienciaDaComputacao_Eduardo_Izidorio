#include<stdio.h>

void bobbleSort(int vetor[], int tamanho){
	int aux, i, j, cont = 0;
	for(j=tamanho-1; j>=1; j--){
		for(i=0; i<j; i++){
			if(vetor[i]>vetor[i+1]){
				aux=vetor[i];
                    vetor[i]=vetor[i+1];
                    vetor[i+1]=aux;
                    cont++;
            }
        }
    }
    printf("Trocas: %d\n", cont);
}

int main(){
    int vet[5] = {4 , 0, 3, 2, 1};

    for(int i = 0; i < 5; i++){
        printf("%d ", vet[i]);
    }
    puts(" ");
    bobbleSort(vet, 5);

    for(int i = 0; i < 5; i++){
        printf("%d ", vet[i]);
    }
    return 0;
}