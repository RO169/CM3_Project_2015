#include "boss.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <cstdlib> 
#include <ctime>

boss::boss(){}

boss::~boss(){}

boss::boss(bool live = false, int x = 0, int y = 0, int anCol = 0, int anRow = 0, int speed = 4, int mFrame = 3,
	int cFrame = 0, int fDelay = 2, int fWidth = 250, int fHeight = 70, ALLEGRO_BITMAP *im = 0, int fCount = 0)
{
	live = live;
	xPos = x;
	yPos = y;
	animationCol = anCol;
	animationRow = anRow;
	speed = speed;
	maxFrame = mFrame;
	curFrame = cFrame;
	frameDelay = fDelay;
	frameWidth = fWidth;
	frameHeight = fHeight;
	image = im;
	frameCount = fCount;
};

void boss::initBoss(boss fSaucer[], ALLEGRO_BITMAP*image)
{
	for (int i = 0; i < 3; i++)
	{
		fSaucer[i].yPos = 90;
		fSaucer[i].speed = 2;
		//Missile.boundx = 10;
		//Missile.boundy = 12;
		fSaucer[i].maxFrame = 1;
		fSaucer[i].curFrame = 0;

		fSaucer[i].frameDelay = 1;
		fSaucer[i].frameWidth = 250;
		fSaucer[i].frameHeight = 170;
		fSaucer[i].animationCol = 0;
		fSaucer[i].frameCount = 0;

		fSaucer[i].animationRow = 0;
		fSaucer[i].image = image;
		fSaucer[i].live = false;

	}
};

void boss::drawBoss(boss fSaucer[])
{
	for (int i = 0; i < 3; i++)
	{
		if (fSaucer[i].live)
		{
			int fx = fSaucer[i].animationCol * fSaucer[i].frameWidth;
			int fy = fSaucer[i].animationRow * fSaucer[i].frameHeight;

			al_draw_bitmap_region(fSaucer[i].image, fx, fy, fSaucer[i].frameWidth, fSaucer[i].frameHeight,
				fSaucer[i].xPos - fSaucer[i].frameWidth / 2, fSaucer[i].yPos - fSaucer[i].frameHeight / 2, 0);
		}
	}
};

void boss::startBoss(boss fSaucer[])
{
	
	for (int i = 0; i < 3; i++)
	{
		if (!fSaucer[i].live)
		{
			fSaucer[i].live = true;
			fSaucer[i].yPos = 90;
			fSaucer[i].xPos = -150;
		   	break;
		}
		if (fSaucer[i].live)
			break;
	}
};

void boss::updateBoss(boss fSaucer[])
{

	for (int i = 0; i < 3; i++)
	{

		if (fSaucer[i].live)
		{

			fSaucer[i].xPos += fSaucer[i].speed;

			if (++fSaucer[i].frameCount >= fSaucer[i].frameDelay)
			{
				if (++fSaucer[i].curFrame >= fSaucer[i].maxFrame)
					fSaucer[i].curFrame = 0;

				if (fSaucer[i].xPos % 9 == 0)
					fSaucer[i].animationCol++;

				if (fSaucer[i].animationCol >= 2)
					fSaucer[i].animationCol = 0;
			}

		}


		if (fSaucer[i].xPos >= 750)
		{
			fSaucer[i].speed = -2;
		}

		if (fSaucer[i].xPos <= -150)
		{
			fSaucer[i].speed = 2;
		}
	}


};
