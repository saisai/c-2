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

int main(int argc, char *argv[]) {

  struct Person *who = create("dave", 43, 100, 100);
  printf("Person: %s\n", who->name);

	return 0;
}