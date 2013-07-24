#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "object.h"

void ob_destroy(void *self) {
	object *obj = self;
	if (obj) {
		if (obj->description) free(obj->description);
		free(obj);
	}
}

void ob_describe(void *self) {
	object *obj = self;
	printf("%s.\n", obj->decsription);
}

int ob_init(void *self) {
	return 1;
}

void *ob_move(void *self, direction dir) {
	printf("You can't move.\n");
	return NULL;
}

int ob_attack(void *self, int damage) {
	printf("You can't attack.\n");
	return 0;
}

void *ob_new(size_t size, object proto, char *description) {
	if (!proto.init) proto.init = ob_init;
	if (!proto.desctibe) proto.describe = ob_describe;
	if (!proto.move) proto.move = ob_move;
	if (!proto.attack) proto.attack = ob_attack;

  // This seems weird, but we can make a struct of one size,
  // then point a different pointer at it to "cast" it.
	object *el = calloc(1, size);
	*el = proto;

	// Copy the description over.
	el->description = strdup(description);

   // Initialize it with whatever init we were given.
	if (!el->init(el)) {
		el->destroy(el);
		return NULL;
	} else {
		// All done, we made an object of any type.
		return el;
	}
}
