#include <stdio.h>

#define _my_sizeof_(_type_variable) (char*)(&_type_variable+1) - (char*) &_type_variable

/*
 * What's happening here ?
 * We utilize pointer arithmatic to get the size of a type in C
 * &_type_variable gives us address of variable x
 * &_type_variable+1 gives us address in memory where next double can be stored
 * C can do this by making sure there is enough space between addresses so that
 * the previous variable x does not get overwritten or corrupted
 * ergo this will be the size of x (8 bytes)
 * 
 * Why the typecast to (char*)?
 * If you subtract two pointers pointing to double type
 * It will give you how many double type variables can be
 * stored between those addresses.
 * So if the pointer types remain double we will end up with 1
 * because there is room for 1 double variable between those addresses
 *
 * char needs just 1 byte of storage, so if we typecast these addresses to char*
 * and subtract, C will tell us how many characters can be stored between those
 * addresses and so we end up with 8 as a result, which happens to be the number
 * of bytes consumed by a double variable.
 */

int main()
{
    double x = 10;
    printf("%lu\n", sizeof(x));

    printf("%lu\n",
             _my_sizeof_(x));
    return 0;
}
