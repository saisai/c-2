#include <stdio.h>

int main(int argc, char **argv) {

  int numbers[4] = {0};
  char name[4] = {'a'};

  // First, print them out raw.
  printf("numbers: %d %d %d %d.\n", numbers[0], numbers[1], numbers[2], numbers[3]);
  printf("name each: %c %c %c %c.\n", name[0], name[1], name[2], name[3]);
  printf("name: %s.\n", name);

  // Set up the numbers.
  numbers[0] = 1;
  numbers[1] = 2;
  numbers[2] = 3;
  numbers[3] = 4;

  // Set up the name.
  name[0] = 'Z';
  name[1] = 'e';
  name[2] = 'd';
  name[3] = '\0';

  printf("numbers: %d %d %d %d.\n", numbers[0], numbers[1], numbers[2], numbers[3]);
  printf("name each: %c %c %c %c.\n", name[0], name[1], name[2], name[3]);
  printf("name: %s.\n", name);

  // Another way to use name.
  char *alias = "Zed";
  printf("alias each: %c %c %c %c.\n", alias[0], alias[1], alias[2], alias[3]);
  printf("alias: %s.\n", alias);

  // And an array of strings.
  char *strings[] = {"Dave", "is", "a", "twat"};
  printf("First string: %s.\n", strings[0]);
  printf("Last string: %s.\n", strings[3]);

  int i;

  for (i = 0; i < 3; i++) {
    numbers[i] = name[i];
  }

  printf("numbers: %d %d %d %d.\n", numbers[0], numbers[1], numbers[2], numbers[3]);
  printf("numbers: %c %c %c %c.\n", numbers[0], numbers[1], numbers[2], numbers[3]);
  printf("numbers: %x %x %x %x.\n", numbers[0], numbers[1], numbers[2], numbers[3]);
  printf("numbers: %o %o %o %o.\n", numbers[0], numbers[1], numbers[2], numbers[3]);

  return 0;
}

/*

EXTRA CREDIT:

1. Assign the characters into numbers and then use printf to print them a character at 
a time. What kind of compiler warnings did you get?

None, as ints and chars are interchangeable.

2. Do the inverse for name, trying to treat it like an array of int and print it out 
one int at a time. What does Valgrind think of that?

If you did that, you'd get the ASCII value for each char, as already demonstrated above.

3. How many other ways can you print this out?

Printed the modified numbers array values in  integer, hexadecimal and octal formats above.

4. If an array of characters is 4 bytes long, and an integer is 4 bytes long, then can 
you treat the whole name array like it's just an integer? How might you accomplish this 
crazy hack?

5. Take out a piece of paper and draw out each of these arrays as a row of boxes. Then 
do the operations you just did on paper to see if you get them right.

You'll have to take my work for it.

6. Convert name to be in the style of another and see if the code keeps working.

Yep.

*/
