#include "q-sort-array.h"

void quickSortArray(int *array, int begin, int end)
{
    if (end <= begin) {
        return;
    }
    int pivot = array[begin];
    int left = begin, right = end;
    while (right > left) {
        if (array[right] >= pivot) {
            right--;
            continue;
        } else {
            left++;
            swap(&array[left], &array[right]);
        }
    }
    swap(&array[begin], &array[right]);
    printf("pivot: %d follow:", *(&pivot));
    printArray(array, begin, end);
    quickSortArray(array, begin, right - 1);
    quickSortArray(array, right + 1, end);
    return;
}
void q_sort_array(void)
{
    int array[ARRAY_SIZE];
    randomArray(array, ARRAY_SIZE);
    printArray(array, 0, ARRAY_SIZE - 1);
    quickSortArray(array, 0, ARRAY_SIZE - 1);
    printArray(array, 0, ARRAY_SIZE - 1);
    return;
}
void swap(int *a, int *b)
{
    if (*a == *b)
        return;
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}
/*
shuffle the array
*/
void shuffleArray(int *array, size_t arraySize)
{
    if (arraySize <= 0)
        return;

    for (size_t i = 0; i < arraySize; i++) {
        size_t j = i + rand() / (RAND_MAX / (arraySize - i) + 1);
        int t = array[j];
        array[j] = array[i];
        array[i] = t;
    }
    return;
}
/*
random the array not create a new array, user should create array previously
*/
void randomArray(int *array, size_t arraySize)
{
    if (arraySize <= 0)
        return;
    for (size_t i = 0; i < arraySize; i++) {
        array[i] = i;
    }
    shuffleArray(array, arraySize);
    return;
}
/*
print the array from begin to end (include array[end])
*/
void printArray(int *array, int begin, int end)
{
    if (begin < 0 || end >= ARRAY_SIZE)
        return;
    for (int i = begin; i <= end; i++)
        printf("%d ", array[i]);
    printf("\n");
}