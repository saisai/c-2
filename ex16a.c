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

struct Person create(char *name, int age, int height, int weight) {
	struct Person peep;
	
	peep.name = name;
	peep.age = age;
	peep.height = height;
	peep.weight = weight;
	
	return peep;
}

void pp(struct Person peep) {
	printf("Name: %s\n", peep.name);
	printf("Age: %d\n", peep.age);
	printf("Height: %d\n", peep.height);
	printf("Weight: %d\n", peep.weight);
}

int main(int argc, char *argv[]) {

  struct Person dave = create("dave", 43, 100, 100);
  struct Person ray = create("ray", 39, 120, 80);

  pp(dave);
  pp(ray);

  dave.age = 44;
  ray.age = 40;

  pp(dave);
  pp(ray);

  return 0;
}
