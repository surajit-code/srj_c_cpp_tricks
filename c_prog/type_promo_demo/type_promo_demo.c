#include<stdio.h>

int main()
{
    double x = 10.7;
    int    y = 2;

    double z = x + y;
    int w = x + y;

    printf("%lf\n", z);
    printf("%d\n", w); //type demotion, inaccurate answer

    printf( "%zu\n", sizeof(int));
    unsigned int a = 0xFFFFFFFF;
    printf("a accurate: %u\n", a);
    printf( "%zu\n", sizeof(short));
    unsigned short b = a;
    printf("a inaccurate when stored in b: %u\n", b); //type demotion

    return 0;
}
