#ifndef _object_h
#define _object_h

typedef enum {
  NORTH, SOUTH, EAST, WEST
} Direction;

typedef struct {
	char *description;
	int (*init)(void *self);
	void (*describe)(void *self);
	void (*destroy)(void *self);
	void *(*move)(void *self, Direction dir);
	int (*attack)(void *self, int damage);
} Object;

int ob_init(void *self);
void ob_destroy(void *self);
void ob_describe(void *self);
void *ob_move(void *self, Direction dir);
int ob_attack(void *self, int damage);
void *ob_new(size_t size, Object proto, char *description);

#define NEW(T, N) ob_new(sizeof(T), T##Proto, N)
#define _(N) proto.N

#endif
