#include <stdio.h>

#define _my_sizeof_(_type_variable) (char*)(&_type_variable+1) - (char*) &_type_variable
int main()
{
    double x = 10;
    printf("%lu\n", sizeof(x));

    printf("%lu\n",
             _my_sizeof_(x));
    return 0;
}
