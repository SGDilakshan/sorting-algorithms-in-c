#include <stdio.h>

void insertionSort(int num[], int n) {
    for (int i = 1; i < n; i++) {
        int key = num[i];
        int j = i - 1;
        while (j >= 0 && num[j] > key) {
            num[j + 1] = num[j];
            j--;
        }
        num[j + 1] = key;
    }
}

int main() {
    int numbers[10];
    printf("Enter 10 numbers:\n");
    for (int i = 0; i < 10; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    insertionSort(numbers, 10);

    printf("\nSorted Array (Insertion Sort):\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    return 0;
}
