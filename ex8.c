#include <stdio.h>

int main(int argc, char **argv) {
  int areas[] = {10, 12, 13, 14, 20};
  char name[] = "Zed";
  char full_name[] = {'Z', 'e', 'd', ' ', 'A', '.', ' ', 'S', 'h', 'a', 'w', '\0'};

  // WARNING: On some systems you may have to change the
  // %ld in this code to a %u since it will use unsigned ints
  printf("The size of an int: %ld.\n", sizeof(int));
  printf("The size of areas: %ld.\n", sizeof(areas) / sizeof(int));

  areas[0] = 1000;
  areas[1] = name[0];

  printf("The first area is %d, the 2nd %d etc.\n", areas[0], areas[1]);

  printf("The size of a char: %ld.\n", sizeof(char));
  printf("The size of name: %ld.\n", sizeof(name));
  printf("The number of characters: %ld.\n", sizeof(name) / sizeof(char));

  printf("The size of full_name: %ld.\n", sizeof(full_name));
  printf("The number of characters: %ld.\n", sizeof(full_name) / sizeof(char));

  name[0] = full_name[0] = 'J';

  printf("Name: %s Full name: %s.\n", name, full_name);
  
  return 0;
}

/*

EXTRA CREDIT:

1. Try assigning to elements in the areas array with areas[0] = 100; and similar.

Included above.

2. Try assigning to elements of name and full_name.

Included above.

3. Try setting one element of areas to a character from name.

Included above.

4. Go search online for the different sizes used for integers on different CPUs.

*/

