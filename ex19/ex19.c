#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ex19.h"

int monster_attack(void *self, int damage) {
  monster *monster = self;
  printf("You attack %s!\n", monster->_(description));
  monster->hit_points -= damage;
  if (monster->hit_points > 0) {
  	printf("It lives!\n");
  	return 0;
  } else {
  	printf("It dies!\n");
  	return 1;
  }
}

int monster_init(void *self) {
	monster *monster = self;
	monster->hit_points = 10;
	return 1;
}

object monsterProto = { .init = monster_init, .attack = monster_attack };

void *room_move(void *self, direction dir) {
	room *room = self;
	room *next = NULL;

	if (dir == NORTH && room->north) {
		printf("Northwards into: \n");
		next = room->north;
	} else if (dir == SOUTH && room->south) {
		printf("Southwards into: \n");
		next = room->south;
	} else if (dir == EAST && room->east) {
		printf("Eastwards into: \n");
		next = room->east;
	} else if (dir == WEST && room->west) {
		printf("Westwards into: \n");
		next = room->west;
	} else {
		printf("No way jose!\n");
		next = NULL;
	}

	if (next) {
		next->_(describe)(next);
	}
	return next;
}

int room_attack(void *self, int damage) {
	room *room = self;
	monster *monster = room->bogeyman;

	if (monster) {
		monster->_(attack)(monster, damage);
		return 1;
	} else {
		printf("You flail!\n");
		return 0;
	}
}

object roomProto = { .move = room_move, .attack = room_attack };

void *map_move(void *self, direction dir) {
	map *map = self;
	room *location = map->location;
	room *next = NULL;
	next = location->_(move)(location, direction);
	if (next) {
		map->location = next;
	}
	return next;
}

int map_attack(void *self, int damage) {
	map *map = self;
	room *location = map->location;
  return location->_(attack)(location, damage);
}

int main(int argc, char *argv[]) {
  printf("loaded.\n");
  return 0;
}
