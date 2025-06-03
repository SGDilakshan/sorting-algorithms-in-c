#include <stdio.h>

void swapnum(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int num[], int low, int high) {
    int pivot = num[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (num[j] < pivot) {
            i++;
            swapnum(&num[i], &num[j]);
        }
    }
    swapnum(&num[i + 1], &num[high]);
    return i + 1;
}

void quickSort(int num[], int low, int high) {
    if (low < high) {
        int pi = partition(num, low, high);
        quickSort(num, low, pi - 1);
        quickSort(num, pi + 1, high);
    }
}

int main() {
    int numbers[10];
    printf("Enter 10 numbers:\n");
    for (int i = 0; i < 10; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    quickSort(numbers, 0, 9);

    printf("\nSorted Array (Quick Sort):\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    return 0;
}
