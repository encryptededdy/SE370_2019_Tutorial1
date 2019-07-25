#include <stdio.h>

int main( int argc, const char* argv[] )
{
    int foo;
    int *fooPointer = &foo;
    *fooPointer = 420;

    printf("%d\n", fooPointer); // Compiler warning
    printf("%d\n", *fooPointer);
    printf("%d\n", foo);

    int bar = *fooPointer;
    bar = 840;

    printf("%d\n", bar);
    printf("%d\n", foo);
}