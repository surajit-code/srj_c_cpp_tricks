#include <stdio.h>
#include <sys/resource.h>

int main()
{
    struct rlimit this_prog_limit;
    getrlimit( RLIMIT_STACK, &this_prog_limit );

    printf("Stack size this program has consumed: %luMB\n", this_prog_limit.rlim_cur / (1024*1024));
    printf("Max stack size this program can consume: %luMB\n", this_prog_limit.rlim_max / (1024*1024));
    return 0;
}
