#include <stdio.h>
#include <stdlib.h>

void selectionSort(int  *V, int N);
void printArray(int *v, int n);

int main(void){

    int number[] = {23,4,67,-8,0};

    printArray(number,5);
    selectionSort(number,5);
    printf("\n");
    printArray(number,5);

    return 0;
}
void selectionSort(int *array, int N){

    int index = 0;
    int indexJ = 0;
    int var = 0;
    int lower = 0;

    for(index = 0; index < N - 1; index++){
        lower = index;
        for(indexJ = index + 1; indexJ < N; indexJ++){
            if(array[indexJ] < array[lower]){
                lower = indexJ;
            }
        }

        if(lower != index){
            var = array[index];
            array[index] = array[lower];
            array[lower] = var;
        }
    }
}

void printArray(int *v, int n){
    for(int i = 0;  i < n; i++){
        printf("%d->",v[i]);
    }
}