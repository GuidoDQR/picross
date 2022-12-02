#include "Picross.h"
#include "Render.h"
#include <cstdio>

Vector2 mouse;
Color colorSelected;
int colorPos;
GameState gameState = menu;
bool loadedPicross  = false;
bool loadedFile     = false;
char file[MAX_INPUT_CHARS];

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    
    InitWindow(screenWidth, screenHeight, "Picross");

    // TODO: Load resources / Initialize variables at this point

    SetTargetFPS(60);
    //int windowCreated = 0;
    //Vector2 windowPos = {(float) GetScreenWidth()/2, (float) GetScreenHeight()/2};
    
    //Window* windows = new Window[maxWindows];
    
    //--------------------------------------------------------------------------------------
    RenderInit();

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        mouse = GetMousePosition();

        if(gameState != menu && IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_A)){
            gameState = menu;
            loadedPicross = false;
            showText = false;
            letterCount = 0;
        }

        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update variables / Implement example logic at this point
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            // TODO: Draw everything that requires to be drawn at this point:
            
            RenderGame();
            
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------

    // TODO: Unload all loaded resources at this point

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
