#ifndef COLORS_H
#define COLORS_H
#include <raylib.h>

const int maxColors  = 20;

Color Colors[maxColors]{
	WHITE,
	BLACK,
	LIGHTGRAY,
	GRAY,
	YELLOW,
	GOLD,
	RED,
	GREEN,
	BLUE,
	BROWN,
	PURPLE,
	VIOLET
};

bool IsWhite(Color newColor){
	if(newColor.r == 255 && newColor.g == 255 && newColor.b == 255){
        return true;
    }
    return false;
}

bool CompareColors(Color c1, Color c2){
	if(c1.r == c2.r && c1.g == c2.g && c1.b == c2.b && c1.a == c2.a){
        return true;
    }
    return false;
}

#endif