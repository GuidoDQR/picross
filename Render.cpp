#include "Render.h"
#include "Colors.h"
#include "Boton.h"
#include <cstdio>

int windowCounter;
int botonId = 0;
int tileX = 0;
int tileY = 0;
int tileOffsetX = 200;
int tileOffsetY = 160;
int counterTileX[maxTiles][maxTiles];
int counterTileY[maxTiles][maxTiles];
int counterPaddingX=0;
int counterPaddingY=0;
int textOffsetX = 0;
int textOffsetY = 0;
int textPaddingX = 0;
int textPaddingY = 0;
Color tileColor;

Boton (*tile)[maxTiles] = new Boton[maxTiles][maxTiles];
Boton* colorMenu = new Boton[maxColors];

void PanelColor(){
	
   for(int i=0;i<maxColors;i++){
      colorMenu[i].Draw();
      if(colorMenu[i].BotonPressed(mouse,0)){
         colorSelected = colorMenu[i].GetColor();
         colorMenu[colorPos].lineThick = 2;
         colorMenu[i].lineThick = 3;
         colorPos = i;
      }

      if(colorMenu[i].MouseOverBoton(mouse) || CompareColors(colorMenu[i].GetColor(),colorSelected)){
     	   colorMenu[i].DrawOutline();
      }
   }

}

void Editor(){
   ClearBackground(DARKBLUE);

   for(int i=0; i < maxTiles;i++){
      for(int j=0; j < maxTiles; j++){
         tile[i][j].Draw();
      }
   }

   textOffsetX = 0;
   textOffsetY = 0;
   textPaddingX = 0;
   textPaddingY = 0;
   counterPaddingX = 0;
   counterPaddingY = 0;
   for(int i = 0; i< maxTiles; i++){
      for(int j = 0; j< maxTiles;j++){
         counterTileX[i][j] = 0;
         counterTileY[i][j] = 0;
      }
      
   }

   // Dibuja la cantidad de tiles de forma horizontal

   for(int i=0; i < maxTiles;i++){
      for(int j=0; j < maxTiles; j++){

         if(tile[i][j].BotonReleased() || !tile[i][j].MouseOverBoton(mouse)){
            //tile[i][j].SetColorOutline(Color{0,0,0,255});
            //tile[i][j].SetColor(colorSelected);
         }
         
         if(tile[i][j].BotonPressed(mouse,0)){
            //printf("color:[%d][%d][%d]\n", tile[i][j].GetColor().r, tile[i][j].GetColor().g, tile[i][j].GetColor().b);
         }

         if(tile[i][j].BotonDown(mouse,0) && tile[i][j].MouseOverBoton(mouse)){
            //tile[i][j].SetColorOutline(Color{0,255,0,255});
            tile[i][j].SetColor(colorSelected);

            //printf("set white:[%d][%d]\n", j,i);
         }else if(tile[i][j].BotonDown(mouse,1) && tile[i][j].MouseOverBoton(mouse)){
            tile[i][j].SetColor(WHITE);
         }

         if(tile[i][j].MouseOverBoton(mouse)){
            botonId = tile[i][j].id;
            tileX = j;
            tileY = i;
            
            //tile[i][j].SetColorOutline(Color{0,0,255,255});
            tile[i][j].DrawOutline();
         }
         
         if(!IsWhite(tile[i][j].GetColor())){
            counterTileX[i][counterPaddingX]++;
            //printf("not white:[%d][%d]\n", i,j);     
         }else {
            if(counterTileX[i][counterPaddingX] != 0){
               counterPaddingX++;
               textPaddingX = 0;
               //printf("is white:[%d][%d]\n", i,j);
            }
            
         }
         
      }

      for(int k=counterPaddingX;k>=0;k--){
         if(counterTileX[i][k] != 0 || (counterTileX[i][k] == 0 && k == 0)){
            DrawText(TextFormat("%d", counterTileX[i][k]),tile[0][0].GetShape().x-20 - textPaddingX,tile[0][0].GetShape().y + 6 +textOffsetY,20,BLACK);
            textPaddingX += 20;
         }     
      }
      textPaddingX = 0;
      counterPaddingX = 0;

      textPaddingY = 0;
      textOffsetX += 32;
      textOffsetY += 32;
   }

   textOffsetX = 0;

   // Dibuja la cantidad de tiles de forma vertical

   for(int i=0;i<maxTiles;i++){
      for(int j=0;j<maxTiles;j++){
         if(!IsWhite(tile[j][i].GetColor())){
            counterTileY[i][counterPaddingY]++; 
            //printf("not white:[%d][%d]\n", i,j);     
         }else {
            if(counterTileY[i][counterPaddingY] !=0){
               counterPaddingY++;
               //printf("is white:[%d][%d]\n", i,j);
            }            
            
         }
      }
      for(int k=counterPaddingY;k>=0;k--){
         if(counterTileY[i][k] != 0 || (counterTileY[i][k] == 0 && k == 0)){
            DrawText(TextFormat("%d", counterTileY[i][k]),tile[0][0].GetShape().x+10+textOffsetX,tile[0][0].GetShape().y - 20 - textPaddingY,20,BLACK);
            textPaddingY +=20;
         }
      }
      textPaddingY = 0;
      textOffsetX += 32;

      counterPaddingY = 0;
   }
   Vector2 startPos;
   Vector2 endPos;

   // Lineas verticales

   for(int i = 0; i<maxTiles;i++){
      startPos.x = tile[0][i].GetShape().x;
      startPos.y = tile[0][i].GetShape().y-1;
      endPos.x   = tile[maxTiles-1][i].GetShape().x;
      endPos.y   = tile[maxTiles-1][i].GetShape().y + tile[maxTiles-1][i].GetShape().height; 
      if(i%5 ==0){
         DrawLineEx(startPos,endPos,1,ORANGE);
      }else{
         DrawLineEx(startPos,endPos,1,BLACK);   
      }
      
   }
   
   startPos.x = tile[0][maxTiles-1].GetShape().x + tile[0][maxTiles-1].GetShape().width;
   startPos.y = tile[0][maxTiles-1].GetShape().y;
   endPos.x   = tile[maxTiles-1][maxTiles-1].GetShape().x + tile[maxTiles-1][maxTiles-1].GetShape().width;
   endPos.y   = tile[maxTiles-1][maxTiles-1].GetShape().y + tile[maxTiles-1][maxTiles-1].GetShape().height;
   DrawLineEx(startPos,endPos,1,ORANGE);

   // Lineas horizontales

   for(int i = 0; i<maxTiles;i++){
      startPos.x = tile[i][0].GetShape().x;
      startPos.y = tile[i][0].GetShape().y;
      endPos.x   = tile[i][maxTiles-1].GetShape().x + tile[i][maxTiles-1].GetShape().width;
      endPos.y   = tile[i][maxTiles-1].GetShape().y; 
      if(i%5 ==0){
         DrawLineEx(startPos,endPos,1,ORANGE);
      }else{
         DrawLineEx(startPos,endPos,1,BLACK);   
      }
   }

   startPos.x = tile[maxTiles-1][0].GetShape().x;
   startPos.y = tile[maxTiles-1][0].GetShape().y + tile[maxTiles-1][0].GetShape().height;
   endPos.x   = tile[maxTiles-1][maxTiles-1].GetShape().x + tile[maxTiles-1][maxTiles-1].GetShape().width;
   endPos.y   = tile[maxTiles-1][maxTiles-1].GetShape().y + tile[maxTiles-1][maxTiles-1].GetShape().height;
   DrawLineEx(startPos,endPos,1,ORANGE);

   
   DrawText(TextFormat("ID: %d",botonId),10,390,20,BLACK);
   DrawText(TextFormat("y: %d, x: %d",tileY,tileX),10,410,20,BLACK);
   
}

void RenderInit(){
   for (int i = 0; i < maxTiles; i++) {
        for(int j=0; j < maxTiles; j++){
            tile[i][j].SetBoton((j*32)+tileOffsetX,(i*32)+tileOffsetY, 32, 32);
            tile[i][j].SetColor(WHITE);
            //printf("%d\n",tile[i][j].id);
            //windowCounter++;
        }       
    }

	for(int i=0;i<maxColors;i++){
        colorMenu[i].SetBoton((10 + (30*i) + (4*i)),10,32,32);
        colorMenu[i].SetColor(Colors[i]);
   }
   
   colorPos = 1;
   colorMenu[0].lineThick = 3; 
   colorMenu[1].SetColorOutline(WHITE);
   colorSelected = colorMenu[colorPos].GetColor();

   windowCounter = 0;

}

void RenderGame(){
	Editor();
	PanelColor();
}