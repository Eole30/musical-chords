#include "library.h"

#include <stdio.h>

/* Elisabeth
 * compiling in linux : gcc -shared -O2 -o library.so -fPIC library.c
 */

void hello() {
    printf("Hello, World!\n");
}

int returns_int(){
    return 1;
}
