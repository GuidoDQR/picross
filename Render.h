#ifndef RENDER_H
#define RENDER_H
#include <raylib.h>
#include "Picross.h"
#include "Box.h"

extern int windowCounter;
extern bool showText; 
extern int letterCount;
bool SetNameFile(char* nameFile);

void Menu();
void PicrossScene();
void Game();		// Dibuja el modo de juego
void PanelColor();  // Dibuja los colores para seleccionar
void Editor();		// Dibuja la escena donde se pinta los cuadrados

void RenderInit();
void RenderGame();

#endif