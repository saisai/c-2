#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#define MAX_DATA 512
#define MAX_ROWS 100

typedef struct {
  int id;
  int set;
  char name[MAX_DATA];
  char email[MAX_DATA];
  char postcode[MAX_DATA];
} address;

typedef struct {
  address rows[MAX_ROWS];
} db;

typedef struct {
  FILE *file;
  db *db;
} connection;

static connection *conn;

void db_close();

void die(const char *message) {
	if (errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}
	if (conn != NULL) {
	  db_close();
	}
	exit(1);
}

address *address_create(int id, char *name, char *email, char *postcode) {

	address *addr = malloc(sizeof(address));

	addr->id = id;
	addr->set = 0;
	memcpy(addr->name, name, strlen(name));
	memcpy(addr->email, email, strlen(email));
	memcpy(addr->postcode, postcode, strlen(postcode));

	return addr;
}

void address_print(address *addr) {
	printf("%d %s (%s) resident at %s\n", addr->id, addr->name, addr->email, addr->postcode);
}

void address_destroy(address *addr) {
	free(addr);
}

void db_load() {
	int rc = fread(conn->db, sizeof(db), 1, conn->file);
	if (rc != 1) {
		die("Failed to load database.");
	}
}

void db_open(const char *filename, char mode) {
	conn = malloc(sizeof(connection));
	if (!conn) {
		die("Memory error.");
	}
	conn->db = malloc(sizeof(db));
	if (!conn->db) {
		die("Memory error");
	}
	if (mode == 'c') {
		conn->file = fopen(filename, "w");
	} else {
		conn->file = fopen(filename, "r+");
		if (conn->file) {
			db_load(conn);
		}
	}
	if (!conn->file) {
		die("Failed to open file.");
	}
}

void db_close() {
	if (conn) {
		if (conn->file) fclose(conn->file);
		if (conn->db) free(conn->db);
		free(conn);
	}
}

void db_write(c) {
	rewind(conn->file);
	int rc = fwrite(conn->db, sizeof(db), 1, conn->file);
	if (rc != 1) {
		die("Failed to write database.");
	}
	rc = fflush(conn->file);
	if (rc ==  1) {
		die("Cannot flush database.");
	}
}

void db_create() {
  int i = 0;
  for (i = 0; i < MAX_ROWS; i++) {
  	address addr = {.id = i, .set = 0};
  	conn->db->rows[i] = addr;
  }
}

void db_set(int id, const char *name, const char *email, const char *postcode) {

	address *addr = &conn->db->rows[id];
	if (addr->set) {
		die("Already set, delete it first.");
	}

  addr->set = 1;

  char *res = strncpy(addr->name, name, MAX_DATA);
  if (!res) {
  	die("Failed to copy name.");
  }
  res = strncpy(addr->email, email, MAX_DATA);
  if (!res) {
  	die("Failed to copy email.");
  }
  res = strncpy(addr->postcode, postcode, MAX_DATA);
  if (!res) {
  	die("Failed to copy postcode.");
  }
}

void db_get(int id) {
  address *addr = &conn->db->rows[id];

  if (addr->set) {
  	address_print(addr);
  } else {
  	die("ID is not set.");
  }
}

void db_delete(int id) {
	address addr = {.id = id, .set = 0};
	conn->db->rows[id] = addr;
}

void db_find(char *text) {
	int i = 0;
	int found = 0;
	db *db = conn->db;
	for (i = 0; i < MAX_ROWS; i++) {
		address *current = &db->rows[i];
		if (strcmp(text, current->name) == 0 || strcmp(text, current->email) == 0 || strcmp(text, current->postcode) == 0) {
			address_print(current);
			found = 1;
		}
	}
	if (found == 0) {
		printf("No matching records found.\n");
	}
}

void db_list() {
	int i = 0;
	db *db = conn->db;
	for (i = 0; i < MAX_ROWS; i++) {
		address *current = &db->rows[i];
		if (current->set) {
			address_print(current);
		}
	}
}

void db_iterate() {
	int i;
	// Demonstrate addresses of database rows.
	for (i = 0; i < MAX_ROWS; i++) {
	  printf("Address of record at row %d: %p.\n", i + 1, &conn->db->rows[i]);
		usleep(10000);
	}
}

int main(int argc, char *argv[]) {

	if (argc < 3) die("USAGE: ex17 <dbfile> <action> [params]");

	int i;
	int id = 0;
	char *filename = argv[1];
	char action = argv[2][0];

	db_open(filename, action);

	if (argv[2][0] != 'c' && argc > 3) id = atoi(argv[3]);
	if (id >= MAX_ROWS) die("There's not that many records.");

	switch (action) {
		case 'c':
		  db_create();
		  db_write();
		  break;
		case 'g':
		  if (argc != 4) die("Please supply an ID.");
		  db_get(id);
		  break;
		case 'i':
		  db_iterate();
		  break;
		case 'f':
		  if (argc != 4) die("Please supply a name to search on.");
		  db_find(argv[3]);
		  break;
		case 's':
		  if (argc != 7) die("Please supply an ID, name, email and postcode");
		  db_set(id, argv[4], argv[5], argv[6]);
		  db_write();
		  break;
		case 'd':
		  if (argc != 4) die("Please supply an ID to delete");
		  db_delete(id);
		  db_write();
		  break;
		case 'l':
		  db_list();
		  break;
		default:
		  die("Invalid action");
		  break;
	}
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

1. The die function needs to be augmented to let you pass the conn variable
so it can close it and clean up.

Don't like that approach. Don't like global variables that much either, but
a single connection shared between the functions makes sense so created it as
a static variable.

2. Change the code to accept parameters for MAX_DATA and MAX_ROWS, store them
in the db struct, and write that to the file, thus creating a database
that can be arbitrarily sized.

3. Add more operations you can do on the database, like find.

Rudimentary find function added.

4. Read about how C does it's struct packing, and then try to see why your file
is the size it is. See if you can calculate a new size after adding more fields.

5. Add some more fields to the address and make them searchable.

6. Write a shell script that will do your testing automatically for you by
running commands in the right order. Hint: Use set -e at the top of a bash
to make it abort the whole script if any command has an error.

7. Try reworking the program to use a single global for the database connection.
How does this new version of the program compare to the other one?

Already did that in step 1. I use global variables (very) sparingly, but in the case
of a shared connection it made sense.

*/
