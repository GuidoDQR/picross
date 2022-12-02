#ifndef BOTON_H
#define BOTON_H

#include "raylib.h"

class Boton{
private:
    static int countBoton;
    
    int layer = 0;

    float totalWidth;
    float totalHeight;

    Color colorForm    = RAYWHITE;
    Color colorOutline = BLACK;
    
    
    Rectangle shape    = {0};
    Rectangle recShape = {0};

    Texture2D texture;
    int textureValue   = 0;

    static bool mouseOver; // Global Boton
 
public:
    int id;
    
    bool botonOver = false;  // Local Boton
    bool botonPress = false;
    bool botonPressDown = false;

    int   lineThick    = 2;

    Boton();  // Constructor
    ~Boton(); // Destructor

    // Inicializador
    void SetBoton(float X, float Y, float width, float height); // Iniciliza el boton
    void SetBoton(float X, float Y, float width, float newHeight, int newLayer);
    
    int getLayer();
    void setLayer(int newLayer);

    // Metodos del boton
    bool MouseOverBoton(Vector2 mouse); // Verifica si el mouse esta encima del boton
    bool BotonPressed(Vector2 mouse, int button);   // Verifica si el mouse presiono el boton
    bool BotonDown(Vector2 mouse, int button); // Verifica si el mouse mantiene presionado el boton
    bool BotonReleased(Vector2 mouse, int button); // Verifica que el boton no este presionado
    bool BotonReleased(); // Verifica que el boton no este presionado

    // Metodos de Rectangulo
    Rectangle GetShape();
    void setRec(Rectangle newRec);

    void setShapeX(float newPosX);
    void setShapeY(float newPosY);

    void Draw(); // Dibuja el boton 
    void DrawOutline();

    // Metodos del color
    Color GetColor(); // Devuelve el color del boton
    void SetColor(Color newColor);
    void SetColorOutline(Color newColor);

    // Metodos de la textura
    void setTexture(const char* newImage);
    void setTexture(const char* newImage, int imageValue);
    void setTexture(Texture2D newTexture, int newTextureValue);
    void drawTexture();

    Texture2D getTexture();

    int getTextureValue();

    void Reset();
};

#endif