//Class for Background Images 

#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>


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
	void InitBackground(Background &back, float x, float y, float velx, float vely, int width, int height, int dirX, int dirY, ALLEGRO_BITMAP *image);
	void UpdateBackground(Background &);
	void DrawBackground(Background &);
	~Background();
};

