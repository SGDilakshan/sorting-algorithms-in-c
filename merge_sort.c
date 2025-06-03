#include <stdio.h>

void merge(int num[], int first, int mid, int last) {
    int i, j, k;
    int n1 = mid - first + 1;
    int n2 = last - mid;

    int left[n1], right[n2];

    for (i = 0; i < n1; i++)
        left[i] = num[first + i];
    for (j = 0; j < n2; j++)
        right[j] = num[mid + 1 + j];

    i = 0; j = 0; k = first;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            num[k++] = left[i++];
        } else {
            num[k++] = right[j++];
        }
    }

    while (i < n1) num[k++] = left[i++];
    while (j < n2) num[k++] = right[j++];
}

void mergeSort(int num[], int first, int last) {
    if (first < last) {
        int mid = first + (last - first) / 2;
        mergeSort(num, first, mid);
        mergeSort(num, mid + 1, last);
        merge(num, first, mid, last);
    }
}

int main() {
    int numbers[10];
    printf("Enter 10 numbers:\n");
    for (int i = 0; i < 10; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    mergeSort(numbers, 0, 9);

    printf("\nSorted Array (Merge Sort):\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    return 0;
}
