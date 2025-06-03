#include <stdio.h>
#include <string.h>

#define MAX 100

void countingSort(int arr[], int n) {
    int output[n];
    int count[MAX];
    int max = arr[0];

    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    memset(count, 0, sizeof(count));

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main() {
    int numbers[10];
    printf("Enter 10 non-negative integers:\n");
    for (int i = 0; i < 10; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    countingSort(numbers, 10);

    printf("\nSorted Array (Counting Sort):\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    return 0;
}
