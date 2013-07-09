#include <stdio.h>

/* Warning: This program is wrong on purpose. */

int main() {
  int age = 10;
  int height;

  printf("I am %d years old.\n");
  printf("I am %d inches tall.\n", height);

  return 0;
}

/*

EXTRA CREDIT

1. Fix this program using Valgrind and the compiler as your guide.

Valgrind is fucked on Mountain Lion.

2. Read up on Valgrind on the internet.

Fascinating!

Discovered the full valgrind tool suite, run via valgrind --tool=

memcheck - memory allocation checker
cachegrind - cache profiler
callgrind - extension to cachegrid plus data on callgraphs
massif - heap profiler
helgrind - thread debugger
DRD - detects errors in multithreaded programs

3. Download other software and build it by hand. 
Try something you already use but never built for yourself.

Bitch, please.

4. Look at how the Valgrind source files are laid out in the 
source directory and read its Makefile. Don't worry, none of 
that makes sense to me either.

Moon.

*/
