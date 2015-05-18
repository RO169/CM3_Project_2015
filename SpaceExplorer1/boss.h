#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
class boss
{
private:
	bool live;
	int xPos;
	int yPos;
	int animationCol;
	int animationRow;
	int speed;
	//int boundx;
	//int boundy;	//
	int maxFrame;
	int curFrame;
	int frameDelay;
	int frameWidth;
	int frameHeight;
	int frameCount;
	ALLEGRO_BITMAP *image;
public:
	boss();
	boss(bool live, int x, int y, int anCol, int anRow, int speed, int mFrame,
		int cFrame, int fDelay, int fWidth, int fHeight, ALLEGRO_BITMAP *im, int fCount);

	void initBoss(boss fSaucer[], ALLEGRO_BITMAP*image);
	void drawBoss(boss fSaucer[]);
	void startBoss(boss fSaucer[]);
	void updateBoss(boss fSaucer[]);

	~boss();
};

