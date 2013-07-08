#include <stdio.h>

int main() {
  int age = 10;
  int height = 72;

  printf("I am %d years old.\n", age);
  printf("I am %d inches tall.\n", height);

  return 0;
}

/*

ESCAPE CODES:

\a bell
\b backspace
\t horizontal tab
\n newline
\v vertical tab
\f form feed
\r carriage return
\" double quote
\' single quote
\\ backslash
\? question mark

FORMAT SEQUENCES:

%c character
%d integer
%e float, scientific notation
%f float, six digits of precision
%g float, up to six digits of precision
%ld long integer
%le double, scientifc notation
%lf double, six digits of precision
%lg double, up to six digits of precision
%lu unsigned long
%o octal number
%s string
%u unsigned
%x hexadecimal number
%X hexadecimal number


EXTRA CREDIT

1. Find as many other ways to break ex3.c as you can.

Done.

2. Run man 3 printf and read about the other '%' format characters you can use.
   These should look familiar if you used them in other languages (printf is
   where they come from).

Format sequences included above.

3. Add ex3 to your Makefile's all list. Use this to make clean all and build
  all your exercises so far.

The Makefile is already pretty sweet.

4. Add ex3 to your Makefile's clean list as well. Now use make clean will
   remove it when you need to.

As I said, my Makefile is better than that.

*/
