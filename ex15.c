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
  printf("Start of ages array: %p Pointer address: %p.\n", &ages[0], current_age);


  return 0;

}