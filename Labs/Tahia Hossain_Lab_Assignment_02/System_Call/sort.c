#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main(int argc, char *argv[]) {
    int size = argc - 1;
    int arr[size];

    for (int i = 0; i < size; i++) {
        arr[i] = atoi(argv[i + 1]);
    }

    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubbleSort(arr, size);

    printf("Sorted Array (Descending Order): ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}