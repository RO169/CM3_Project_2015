//Functions For Background Images

#include "Background.h"
const int WIDTH = 600;
const int HEIGHT = 650;

Background::Background(){};

Background::Background(float x = 0, float y = 0, float velX = 0, float velY = 1, int dirX = 0, int dirY = 0, int w=600, int h=650, ALLEGRO_BITMAP *im=0)
{
	xPos = x;
	yPos = y;
	velocityX = velX;
	velocityY = velY;
	directionX = dirX;
	directionY = dirY;
	width = w;
	height = h;
	image = im;
};

void Background::InitBackground(Background &back, float x, float y, float velx, float vely, int width, int height, int dirX, int dirY, ALLEGRO_BITMAP *image)
{
	back.xPos = x;
	back.yPos = y;
	back.velocityX = velx;
	back.velocityY = vely;
	back.width = width;
	back.height = height;
	back.directionX = dirX;
	back.directionY = dirY;
	back.image = image;
}

void Background::UpdateBackground(Background &back)
{
	back.yPos += back.velocityY * back.directionY;
	if (back.yPos - back.height >= HEIGHT)
		back.yPos = 0;
};

void Background::DrawBackground(Background &back)
{
	al_draw_bitmap(back.image, back.xPos, back.yPos, 0);

	if (back.yPos - back.height <= HEIGHT)
		al_draw_bitmap(back.image, back.xPos, back.yPos-back.height, 0);
};

Background::~Background(){};
