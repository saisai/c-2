#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
  char *name;
  int age;
  int height;
  int weight;
};

struct Person *create(char *name, int age, int height, int weight) {
	struct Person *peep = malloc(sizeof(struct Person));
	
	assert(peep != NULL);
	
	peep->name = strdup(name);
	peep->age = age;
	peep->height = height;
	peep->weight = weight;
	
	return peep;
}

void destroy(struct Person *peep) {
	assert(peep != NULL);

	free(peep->name);
	free(peep);
}

void pp(struct Person *peep) {
	printf("Name: %s\n", peep->name);
	printf("Age: %d\n", peep->age);
	printf("Height: %d\n", peep->height);
	printf("Weight: %d\n", peep->weight);
}

int main(int argc, char *argv[]) {

  struct Person *dave = create("dave", 43, 100, 100);
  struct Person *ray = create("ray", 39, 120, 80);

  pp(dave);
  pp(ray);

  dave->age = 44;
  ray->age = 40;

  pp(dave);
  pp(ray);

  destroy(dave);
  destroy(ray);

	return 0;
}

/*

EXTRA CREDIT:

In this exercise I want you to attempt something difficult for the extra 
credit: Convert this program to not use pointers and malloc. This will be 
hard, so you'll want to research the following:

How to create a struct on the stack, which means just like you've been making 
any other variable.

How to initialize it using the x.y (period) character instead of the x->y syntax.

How to pass a structure to other functions without using a pointer.

Included in ex16a.character

*/
