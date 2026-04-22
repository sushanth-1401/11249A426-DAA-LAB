#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
void ls(int a1[], int begin, int stop, int search) {
    if (begin == stop)
        printf("Element not found\n");
    else if (a1[begin] == search)
        printf("Element found @ position %d\n", begin + 1);
    else
        ls(a1, begin + 1, stop, search);
}
void main() {
    int a[10000], n, key, i;
    clock_t start, end;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter key: ");
    scanf("%d", &key);
    start = clock();
    ls(a, 0, n, key);
    end = clock();
    printf("Total time taken for execution: %lf\n", (double)(end - start));
    printf("\nPress ESC to exit...\n");
    while (getch() != 27);
}
