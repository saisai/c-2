#include <stdio.h>

int main(int argc, char *argv[]) {
  int distance = 100;
  float power = 2.345f;
  double super_power = 56789.4532;
  char initial = 'A';
  char first_name[] = "Zed";
  char last_name[] = "Shaw";

  printf("You are %d miles away.\n", distance);
  printf("You have %.3f levels of power.\n", power);
  printf("You have %.4f awesome super powers.\n", super_power);
  printf("I have an initial %c.\n", initial);
  printf("I have a first name %s.\n", first_name);
  printf("I have a last name %s.\n", last_name);
  printf("My whole name is %s %c 5%s.\n", first_name, initial, last_name);

  printf("100 in hex is %x.\n", distance);
  printf("100 in octal is %o.\n", distance);
  printf("Distance is stored in address %p.\n", &distance);
  printf("Power in scientific notation: %e.\n", power);
  printf("Power in alternative float format: %g.\n", power);
  printf("%s.\n", ""); 

  return 0;
}

/*

EXTRA CREDIT

1. Come up with other ways to break this C code by changing the printf, then fix them.

Done.

2. Go search for "printf formats" and try using a few of the more exotic ones.

Done in a previous exercise and some demonstrated here.

3. Research how many different ways you can write a number. Try octal, 
hexadecimal, and others you can find.

Included above.

4. Try printing an empty string that's just "".

Included above.

*/
