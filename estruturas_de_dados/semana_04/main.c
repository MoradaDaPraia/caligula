#include <stdio.h>
#include <stdlib.h>

void print(const int *arr, int len) {
    int i;
    printf("[");
    for (i = 0; i < len; i++) {
        printf("%d", arr[i]);
        if (i < len - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void quicksort(int *arr, int len) {
    int start, end, i, j, pivot, temp, top, *stack;

    start = 0;
    end = len - 1;
    stack = malloc(sizeof(int) * len);
    top = -1;

    stack[++top] = start;
    stack[++top] = end;

    while (top >= 0) {
        end = stack[top--];
        start = stack[top--];

        i = start;
        j = start;
        pivot = end;

        while (j < pivot) {
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

        if (start < pivot - 1) {
            stack[++top] = start;
            stack[++top] = pivot - 1;
        }

        if (pivot + 1 < end) {
            stack[++top] = pivot + 1;
            stack[++top] = end;
        }
    }

    free(stack);
}

int main(void) {
    int arr[] = {53, 62, 59, 27, 98, 25, 72, 77, 27, 39, 70, 55, 88, 67, 49,
                 50, 69, 83, 36, 45, 10, 68, 66, 52, 53, 90, 85, 51, 79, 69,
                 49, 61, 78, 34, 59, 45, 19, 71, 53, 99, 98, 32, 26, 95, 82,
                 27, 75, 71, 78, 36, 93, 58, 45, 86, 84, 18, 29, 17, 19, 19,
                 82, 94, 57, 81, 99, 91, 70, 23, 99, 24, 92, 11, 41, 17, 44,
                 77, 89, 88, 23, 17, 86, 23, 44, 96, 85, 37, 92, 83, 23, 53,
                 40, 12, 70, 86, 88, 85, 52, 61, 50, 35};
    int len = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, len);
    printf("arr = ");
    print(arr, len);

    return 0;
}
