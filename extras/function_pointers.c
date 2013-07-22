#include <stdio.h>

int add(int a, int b) {
  return a + b;
}

int subtract(int a, int b) {
	return a - b;
}

int multiply(int a, int b) {
	return a * b;
}

int main(int argc, char *argv[]) {

  int (*func_cb)(int a, int b) = add;

  printf("Using the normal function: %d.\n", add(10, 10));
  printf("Using the function pointer: %d.\n", func_cb(10, 10));

  func_cb = subtract;

  printf("Using the function pointer: %d.\n", func_cb(10, 10));

  func_cb = multiply;

  printf("Using the function pointer: %d.\n", func_cb(10, 10));

  return 0;
}
