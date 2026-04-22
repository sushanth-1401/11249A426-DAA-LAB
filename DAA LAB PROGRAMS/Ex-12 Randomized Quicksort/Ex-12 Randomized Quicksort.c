#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int A[], int low, int high) {
    int pivot = A[high];
    int i = low - 1, j;
    for (j = low; j < high; j++) {
        if (A[j] <= pivot) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[high]);
    return i + 1;
}
int randomPartition(int A[], int low, int high) {
    int r = low + rand() % (high - low + 1); 
    swap(&A[r], &A[high]);
    return partition(A, low, high);
}
void randomizedQuickSort(int A[], int low, int high) {
    if (low < high) {
        int pi = randomPartition(A, low, high);
        randomizedQuickSort(A, low, pi - 1);
        randomizedQuickSort(A, pi + 1, high);
    }
}
int main() {
    int n, i;
    srand(time(NULL));
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int A[n];
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
    randomizedQuickSort(A, 0, n - 1);
    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    printf("\nPress ESC to exit...\n");
    while (getch() != 27);
    return 0;
}
