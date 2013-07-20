#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

typedef struct {
  int id;
  int set;
  char name[MAX_DATA];
  char email[MAX_DATA];
} address;

typedef struct {
  address rows[MAX_ROWS];
} db;

typedef struct {
  FILE *file;
  db *db;
} connection;

address *address_create(int id, char *name, char *email) {
	address *addr = malloc(sizeof(address));

	addr->id = id;
	addr->set = 0;
	memcpy(addr->name, name, strlen(name));
	memcpy(addr->email, email, strlen(email));

	return addr;
}

void address_print(address *addr) {
	printf("Address: %d %s (%s)\n", addr->id, addr->name, addr->email);
}

void address_destroy(address *addr) {
	free(addr);
}

int main(int argc, char *argv[]) {
	address *addr = address_create(100, "buddhamagnet", "buddhamagnet@gmail.com");
	address_print(addr);
	address_destroy(addr);
	return 0;
}

/* NOTES

According to many, this exercise is where many people get stuck.

To prepare, I started by adding some functions to create, display and
delete addresses, and also made use of typedef (mainly so I didn't have
to keep typing struct Address everywhere) and also discovered the use of
memcpy to copy string arguments into struct values.

Thus prepared, I enter the field of battle.

EXTRA CREDIT:



*/
