#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ex19.h"

int monster_attack(void *self, int damage) {
  Monster *monster = self;
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
	Monster *monster = self;
	monster->hit_points = 10;
	return 1;
}

Object MonsterProto = { .init = monster_init, .attack = monster_attack };

void *room_move(void *self, Direction dir) {
	Room *room = self;
	Room *next = NULL;

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
	Room *room = self;
	Monster *monster = room->bogeyman;

	if (monster) {
		monster->_(attack)(monster, damage);
		return 1;
	} else {
		printf("You flail!\n");
		return 0;
	}
}

Object RoomProto = { .move = room_move, .attack = room_attack };

void *map_move(void *self, Direction dir) {
	Map *map = self;
	Room *location = map->location;
	Room *next = NULL;
	next = location->_(move)(location, dir);
	if (next) {
		map->location = next;
	}
	return next;
}

int map_attack(void *self, int damage) {
	Map *map = self;
	Room *location = map->location;
  return location->_(attack)(location, damage);
}

int map_init(void *self) {
	Map *map = self;
	Room *hall = NEW(Room, "The great hall.");
	Room *throne = NEW(Room, "The throne room.");
	Room *arena = NEW(Room, "The arena, with the minotaur.");
	Room *kitchen = NEW(Room, "The kitchen - you now have a blade.");

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

Object MapProto = { .init = map_init, .move = map_move, .attack = map_attack };

int process_input(Map *game) {
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
     case 'q':
       printf("Bye!\n");
       exit(1);
      default:
      printf("What does %c mean?\n", ch);
      break;
	}
	return 1;
}

int main(int argc, char *argv[]) {

  srand(time(NULL));
  Map *game = NEW(Map, "The Hall Of The Minotaur");

  printf("You enter the ");
  game->location->_(describe)(game->location);

  while(process_input(game)) {

  }

  return 0;
}
