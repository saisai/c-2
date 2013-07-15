#include <stdio.h>

int main(int argc, char *argv[]) {
	int i = 1;
	while (i < argc) {
	  printf("arg %d: %s\n", i, argv[i]);
	  i++;
	}

	i = argc - 1;
	while (i > 0) {
	  printf("arg %d: %s\n", i, argv[i]);
	  i--;
	}

	char *states[] = {"California", "Oregon", "Washington", "Texas"};
	int num_states = 4;
	i = 0;
	while (i < num_states) {
	  printf("state %d: %s\n", i + 1, states[i]);
	  i++;
	}

	i = 0;
	while (i < num_states && i < argc - 1) {
	  states[i] = argv[i + 1];
	  i++;
	}

	i = 0;
	while (i < num_states) {
	  printf("state %d: %s\n", i + 1, states[i]);
	  i++;
	}

	return 0;
}

/*

EXTRA CREDIT:

1. Make these loops count backward by using i-- to start at argc and 
count down to 0. You may have to do some math to make the array 
indexes work right.

Included above.

2. Use a while loop to copy the values from argv into states.

Included above.

3. Make this copy loop never fail such that if there's too many 
argv elements it won't put them all into states.

We use the num_states variable above to make sure that never happens.

4. Research if you've really copied these strings. The answer may 
surprise and confuse you though.

Not really surprised.

*/
