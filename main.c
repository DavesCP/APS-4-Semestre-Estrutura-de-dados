#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort (int * v, int p, int r ) {
    int i, j, x;
    printf("QuickSort: ");
    x = v [(p + r) / 2];
    i = p;
    j = r;

    while (i <= j) {
        while (v[i] < x && i < r) {
            i ++;
        }

        while (v[j] > x && j > p) {
            j --;
        }
        if (i <= j) {
            troca (&v[i], &v[j]);
            i ++;
            j --;
        }
    }
    if (j > p) {
        quickSort (p, j, v);
    }
    if (i < r) {
        quickSort (i, r, v);
    }
}

void troca (int * a, int * b) {
    int aux;

    aux = * a;
    * a = * b;
    * b = aux;
}

void insertionSort(int * v, int n) {
    int i, j, elemento;

    printf("Selection Sort: \n");
    for (i = 1; i < n; i ++) {
        elemento = v[i];
        for (j = i - 1; j >= 0 && v[j] > elemento; j --) {
            v[j + 1] = v[j];
        }
        v[j + 1] = elemento;
    }
    for (int i = 0; i < n; i++) {
        //printf("%d ", v[i]);
    }

    //printf("\n");

}

void bubbleSort(int * v, int n)
{
    unsigned int aux;
    int i = 0;
    int j;

    while (i < n) {
        j = 0;
        while (j < i) {
            if (v[j] > v[i]) {
                aux = v[j];
                v[j] = v[i];
                v[i] = aux;
            }
            j ++;
        }
        i ++;
    }

    printf("Bubble sort: \n");
    for(i = 0; i < n; i++)
    {
        //printf("%d ", v[i]);
    }
}

int main(void)
{
    int k = NULL, *vetor = NULL;
    float tempo;
    clock_t t1, t2;

	printf("Tamanho do vetor: ");
	scanf("%i", &k);

	vetor = (int *)malloc(k * sizeof(int));

    srand(time(NULL));
	for (int i = 0; i < k; i++)
	{
		vetor[i] = rand() % 1000000;
		printf("Valor  %i : %i" , i+1,  vetor[i]);
		printf("\n");
	}
    printf("\n");
    t1 = clock();
    bubbleSort(vetor, k);
    t2 = clock();
    tempo = difftime(t2,t1)*1000 /CLOCKS_PER_SEC;
    printf("Tempo: %f", tempo);
    printf("ms");
    printf("\n\n");

    t1 = clock();
    insertionSort(vetor, k);
    t2 = clock();
    tempo = difftime(t2,t1)*1000 /CLOCKS_PER_SEC;
    printf("Tempo Selection: %f", tempo);
    printf("ms");
    printf("\n\n");

    t1 = clock();
    quickSort(vetor, vetor[0], vetor[k]);
    t2 = clock();
    tempo = difftime(t2,t1)*1000 /CLOCKS_PER_SEC;
    printf("Tempo QuickSort: %f", tempo);
    printf("ms");

	system("pause");
}
