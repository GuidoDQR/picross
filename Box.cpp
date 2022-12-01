#include "box.h"

void Label::DrawLabel(){
	DrawText(text,position.x, position.y, fontSize, colorText);
}

void Label::DrawLabel(Vector2 windowPos){

	DrawText(text, position.x + windowPos.x, position.y + windowPos.y, fontSize, colorText);
}

Window::Window(){
	position = {10, 100};
	size = {130, 120};
	windowBox = {position.x, position.y, size.x, size.y};
	colorBox = RED;
	labelSize = 0;
	
}

Window::~Window(){

}

void Window::newLabel(const char* newText, Vector2 labelPos){
	labelSize++;

	label.resize(labelSize);

	label[labelSize-1].text = newText;
	label[labelSize-1].position = labelPos;
}

void Window::newButton(float newxPos, float newyPos, float width, float newHeight){
	buttonSize++;

	button.resize(buttonSize);
	button[buttonSize-1].SetBoton(newxPos + position.x, newyPos + position.y, width, newHeight);
}

void Window::Position(Vector2 newposition){
	position = newposition;
	windowBox = {position.x, position.y, size.x, size.y};
}

void Window::sizeBox(Vector2 newsize){
	size = newsize;
	windowBox = {position.x, position.y, size.x, size.y};
}

void Window::DrawBox(){
	DrawRectangleRec(windowBox,colorBox);
	for(unsigned int i=0;i<labelSize;i++){
		
		//cout << i<< ": " << label[i].text << endl;
		label[i].DrawLabel(position);

	}
}
