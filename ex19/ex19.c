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

int map_init(void *self) {
	map *map = self;
	room *hall = NEW(room, "The great hall.");
	room *throne = NEW(room, "The throne room.");
	room *arena = NEW(room, "The arena, with the minotaur.");
	room *kitchen = NEW(room, "The kitchen - you now have a blade.");

	hall->north = throne;
	throne->west = arena;
	throne->east = kitchen;
	throne->south = hall;

	arena->east = throne;
	kitchen->west = throne;

	map->start = hall;
	map->location = hall;

	return 1;
}

object mapProto = { .init = map_init, .move = map_move, .attack = map_attack };

int process_input(map *game) {
	printf("\n> ");
	char ch = getchar();
	getchar(); // EAT ENTER.
	int damage = rand() % 4;

	switch(ch) {
		case -1:
		  printf("Loser!\n");
		  return 0;
		  break;
		case 'n':
		  game->_(move)(game, NORTH);
		  break;
		case 's':
		  game->_(move)(game, SOUTH);
		  break;
		case 'e':
		  game->_(move)(game, EAST);
		  break;
		case 'w':
		  game->_(move)(game, WEST);
		  break;
		case 'a':
		  game->_(attack)(game, damage);
		  break;
		case 'l':
		  printf("You can go: \n");
		  if (game->location->north) printf("NORTH\n");
		  if (game->location->south) printf("SOUTH\n");
		  if (game->location->east) printf("EAST\n");
		  if (game->location->west) printf("WEST\n");
      break;
    default:
      printf("What does %d mean?\n", ch);
      break;
	}
	return 1;
}

int main(int argc, char *argv[]) {

  srand(time(NULL));
  map *game = NEW(map, "The Hall Of The Minotaur");

  printf("You enter the ");
  game->location->_(describe)(game->location);

  while(process_input(game)) {

  }

  return 0;
}
