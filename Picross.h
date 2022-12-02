#ifndef PICROSS_H
#define PICROSS_H
#include <raylib.h>
#include "Boton.h"

enum GameState{
	menu,
	game,
	editor
} ;

const int screenWidth = 800;
const int screenHeight = 640;
const int maxTiles = 10;
extern Vector2 mouse;
extern Color colorSelected;
extern int   colorPos;
extern Boton (*tile)[maxTiles];
extern Boton* colorMenu;
extern GameState gameState;
extern bool loadedPicross;
extern bool loadedFile;
const int MAX_INPUT_CHARS = 64;
extern char file[MAX_INPUT_CHARS]; 
#endif