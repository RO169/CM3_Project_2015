#include "Alien.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include<cstdlib> 
#include<ctime>

Alien::Alien(){};

Alien::Alien(bool live=false, int x=0, int y=0, int anCol=0, int anRow=0, int speed=4, int mFrame=3,
	int cFrame=0, int fDelay=3, int fWidth=154, int fHeight=105, ALLEGRO_BITMAP *im=0, int fCount=0)
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

void Alien::initAliens(Alien fSaucer[], ALLEGRO_BITMAP*image)
{
	for (int i = 0; i < 3; i++)
	{
		fSaucer[i].xPos = 300;
		fSaucer[i].yPos = 20;
		fSaucer[i].speed = 3;
		//Missile.boundx = 10;
		//Missile.boundy = 12;
		fSaucer[i].maxFrame = 3;
		fSaucer[i].curFrame = 0;
		
		fSaucer[i].frameDelay = 1;
		fSaucer[i].frameWidth = 154;
		fSaucer[i].frameHeight = 108;
		fSaucer[i].animationCol = 0;
		fSaucer[i].frameCount = 0;

		fSaucer[i].animationRow = 0;
		fSaucer[i].image = image;
		fSaucer[i].live = false;
		
	}
};

void Alien::drawAliens(Alien fSaucer[])
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

void Alien::startAlien(Alien fSaucer[],int lim=2)
{
	srand(time(0));
	for (int i = 0; i < lim; i++)
	{
		
		int num1 = (rand() % (600));
		int num2 = (rand() % 3);

		if (!fSaucer[i].live)
		{
			if ((rand() % 500) % 2 == 0)
			{
				fSaucer[i].live = true;
				fSaucer[i].yPos = 0;
				fSaucer[i].xPos = num1;
				fSaucer[i].animationRow = num2;

				break;
			}

			if (fSaucer[i].live)
			break;
		}
	}
};

void Alien::updateAliens(Alien fSaucer[],int lim=2)
{
	
	for (int i = 0; i < lim; i++)
	{
		if (fSaucer[i].live)
		{

			fSaucer[i].yPos += fSaucer[i].speed;

			if (++fSaucer[i].frameCount >= fSaucer[i].frameDelay)
			{
				if (++fSaucer[i].curFrame >= fSaucer[i].maxFrame)
				fSaucer[i].curFrame = 0;
				
				if (fSaucer[i].yPos % 7 == 0)
				fSaucer[i].animationCol++;

				if (fSaucer[i].animationCol>=3)
				fSaucer[i].animationCol = 0;
			}		
	    }
	    	if (fSaucer[i].yPos >= 700)
			fSaucer[i].live = false;
	}	
};

Alien::~Alien(){};
