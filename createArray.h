#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 20  
/*
shuffle the array 
*/
void shuffleArray(int *array, size_t arraySize)
{
    if (arraySize <= 0)
        return;

    for (size_t i = 0; i < arraySize ; i++) {
        size_t j = i + rand() / (RAND_MAX / (arraySize - i) + 1);
        int t = array[j];
        array[j] = array[i];
        array[i] = t;
    }
    return ;
}
/*
random the array not create a new array, user should create array previously
*/
void randomArray(int *array, size_t arraySize) 
{   
    if (arraySize <= 0)
        return;
    for (size_t i = 0; i < arraySize; i++) {
        array[i]=i;
    }
    shuffleArray(array,arraySize);
    return ;
}
/*
print the array from begin to end (include array[end])
*/
void printArray(int * array,int begin, int end )
{
    if(begin <0 || end >=ARRAY_SIZE) return ;
    for(int i=0;i<ARRAY_SIZE;i++)
        printf("%d ", array[i]);
    printf("\n");
}