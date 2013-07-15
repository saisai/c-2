#include <stdio.h>

int main(int argc, char *argv[]) {
	int i = 0;

	if (argc == 1) {
		printf("You don't have any arguments, weakling!\n");
	} else if (argc == 2) {
	printf("You only have one argument, fundamentalist!\n");
	} else if (argc > 1 && argc < 4) {
	printf("Here they are...\n");
	for (i = 1; i < argc; i++) {
		printf("%s ", argv[i]);
	}
	printf("\n");
	} else {
	printf("You have too many arguments, flake!\n");
	}

	for (i = 1; i < argc; i++) {
		if (i == 10) break;
		printf("Arg %d: %s\n", i, argv[i]);
	}

	return 0;
}

/* EXTRA CREDIT:

1. You were briefly introduced to &&, which does an "and" comparison, 
so go research online the different "boolean operators".

Yep.

2. Write a few more test cases for this program to see what you can come up with.

Added check to see whether no arguments were passed in.

3. Go back to Exercises 10 and 11, and use if-statements to make the loops 
exit early. You'll need the break statement to do that. Go read about it.

Added the break statement in here instead.

4. Is the first test really saying the right thing? To you the "first argument"
isn't the same first argument a user entered. Fix it.

The first element in argv is the current program.

*/
