#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[]) {
  int bugs = 100;
  double bug_rate = 1.2;

  printf("You have %d bugs at the imaginary rate of %f.\n", bugs, bug_rate);

  long universe_of_defects = 1L * 1024L * 1024L * 1024L;
  printf("The entire universe has %ld defects.\n", universe_of_defects);

  double expected_bugs = bugs * bug_rate;
  printf("You are expected to have %f bugs.\n", expected_bugs);

  double part_of_universe = expected_bugs / universe_of_defects;
  printf("That is only a %e portion of the universe.\n", part_of_universe);

  char null_byte = '\0';
  int care_percentage = bugs * null_byte;
  printf("Which means you should care %d%%.\n", care_percentage);

  printf("Number of bits in a char: %d.\n", CHAR_BIT);
  printf("Maximum value for a signed char: %d.\n", SCHAR_MAX);
  printf("Minimum value for a signed char: %d.\n", SCHAR_MIN);
  printf("Maximum value for an unsigned char: %d.\n", UCHAR_MAX);
  printf("Maximum value for a char: %d.\n", CHAR_MAX);
  printf("Minimum value for a signed char: %d.\n", CHAR_MIN);

  printf("Maximum value for an unsigned short: %d.\n", USHRT_MAX);
  printf("Maximum value for a short: %d.\n", SHRT_MAX);
  printf("Minimum value for a short: %d.\n", SHRT_MIN);

  printf("Maximum value for an unsigned int: %d.\n", UINT_MAX);
  printf("Maximum value for an int: %d.\n", INT_MAX);
  printf("Minimum value for an int: %d.\n", INT_MIN);

  printf("Maximum value for an unsigned long: %ld.\n", ULONG_MAX);
  printf("Maximum value for a long: %ld.\n", LONG_MAX);
  printf("Minimum value for a long: %ld.\n", LONG_MIN);

  printf("Maximum value for an unsigned long long: %lld.\n", ULLONG_MAX);
  printf("Maximum value for a signed long long: %lld.\n", LLONG_MAX);
  printf("Minimum value for a signed long long: %lld.\n", LLONG_MIN);

  printf("Maximum value for a size_t: %ld.\n", SIZE_T_MAX);

  return 0;
}

/*

EXTRA CREDIT

1. Make the number you assign to universe_of_defects various sizes until 
you get a warning from the compiler.

I did that, and then pulled in limits.h to get the thresholds.

2. What do these really huge numbers actually print out?

Depends if they overflow or not.

3. Change long to unsigned long and try to find the number that makes 
that one too big.

Well, I kind of did that using limits.h.

4. Go search online to find out what unsigned does.

I already knew that shizzle. In short, it indicates whether a number is
positive or negative.

5. Try to explain to yourself (before I do in the next exercise) why you 
can multiply a char and an int.

Simply because a char IS an int.

*/
