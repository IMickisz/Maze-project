#ifndef HEADER_H
#define HEADER_H

/* header files */
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

/* macros */
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800
#define TEX_COUNT 6
#define TEX_WIDTH 64
#define TEX_HEIGHT 64
#define MAP_WIDTH 24
#define MAP_HEIGHT 24
#define MAP_CHAR_COUNT 1275

/* structure */
/**
 * struct point_s - data structure for XY point coordinates of type double
 * @x: X coordinate
 * @y: Y coordinate
 * Description: struct point
 */
typedef struct point_s
{
	double x;
	double y;
} point_t;

/* global variables */
extern SDL_Window *window;     /* render window */
extern SDL_Renderer *renderer; /* window renderer */
extern SDL_Texture *texture;   /* texture */
extern uint32_t buffer[SCREEN_HEIGHT][SCREEN_WIDTH]; /* buffer for textures */
extern uint32_t tiles[TEX_COUNT][TEX_HEIGHT][TEX_WIDTH]; /* array of textures */
extern point_t pos;            /* X and Y start position */
extern point_t dir;            /* initial direction vector */
extern point_t plane;          /* camera plane */
extern double time;            /* time of current frame */

/* functions */
int *parseMap(char *filename, int *map);
void loadTextures(char *mapName);

bool initSDL(void);
void updateRenderer(bool textured);
void closeSDL(void);

void input(int *maze);
bool quit(void);

void raycaster(int *maze, bool textured);
void renderWalls(int *maze, SDL_Point map, point_t rayPos, point_t rayDir, double distToWall, int x, int side, bool textured);
void renderBGFlat(void);
void renderBGTex(SDL_Point map, point_t rayDir, double distToWall, double wallX, int drawEnd, int x, int side);

#endif /* HEADER_H */
