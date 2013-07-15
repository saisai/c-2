#include <stdio.h>
#include <ctype.h>
#include <string.h>

void pp(char *arg) {
	int i = 0;
	int len = strlen(arg);
	for (i = 0; i < len; i++) {
		char ch = arg[i];
		if (isalpha(ch) || isblank(ch)) {
			printf("'%c' == %d ", ch, ch);
		}
	}
	printf("\n");
}

void print_args(int argc, char *argv[]) {
  int i = 0;
  for (i = 1; i < argc; i++) {
    pp(argv[i]);
  }
}

int main(int argc, char *argv[]) {
	print_args(argc, argv);
	return 0;
}

/*

NOTES:

1. I re-ordered the function definitions here so I didn't have to add
declarations in advance.

2. I'm also passing char *arg to pp as it's idiomatic C.

EXTRA CREDIT:

1, Rework these functions so that you have fewer functions. For example, do 
you really need can_print_it?

Eliminated printable.

2. Have print_arguments figure how long each argument string is using the 
strlen function, and then pass that length to print_letters. Then, 
rewrite print_letters so it only processes this fixed length and doesn't 
rely on the '\0' terminator. You will need the #include <string.h> for this.

Included above.

4. Use man to lookup information on isalpha and isblank. Use the other 
similar functions to print out only digits or other characters.

Yep.

5. Go read about how different people like to format their functions. Never 
use the "K&R syntax" as it's antiquated and confusing, but understand what 
it's doing in case you run into someone who likes it.

That's some ugly antiquated shit right there.

*/
