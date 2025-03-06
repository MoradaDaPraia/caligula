#include "searching.h"

int linearsearch(const int *arr, int len, int target) {
    int i;
    for (i = 0; i < len; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarysearch(const int *arr, int len, int target) {
    int start = 0, end = len - 1, middle = (start + end) / 2;

    while (start <= end) {
        int value = arr[middle];
        if (value == target) {
            return middle;
        }

        if (value > target) {
            end = middle - 1;
            middle = (start + end) / 2;
        } else {
            start = middle + 1;
            middle = (start + end) / 2;
        }
    }

    return -1;
}
