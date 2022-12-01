#ifndef PICROSS_H
#define PICROSS_H
#include <raylib.h>
#include "Boton.h"
const int screenWidth = 800;
const int screenHeight = 640;
const int maxTiles = 10;
extern Vector2 mouse;
extern Color colorSelected;
extern int   colorPos;
extern Boton (*tile)[maxTiles];
extern Boton* colorMenu;

#endif