#include "Boton.h"


bool Boton::mouseOver;
int  Boton::countBoton = 0;
Boton::Boton(){
    id = countBoton;
    mouseOver= false;
    countBoton++;
}

Boton::~Boton(){ 
    if(texture.mipmaps != 0){
         UnloadTexture(texture);
    }
}

void Boton::SetBoton(float X, float Y, float width, float height){
    shape = {X,Y,width,height}; 

    totalWidth = X + width;
    totalHeight = Y + height;
}

void Boton::SetBoton(float X, float Y, float width, float height, int newLayer){
    shape = {X,Y,width,height}; 

    totalWidth = X + width;
    totalHeight = Y + height;

    layer = newLayer;
}

int Boton::getLayer(){ return layer; }

void Boton::setLayer(int newLayer){ layer = newLayer; }

bool Boton::MouseOverBoton(Vector2 mouse){
    //botonOver = false;
    botonOver = CheckCollisionPointRec(mouse, shape);
    /*if(mouse.x >= shape.x && mouse.x <= totalWidth && mouse.y >= shape.y && mouse.y <= totalHeight){
        botonOver = true;
        return true;
    }*/
    /*if(mouseOver == true){
        mouseOver = false;
    }*/
    //return false;
    return botonOver;
}

bool Boton::BotonPressed(Vector2 mouse, int button){
    if(MouseOverBoton(mouse) == true && IsMouseButtonPressed(button)){     
        botonPress = true; 
        return true;
    }
    
    botonPress = false;
    
    return false;
}

// Verifica si el boton se mantiene presionado 
bool Boton::BotonDown(Vector2 mouse, int button){
    if((MouseOverBoton(mouse) == true && IsMouseButtonDown(button)) || ( botonPressDown == true && IsMouseButtonDown(button))){     
        botonPressDown = true; 
        return true;
    }
    botonPressDown = false;
    return false;
}

bool Boton::BotonReleased(){
    if(botonPress == false && botonPressDown == false){
        return true;
    }
    return false;
}

Rectangle Boton::GetShape(){ return shape; }

void Boton::setRec(Rectangle newRec){ recShape = newRec; }

void Boton::setShapeX(float newPosX){ shape.x = newPosX; totalWidth = shape.x + shape.width;}

void Boton::setShapeY(float newPosY){ shape.y = newPosY; totalHeight = shape.y + shape.height;}

void Boton::Draw(){ DrawRectangleRec(shape, colorForm); }

void Boton::DrawOutline(){ 
    //if(mouseOver == false){
       DrawRectangleLinesEx(shape, lineThick, colorOutline); 
    //   mouseOver = true;  
    //}
}

Color Boton::GetColor(){ return colorForm; }

void Boton::SetColor(Color newColor){ colorForm = newColor; }

void Boton::SetColorOutline(Color newColor){ colorOutline = newColor; }

void Boton::setTexture(const char* newImage){ texture = LoadTexture(newImage); }

void Boton::setTexture(const char* newImage, int imageValue){
    textureValue = imageValue;
    texture = LoadTexture(newImage);
}

void Boton::setTexture(Texture2D newTexture, int newTextureValue){
    textureValue = newTextureValue;
    texture = newTexture;
}

void Boton::drawTexture(){ DrawTexture(texture,shape.x,shape.y,WHITE); }

Texture2D Boton::getTexture(){ return texture; }

int Boton::getTextureValue(){ return textureValue; }

void Boton::Reset(){
    colorForm = RAYWHITE;
    botonPress = false;
}