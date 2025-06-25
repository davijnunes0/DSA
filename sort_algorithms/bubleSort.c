#include <stdio.h>
#include <stdlib.h>

void printArray(int *v,int n);
void bubbleSort(int *v, int n);
void bubbleSortClassic(int *v, int n);

int main(void){

    int number[] = {5,4,3,2,1};
    int number2[] = {10,9,7,8,5};
    int quantity = sizeof(number) / sizeof(number[0]);
    
    printf("\n");

    printArray(number,quantity);
    printf("\n");

    bubbleSortClassic(number,quantity);
    printArray(number,quantity);
    printf("\n");

    printArray(number2,quantity);
    printf("\n");

    bubbleSort(number2,quantity);
    printArray(number2,quantity);


}


void bubbleSort(int *v, int n){
    int i, continua, var, fim = n;

    do{
        continua = 0;
        for(i = 0; i < fim - 1; i++){
            if(v[i] > v[i+1]){
                var = v[i];
                v[i] = v[i+1];
                v[i+1] = var;
                continua = 1;
            }
        }
        fim --;
    }while(continua);
}

void bubbleSortClassic(int *v, int n){
    // Laço externo: Controla o número de passagens
    // Precisa de no máximo n-1 passagens.
    for(int i = 0; i < n -1; i++){
        // Laço interno faz as comparações e trocas.
        // A cada passagem de 'i' o maior elemento "flutua" para sua posição correta
        // Por isso, o laço interno pode ir até 'n - 1 - 1';
        for(int j = 0; j < n - 1 - i; j++){
            if(v[j] > v[j+1]){
                int var = v[j];
                v[j] = v[j+1];
                v[j+1] = var;
            }
       
        }
    }

}

void printArray(int *v, int n){
    for(int i = 0;  i < n; i++){
        printf("%d->",v[i]);
    }
}