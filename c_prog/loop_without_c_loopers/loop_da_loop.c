#include <stdio.h>

void recursion(int input);

int main()
{
    int i = 10;

    recursion(i);
    return 0;
}


void recursion(int input)
{
    if(input>0)
        recursion(input-1);
    printf("%d\n", input);
}
