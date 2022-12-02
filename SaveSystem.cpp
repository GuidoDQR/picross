#include "SaveSystem.h"
#include <iostream>
#include <fstream>
#include <iomanip>

void SavePicross(Boton (*newtile)[maxTiles], char* nameFile){
	std::ofstream file;
	file.open(nameFile);
	for(int i=0;i<maxTiles;i++){
		for(int j=0;j<maxTiles;j++){
			file << std::setw(3) << (int)newtile[i][j].GetColor().r << " ";
			file << std::setw(3) << (int)newtile[i][j].GetColor().g << " ";
			file << std::setw(3) << (int)newtile[i][j].GetColor().b << " ";
		}
	}
    file.close();
    std::cout<< "Guardado\n";
}

void LoadPicross(Boton (*newtile)[maxTiles], char* nameFile){
	std::ifstream file;
	file.open("savefile.txt");
	Color newColor;
	int red;
	int green;
	int blue;
	
	newColor.a = 255;
	for(int i=0;i<maxTiles;i++){
		for(int j=0;j<maxTiles;j++){
			//file.get(red,3);
			file >> red;
			file >> green;
			file >> blue;
			//newColor.r = static_cast<unsigned char>(red); 
			newColor.r = red;
			newColor.g = green;
			newColor.b = blue;
			newtile[i][j].SetColor(newColor);
			//std::cout << "R: " << (int)newColor.r << " G: " << (int)newColor.g << " B: " <<(int) newColor.b << "\n";
		}
	}
	file.close();
	std::cout<< "Cargado\n";
}