#include <stdio.h>

/*
 * What's happening here?
 * Though C can initialize automatic variables with 0
 * there is more to it
 *
 * Here I called and returned from the same function multiple times
 * back to back.
 * What you will observe on most machines is that at the first call
 * machine will show local variable at that location to be intialized with 0
 * but for subsequent calls it ends up with the same old value in the
 * variable location even without intialization
 *
 * So, always intialize your variable, and pay attention to compiler
 * warnings
 */
void somefunc();

int main()
{
    somefunc();
    somefunc();
    somefunc();
    return 0;
}

void somefunc()
{
    printf("Entering function: %s file %s line %d \n", __FUNCTION__ , __FILE__ , __LINE__ );
    int a;
    printf("Print a before intialization: %d\n", a);
    a=10;
    printf("Print a after intialization: %d\n", a);
    printf("Leaving function: %s\n", __func__);
}
