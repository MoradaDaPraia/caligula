#include "searching.h"
#include "sorting.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void print(int *arr, int len) {
    int i;
    printf("[");
    for (i = 0; i < len; i++) {
        printf("%d", arr[i]);
        if (i != len - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

bool sorted(int *arr, int len) {
    int i;
    for (i = 0; i < len - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

void scramble(int *arr, int len) {
    int i, j, k, temp;
    for (i = 0; i < len; i++) {
        arr[i] = i + 1;
    }

    for (i = 0; i < len; i++) {
        j = rand() % len;
        k = rand() % len;
        temp = arr[j];
        arr[j] = arr[k];
        arr[k] = temp;
    }
}

void performance(const char *name, void (*sortfn)(int *, int), const int *arr,
                 int len) {
    int *copy = malloc(sizeof(int) * len);
    clock_t start, end;
    float elapsed_ms;

    memcpy(copy, arr, sizeof(int) * len);

    start = clock();
    sortfn(copy, len);
    end = clock();

    if (!sorted(copy, len)) {
        printf("The %s algorithm could not sort the array.\n", name);
        free(copy);
        return;
    }

    elapsed_ms = ((double)(end - start) / (CLOCKS_PER_SEC / 1000));
    printf("The %s algorithm sorted %d elements in %.2fms.\n", name, len,
           elapsed_ms);
    free(copy);
}

void benchmark(const int *arr, int len) {
    int target, position;
    clock_t start, end;
    srand(time(NULL));

    performance("insertionsort", insertionsort, arr, len);
    performance("selectionsort", selectionsort, arr, len);
    performance("bubblesort", bubblesort, arr, len);
    performance("shakesort", shakesort, arr, len);
    performance("shellsort", shellsort, arr, len);
    performance("quicksort", quicksort, arr, len);
    performance("mergesort", mergesort, arr, len);

    target = rand() % len;

    start = clock();
    position = linearsearch(arr, len, target);
    end = clock();

    printf("The linearsearch algorithm found target %d at position %d in "
           "%ld nanosecond(s).\n",
           target, position, end - start);

    int *copy = malloc(sizeof(int) * len);
    memcpy(copy, arr, sizeof(int) * len);

    quicksort(copy, len);

    start = clock();
    position = binarysearch(copy, len, target);
    end = clock();

    printf("The binarysearch algorithm found target %d at position %d in "
           "%ld nanosecond(s).\n",
           target, position, end - start);

    free(copy);
}

int main(void) {
    int predefined[] = {
        53, 62, 59, 27, 98, 25, 72, 77, 27, 39, 70, 55, 88, 67, 49, 50, 69,
        83, 36, 45, 10, 68, 66, 52, 53, 90, 85, 51, 79, 69, 49, 61, 78, 34,
        59, 45, 19, 71, 53, 99, 98, 32, 26, 95, 82, 27, 75, 71, 78, 36, 93,
        58, 45, 86, 84, 18, 29, 17, 19, 19, 82, 94, 57, 81, 99, 91, 70, 23,
        99, 24, 92, 11, 41, 17, 44, 77, 89, 88, 23, 17, 86, 23, 44, 96, 85,
        37, 92, 83, 23, 53, 40, 12, 70, 86, 88, 85, 52, 61, 50, 35};
    int len, *arr, *copy, target, position;
    char opt = ' ';
    srand(time(NULL));

    while (opt != 't' && opt != 'b') {
        printf("Test (t) or benchmark (b)? ");
        opt = getchar();
        while (getchar() != '\n') {
        }
    }

    if (opt == 'b') {
        len = 1024 * 32;
        arr = malloc(sizeof(int) * len);

        scramble(arr, len);
        benchmark(arr, len);

        free(arr);
        return 0;
    }

    len = sizeof(predefined) / sizeof(predefined[0]);
    arr = predefined;

    copy = malloc(sizeof(int) * len);

    memcpy(copy, arr, sizeof(int) * len);
    insertionsort(copy, len);
    printf("insertionsort = ");
    print(copy, len);

    memcpy(copy, arr, sizeof(int) * len);
    selectionsort(copy, len);
    printf("\nselectionsort = ");
    print(copy, len);

    memcpy(copy, arr, sizeof(int) * len);
    bubblesort(copy, len);
    printf("\nbubblesort = ");
    print(copy, len);

    memcpy(copy, arr, sizeof(int) * len);
    shakesort(copy, len);
    printf("\nshakesort = ");
    print(copy, len);

    memcpy(copy, arr, sizeof(int) * len);
    shellsort(copy, len);
    printf("\nshellsort = ");
    print(copy, len);

    memcpy(copy, arr, sizeof(int) * len);
    quicksort(copy, len);
    printf("\nquicksort = ");
    print(copy, len);

    memcpy(copy, arr, sizeof(int) * len);
    mergesort(copy, len);
    printf("\nmergesort = ");
    print(copy, len);

    target = 40;
    position = linearsearch(arr, len, target);

    printf("\nThe linearsearch algorithm found target %d at position %d.\n",
           target, position);

    position = binarysearch(copy, len, target);

    printf("\nThe binarysearch algorithm found target %d at position %d.\n",
           target, position);

    free(copy);

    return 0;
}
