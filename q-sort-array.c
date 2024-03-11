# include "createArray.h"


int main(int argc, char *argv[])
{   
    int array[ARRAY_SIZE];
    randomArray(array,ARRAY_SIZE);
    printArray(array,0,ARRAY_SIZE-1);
    return 0;
}