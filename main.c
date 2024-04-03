#include <stdio.h>

void quickSort(int arr[], int esquerda, int direita) {
    if (esquerda < direita) { //verifica se ainda há elementos a serem ordenados
        int pivot = arr[esquerda]; // definir o pivô, usado como referência para dividir o array em duas partes
        int i = esquerda - 1; // i iniciado como índice antes do início do array, usado para percorrer o array da esquerda para a direita
        int j = direita + 1; // J iniciado como indice após fim do array, percorrer da direita para esquerda

        while (1) { //loop infinito que será interrompido quando i ultrapassar j.
            do {
                i++; // Incrementamos i até encontrarmos um elemento maior ou igual ao pivô.
            } while (arr[i] < pivot);

            do {
                j--; //Decrementamos j até encontrarmos um elemento menor ou igual ao pivô.
            } while (arr[j] > pivot);

            if (i >= j) break; //quando ultrapassar sai do loop

            // Troca arr[i] e arr[j]
            int temp = arr[i]; //troca os elementos de posição, coloca os menores a esquerda e os maiores a direita
            arr[i] = arr[j];
            arr[j] = temp;
        }

        // Chama recursivamente quickSort para os sub-arrays à esquerda e à direita do pivô
        quickSort(arr, esquerda, j);
        quickSort(arr, j + 1, direita);
    }
}

int main() {
    int arr[] = {10, 4, 5, 1, 3, 9}; //array para ser ordenado
    int size = sizeof(arr) / sizeof(arr[0]); //Calcula o tamanho do array

    printf("Array antes da ordenacao: ");
    for (int i = 0; i < size; i++) { // Loop para exibir os elementos do array antes da ordenação.
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Chama a função quickSort para ordenar o array
    quickSort(arr, 0, size - 1);

    printf("Array depois da ordenacao: ");
    for (int i = 0; i < size; i++) { //Loop para exibir os elementos do array após a ordenação.
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}