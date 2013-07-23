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

void invalid_function() {
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

void dump_callback(compare_cb cmp) {
  unsigned char *data = (unsigned char *)cmp;
  int i;
  for (i = 0; i < 25; i++) {
    printf("%02x:", data[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  if (argc < 2) die("USAGE: ex18 4 3 1 5 6");

  int count = argc - 1;
  int i = 0;
  char **inputs = argv + 1;
  int *numbers = malloc(count * sizeof(int));

  if (!numbers) die("Memory error.");

  for (i = 0; i < count; i++) {
    numbers[i] = atoi(inputs[i]);
  }

  test_sort(numbers, count, sorted_order);
  test_sort(numbers, count, reverse_order);
  test_sort(numbers, count, strange_order);
  test_sort(numbers, count, invalid_function);
  dump_callback(sorted_order);
  dump_callback(reverse_order);
  dump_callback(strange_order);

  free(numbers);

	return 0;
}

/*

HOW TO BREAK IT:

Instead of adding Zed's crazy function dump at the end of test_sorted, I decided to keep
that function clean and add a new function that takes a compare_cb and dumps it.

EXTRA CREDIT:

1. Get a hex editor and open up ex18, then find this sequence of hex digits that start a function to
see if you can find the function in the raw program.

Yep, as indicated by the results of dump_callback.

2. Find other random things in your hex editor and change them. Rerun your program and see what happens.
Changing strings you find are the easiest things to change.

The usual chaos.

3. Pass in the wrong function for the compare_cb and see what the C compiler complains about.

I pass in invalid_function above and get: warning: passing argument 3 of ‘test_sort’ from incompatible pointer type.

The program still runs and the numbers get passed through with no change.

4. Pass in NULL and watch your program seriously bite it. Then run Valgrind and see what that reports.

Segmentation fault, as expected.

5. Write another sorting algorithm, then change test_sorting so that it takes both an arbitrary
sort function and the sort function's callback comparison. Use it to test both of your algorithms.

*/

