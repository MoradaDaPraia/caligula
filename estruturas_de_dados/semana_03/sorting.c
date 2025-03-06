#include "sorting.h"
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void insertionsort(int *arr, int len) {
    int i, j;
    for (i = 0; i < len - 1; i++) {
        j = i;
        while (j >= 0 && arr[j] > arr[j + 1]) {
            int temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

void selectionsort(int *arr, int len) {
    int i, j, min, temp;
    for (i = 0; i < len - 1; i++) {
        min = i;
        for (j = i + 1; j < len; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void bubblesort(int *arr, int len) {
    int i, j;

    for (i = 0; i < len; i++) {
        for (j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void shakesort(int *arr, int len) {
    int i, left = 0, right = len - 1;

    while (left < right) {
        i = left;
        while (i < right) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
            }
            i++;
        }

        right--;
        i = right;
        while (i > left) {
            if (arr[i] < arr[i - 1]) {
                int temp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = temp;
            }
            i--;
        }
        left++;
    }
}

void shellsort(int *arr, int len) {
    int exp = (int)(log(len) / log(2));
    int gap, i, j, temp;

    while (exp > 0) {
        gap = pow(2, exp) - 1;
        for (i = 0; i < len - gap; i += gap) {
            j = i;
            while (j >= 0 && arr[j] > arr[j + gap]) {
                temp = arr[j + gap];
                arr[j + gap] = arr[j];
                arr[j] = temp;
                j -= gap;
            }
        }
        exp--;
    }
}

void quicksort_r(int *arr, int start, int end) {
    int len, pivot, temp, i, j;
    if (start >= end) {
        return;
    }

    len = end - start + 1;
    pivot = rand() % len + start;

    temp = arr[pivot];
    arr[pivot] = arr[end];
    arr[end] = temp;
    pivot = end;

    i = start, j = start;
    while (j < end) {
        if (arr[j] < arr[pivot]) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
        j++;
    }

    temp = arr[i];
    arr[i] = arr[pivot];
    arr[pivot] = temp;
    pivot = i;

    quicksort_r(arr, start, pivot - 1);
    quicksort_r(arr, pivot + 1, end);
}

void quicksort(int *arr, int len) {
    quicksort_r(arr, 0, len - 1);
}

void mergesort_r(int *arr, int start, int end) {
    int middle, i, j, k, len, *temp;
    if (start >= end) {
        return;
    }

    middle = (start + end) / 2;

    mergesort_r(arr, start, middle);
    mergesort_r(arr, middle + 1, end);

    len = end - start + 1;
    temp = malloc(sizeof(int) * len);
    i = start;
    j = middle + 1;
    k = 0;

    while (i <= middle && j <= end) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= middle) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= end) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    memcpy(&arr[start], temp, sizeof(int) * len);
    free(temp);
}

void mergesort(int *arr, int len) {
    mergesort_r(arr, 0, len - 1);
}
