#include<stdio.h>

int main()
{
    double x = 10.7;
    int    y = 2;

    double z = x + y;
    int w = x + y;

    printf("%lf\n", z);
    printf("%d\n", w); //type demotion, inaccurate answer
    return 0;
}
