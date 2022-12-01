#ifndef BOX_H
#define BOX_H

#include "raylib.h"
#include "Boton.h"
#include <vector>
#include <string.h>
#include <algorithm>
 
struct Label{
	const char* text;
	Vector2 position;
	Color colorText = BLACK;
	int fontSize = 20;
	

	void DrawLabel();
	void DrawLabel(Vector2);

};

struct Window{
private:
	Vector2 position;
	Vector2 size;
	
	
public:
	Rectangle windowBox;
	Color colorBox;
	unsigned int labelSize = 0;
	unsigned int buttonSize = 0;
	std::vector<Label> label;
	std::vector<Boton> button;

	Window();
	~Window();

	void Position(Vector2);
	void sizeBox(Vector2 newsize);
	void newLabel(const char*, Vector2);
	void newButton(float, float, float, float);
	void DrawBox();
};
#endif