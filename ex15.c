#include <stdio.h>

void pb() {
	printf("--------\n");
}

void iterate(int *array, int len) {
  int i;
  for (i = 0; i < len; i++) {
    printf("Element %d: %d.\n", i, *(array + i));
  }
}

int main(int argc, char *argv[]) {

	int ages[] = {23, 43, 12, 89, 2};
	char *names[] = {"Alan", "Frank", "Mary", "John", "Lisa"};
  
  int count = sizeof(ages) / sizeof(int);
  int i = 0;

  // Use standard array indices.
  for (i = 0; i < count; i++) {
  	printf("%s is %d years old.\n", names[i], ages[i]);
  }

  pb();

  // Set up pointers to the start of the arrays.
  int *current_age = ages;
  char **current_name = names;

  // Prove it.
  printf("Start of names array: %p Pointer address: %p.\n", &names[0], current_name);
  printf("Start of names array: %s.\n", *current_name);

  printf("Start of ages array: %p Pointer address: %p.\n", &ages[0], current_age);
  printf("Start of ages array: %d.\n", *current_age);

  pb();

  // Use function that takes a pointer.
  iterate(current_age, count);

  pb();

  // Now use the pointers to access the array elements.
  // To access the VALUE of whatever a pointer is pointing at, use *.
  for (i = 0; i < count; i++) {
    printf("%s is %d years old.\n", *(current_name + i), *(current_age + i));
  }

  pb();

  // And the addresses.
  for (i = 0; i < count; i++) {
    printf("Address at element %d (%s): %p.\n", i, *(current_name + i), current_name[i]);
  }

  pb();

  // We can also navigate the pointers like arrays.
  for (i = 0; i < count; i++) {
    printf("%s is %d years old.\n", current_name[i], current_age[i]);
  }

  pb();

  // This way leads to madness.
  for (current_name = names, current_age = ages; (current_age - ages) < count; current_name++, current_age++) {
    printf("%s is %d years old.\n", *current_name, *current_age);
  }

  pb();

  // Process command line arguments.
  char **args = argv;
  for (i = 1; i < argc; i++) {
    printf("Argument %d: %s.\n", i, *(args + i));
  }

  return 0;
}

/*

EXTRA CREDIT:

1. Rewrite all the array usage in this program so that it's pointers.

Done and reverted.

2. Rewrite all the pointer usage so they're arrays.

Done and reverted.

3. Go back to some of the other programs that use arrays and try to use pointers instead.

Yeah, easy.

4. Process command line arguments using just pointers similar to how you did names in this one.

Included above.

5. Play with combinations of getting the value of and the address of things.

Included above.

6. Add another for-loop at the end that prints out the addresses these pointers are 
   using. You'll need the %p format for printf.

Included above.

7. Rewrite this program to use a function for each of the ways you're printing out things. 
   Try to pass pointers to these functions so they work on the data. Remember you can 
   declare a function to accept a pointer, but just use it like an array.

Included above as the iterate function.

8. Change the for-loops to while-loops and see what works better for which kind of pointer usage.

Done and reverted.

*/
