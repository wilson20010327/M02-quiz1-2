#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 100
void q_sort_array(void);
void quickSortArray(int *array, int begin, int end);
/*
swap the value of two container with the xor operator
*/
void swap(int *a, int *b);
/*
shuffle the array
*/
void shuffleArray(int *array, size_t arraySize);
/*
random the array not create a new array, user should create array previously
*/
void randomArray(int *array, size_t arraySize);
/*
print the array from begin to end (include array[end])
*/
void printArray(int *array, int begin, int end);