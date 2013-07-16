#include <stdio.h>

void pb() {
	printf("--------\n");
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

  // Now use the pointers to access the array elements.
  // To access the VALUE of whatever a pointer is pointing at, use *.
  for (i = 0; i < count; i++) {
    printf("%s is %d years old.\n", *(current_name + i), *(current_age + i));
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

  return 0;
}