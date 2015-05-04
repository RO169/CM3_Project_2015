//Class for Background Images 

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#pragma once

class Background
{
private:
	
	float xPos;
	float yPos;
	float velocityX;
	float velocityY;
	int directionX;
	int directionY;
	int width;
	int height;
	ALLEGRO_BITMAP *image;

public:
	
	Background();
	Background(float, float, float, float, int, int, int, int, ALLEGRO_BITMAP*);
	void InitBackground(Background &, float, float, float, float, int, int, int, int, ALLEGRO_BITMAP*);
	void UpdateBackground(Background &);
	void DrawBackground(Background &);
	~Background();
};

