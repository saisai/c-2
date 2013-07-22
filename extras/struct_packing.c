#include <stdio.h>
#define MAX_DATA 512

typedef struct {
  int i;
  int j;
  char x;
} example1;

typedef struct {
	int i;
	int j;
	char name[MAX_DATA];
} example2;

typedef struct __attribute__((__packed__)){
  int i;
  int j;
  char x;
} example3;

int main(int argc, char *argv[]) {
	printf("Size of example1 (two ints and a char): %ld.\n", sizeof(example1));
	printf("Size of example2 (two ints and a string): %ld.\n", sizeof(example2));
	printf("Size of example3 (two ints and a char, not padded): %ld.\n", sizeof(example3));

  return 0;
}
