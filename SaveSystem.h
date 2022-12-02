#ifndef SAVESYSTEM_H
#define SAVESYSTEM_H
#include "Boton.h"
#include "Picross.h"


void SavePicross(Boton (*newtile)[maxTiles], char* nameFile);
void LoadPicross(Boton (*newtile)[maxTiles], char* nameFile);

#endif