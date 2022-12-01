#ifndef RENDER_H
#define RENDER_H
#include <raylib.h>
#include "Picross.h"

extern int windowCounter;


void PanelColor();  // Dibuja los colores para seleccionar
void Game();		// Dibuja el modo de juego
void Editor();		// Dibuja la escena donde se pinta los cuadrados

void RenderInit();
void RenderGame();

#endif