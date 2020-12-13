#include <stdio.h>
#include <string.h>

#define FIB_CAPACITY   (500)

long int getFibAtIndex(int index, long int* memo)
{
    if (index == 1 || index == 2)
        return 1;
    else if (memo[index] == -1)
    {
        memo[index] = getFibAtIndex(index - 1, memo) + getFibAtIndex(index - 2, memo);
        return memo[index];
    }
    else
        return memo[index];
}

int main()
{
    long int memo[FIB_CAPACITY];
    memset (memo, -1, FIB_CAPACITY * sizeof(long int));

    printf("Fibonachi value at index %d is %ld\n", 1, getFibAtIndex(1, memo));
    printf("Fibonachi value at index %d is %ld\n", 2, getFibAtIndex(2, memo));
    printf("Fibonachi value at index %d is %ld\n", 3, getFibAtIndex(3, memo));
    printf("Fibonachi value at index %d is %ld\n", 4, getFibAtIndex(4, memo));
    printf("Fibonachi value at index %d is %ld\n", 5, getFibAtIndex(5, memo));
    printf("Fibonachi value at index %d is %ld\n", 6, getFibAtIndex(6, memo));
    printf("Fibonachi value at index %d is %ld\n", 50, getFibAtIndex(50, memo));

    return 0;
}
