#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>

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

void die(const char *message) {
	if (errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}
	exit(1);
}

address *address_create(int id, char *name, char *email) {
	address *addr = malloc(sizeof(address));

	addr->id = id;
	addr->set = 0;
	memcpy(addr->name, name, strlen(name));
	memcpy(addr->email, email, strlen(email));

	return addr;
}

void address_print(address *addr) {
	printf("%d %s (%s)\n", addr->id, addr->name, addr->email);
}

void address_destroy(address *addr) {
	free(addr);
}

void db_load(connection *conn) {
	int rc = fread(conn->db, sizeof(db), 1, conn->file);
	if (rc != 1) {
		die("Failed to load database.");
	}
}

connection *db_open(const char *filename, char mode) {
	connection *conn = malloc(sizeof(connection));
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
	return conn;
}

void db_close(connection *conn) {
	if (conn) {
		if (conn->file) fclose(conn->file);
		if (conn->db) free(conn->db);
		free(conn);
	}
}

void db_write(connection *conn) {
	rewind(conn->file);
}
int main(int argc, char *argv[]) {

	int i;

  // Exercise address creation, display and deletion.
	address *addr = address_create(100, "buddhamagnet", "buddhamagnet@gmail.com");
	address_print(addr);
	address_destroy(addr);

  // Demonstrate address for connection.
	connection *conn = db_open("db.dat", 'c');
	printf("Just created a connection at address %p.\n", conn);
	printf("The connection's database is stored at address: %p.\n", conn->db);
	printf("The connection's database contains %ld rows (addresses).\n", sizeof(conn->db->rows) / sizeof(address));

  // Demonstrate addresses of database rows.
	for (i = 0; i < MAX_ROWS; i++) {
		printf("Address of record at row %d: %p.\n", i + 1, &conn->db->rows[i]);
		sleep(1);
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



*/
