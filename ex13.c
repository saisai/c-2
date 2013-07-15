#include <stdio.h>
#define UPPER_LOW 65
#define UPPER_HIGH 90
#define CASE_OFFSET 32

int is_uppercase(char ch) {
  return (ch >= UPPER_LOW && ch <= UPPER_HIGH);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("ERROR: You need at least one argument.\n");
    return 1;
  }

  int i = 0;
  int j = 0;
  char letter;
  char original_letter;

  for (j = 1; j < argc; j++) {
  
    for (i = 0; argv[j][i] != '\0'; i++) {
      letter = original_letter = argv[j][i];
      if (is_uppercase(letter)) letter += CASE_OFFSET;  
      
      switch(letter) {
        case 'a':
          printf("%d: %c\n", i, original_letter);
          break;

        case 'e':
          printf("%d: %c\n", i, original_letter);
          break;

        case 'i':
          printf("%d: %c\n", i, original_letter);
          break;

        case 'o':
          printf("%d: %c\n", i, original_letter);
          break;

        case 'u':
          printf("%d: %c\n", i, original_letter);
          break;

        case 'y':
          if (i > 2) {
            printf("%d: %c\n", i, original_letter);
          }
          break;

        default:
          printf("%d: %c is not a vowel\n", i, letter);
      }
    }
  }

  return 0;
}

/*

EXTRA CREDIT:

1. Write another program that uses math on the letter to convert it to 
lowercase, and then remove all the extraneous uppercase letters in the switch.

See the combination of functions and constants above.

2. Use the ',' (comma) to initialize letter in the for-loop.

Did so then took it back out as it didn't make much sense.

3. Make it handle all of the arguments you pass it with yet another for-loop.

Included above.

4. Convert this switch-statement to an if-statement. Which do you like better?

The switch statement.

5. In the case for 'Y' I have the break outside the if-statement. What's the 
impact of this and what happens if you move it inside the if-statement. Prove 
to yourself that you're right.

It breaks at the wrong level.

*/

