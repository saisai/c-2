#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void die(const char *message) {
  if (errno) {
  	perror(message);
  } else {
  	printf("ERROR: %s\n", message);
  }
  exit(1);
}

// Set up a function pointer and typedef it.
typedef int (*compare_cb)(int a, int b);

int *bubble_sort(int *numbers, int count, compare_cb cmp) {
	int temp = 0;
	int i = 0;
	int j = 0;
	int *target = malloc(count * sizeof(int));

	if (!target) die("Memory error.");

	memcpy(target, numbers, count * sizeof(int));

	for (i = 0; i < count; i++) {
		for (j = 0; j < count -1; j++) {
      if (cmp(target[j], target[j + 1]) > 0) {
      	temp = target[j + 1];
      	target[j + 1] = target[j];
      	target[j] = temp;
      }
		}
	}
  return target;
}

int sorted_order(int a, int b) {
  return a - b;
}

int reverse_order(int a, int b) {
  return b - a;
}

int strange_order(int a, int b) {
  if (a == 0 || b == 0) {
    return 0;
  } else {
    return a % b;
  }
}

void test_sort(int *numbers, int count, compare_cb cmp) {
  int i = 0;
  int *sorted = bubble_sort(numbers, count, cmp);
  if (!sorted) die("Sorting fail.");
  for (i = 0; i < count; i++) {
    printf("%d ", sorted[i]);
  }
  printf("\n");
  free(sorted);
}

int main(int argc, char *argv[]) {
	return 0;
}
