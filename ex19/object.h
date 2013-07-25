#ifndef _object_h
#define _object_h

typedef enum {
  NORTH, SOUTH, EAST, WEST
} direction;

typedef struct {
	char *description;
	int (*init)(void *self);
	void (*describe)(void *self);
	void (*destroy)(void *self);
	void *(*move)(void *self, direction dir);
	int (*attack)(void *self, int damage);
} object;

int ob_init(void *self);
void ob_destroy(void *self);
void ob_describe(void *self);
void *ob_move(void *self, direction dir);
int ob_attack(void *self, int damage);
void *ob_new(size_t size, object proto, char *description);

#define NEW(T, N) ob_new(sizeof(T), T##proto, N)
#define _(N) proto.N

#endif
