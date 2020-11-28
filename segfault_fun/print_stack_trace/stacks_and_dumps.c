#include <stdio.h>
#include <stdlib.h>

#include <signal.h>  //for signal()
#include <execinfo.h>  //for backtrace() and backtrace_symbols_fd()
#include <unistd.h>  //for STDERR_FILENO

#define __MAX_STACK_ENTRIES__     (20)
#define __SHOULD_PRINT_STRACE__   (1)
#define __SHOULDNT_PRINT_STRACE__ (0)
void handler(int sig) {
  void *stack_entries[__MAX_STACK_ENTRIES__]; //array of void* meant to hold stack entries
  size_t size;

  // get void*'s for all entries on the stack
  size = backtrace(stack_entries, __MAX_STACK_ENTRIES__);

  // print out all the frames to stderr
  fprintf(stderr, "Error: signal %d:\n", sig);
  backtrace_symbols_fd( stack_entries, size, STDERR_FILENO);
  exit(1);
}

void a_func();
void another_func();
char yet_another_func(int length);
void a_func()
{
    another_func();
}

void another_func()
{
    char received_result;
    received_result = yet_another_func(20);
    printf("received_result: %c\n", received_result);
}
char yet_another_func(int length)
{
    char result = 'Y';
    int* my_array = (int*) malloc(length);
    free(my_array);

    printf("my_array+2 dereferenced : %d\n", *(my_array+length+10000000)); //this should cause a segfault
    return result;
}


int main(int argc, char **argv) {
#if __SHOULD_PRINT_STRACE__
    signal(SIGSEGV, handler);   // install our handler
                                //To get a coredump, comment out this line using
                                //#define flags above
#endif
    a_func();
    return 0;
}
