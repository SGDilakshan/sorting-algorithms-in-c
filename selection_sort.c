#include <stdio.h>

void swapnum(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int num[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (num[j] < num[minIndex]) {
                minIndex = j;
            }
        }
        swapnum(&num[i], &num[minIndex]);
    }
}

int main() {
    int numbers[10];
    printf("Enter 10 numbers:\n");
    for (int i = 0; i < 10; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    selectionSort(numbers, 10);

    printf("\nSorted Array (Selection Sort):\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    return 0;
}
