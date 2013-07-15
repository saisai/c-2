#include <stdio.h>
#define UPPER_LOW 65
#define UPPER_HIGH 90
#define CASE_OFFSET 32

int is_uppercase(char ch) {
  return (ch >= UPPER_LOW && ch <= UPPER_HIGH);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("ERROR: You need one argument.\n");
    // this is how you abort a program
    return 1;
  }

  int i = 0;

  for (i = 0; argv[1][i] != '\0'; i++) {
    char letter;
    char original_letter;
    letter = original_letter = argv[1][i];
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

  return 0;
}
