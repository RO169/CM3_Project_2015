//class for aliens

#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class Alien
{
private:

	bool live;
	int xPos;
	int yPos;
	int animationCol;
	int animationRow;
	int speed;
	//int boundx;
	//int boundy;
	int maxFrame;
	int curFrame;
	int frameDelay;
	int frameWidth;
	int frameHeight;
	int frameCount;
	ALLEGRO_BITMAP *image;

public:
	int limit;
	Alien();
	Alien(bool live, int x, int y, int anCol, int anRow, int speed, int mFrame, 
		  int cFrame, int fDelay, int fWidth, int fHeight, ALLEGRO_BITMAP *im, int fCount);

	void initAliens(Alien fSaucer[], ALLEGRO_BITMAP*image);
	void drawAliens(Alien fSaucer[]);
	void startAlien(Alien fSaucer[],int lim);
	void updateAliens(Alien fSaucer[],int lim);

	~Alien();
};

