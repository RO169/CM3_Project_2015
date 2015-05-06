#include "Player.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
const int HEIGHT = 438;
const int WIDTH = 876;

Player::Player(){};

Player::Player(int x=300, int y=580, int liv=5, int spd=1, int bndx=4, int bndy=4, int scor=0, int maxF=60,
	           int curF=1, int fCount=0, int fDelay=2, int fWidth=343, int fHeight=171, int aniRow=0,
               int aniDir=0, int aniCol=0, ALLEGRO_BITMAP *im=0, bool live = false)
{
	xPos=x;
	yPos=y;
	lives=liv;
	speed=spd;
	boundx=bndx;
	boundy=bndy;
	score=scor;
	maxFrame=maxF;
	curFrame=curF;
	frameCount=fCount;
	frameDelay=fDelay;
	frameWidth=fWidth;
	frameHeight=fHeight;
	animationRow=aniRow;
	animationDirection=aniDir;
	animationCol=aniCol;
};

void Player::InitShip(Player &ship, ALLEGRO_BITMAP *image)
{
	ship.xPos = 300;
	ship.yPos = 600;
	ship.lives = 5;
	ship.speed = 5;
//	ship.boundx = 10;
//	ship.boundy = 12;
	ship.score = 0;

	ship.maxFrame = 3;
	ship.curFrame = 0;
	ship.frameCount = 0;
	ship.frameDelay = 50;
	ship.frameWidth = 292;
	ship.frameHeight = 146;
	ship.animationCol = 1;
	ship.animationDirection = 1;
	ship.animationRow = 1;

	ship.image = image;
};

void Player::ResetShipAnimation(Player &ship, int position)
{
	if (position == 1)
	{
		ship.animationRow = 0;
		ship.animationCol = 0;
	}
	else
		ship.curFrame = 0;
};

void Player::DrawShip(Player &ship)
{
	int fx = ship.animationCol * ship.frameWidth;
	int fy = ship.animationRow * ship.frameHeight;

	al_draw_bitmap_region(ship.image, fx, fy, ship.frameWidth,
		ship.frameHeight, ship.xPos - ship.frameWidth / 2, ship.yPos - ship.frameHeight / 2, 0);
};

void Player::MoveUp(Player &ship)
{
	ship.animationCol = 1;
	ship.yPos -= ship.speed;
	if (ship.yPos < 350)
		ship.yPos = 350;
	
};

void Player::MoveDown(Player &ship)
{
	ship.animationCol = 2;
	ship.yPos += ship.speed;
	if (ship.yPos > 650)
		ship.yPos = 650;
};

void Player::MoveLeft(Player &ship)
{
	ship.animationRow = 2;
	ship.xPos -= ship.speed;
	if (ship.xPos < 0)
		ship.xPos = 0;
};

void Player::MoveRight(Player &ship)
{
	ship.animationRow = 1;
	ship.xPos += ship.speed;
	if (ship.xPos > 600)
		ship.xPos = 600;
};

void Player::InitMiss(Player Missile[], Player &Ship , ALLEGRO_BITMAP *mImage)
{
	for (int i = 0; i < 5; i++)
	{
		Missile[i].xPos = Ship.xPos - 15;
		Missile[i].yPos = Ship.yPos - 15;
		Missile[i].speed = 8;
		//Missile.boundx = 10;
		//Missile.boundy = 12;
		Missile[i].maxFrame = 17;
		Missile[i].curFrame = 0;
		Missile[i].frameCount = 0;
		Missile[i].frameDelay = 17;
		Missile[i].frameWidth = 25;
		Missile[i].frameHeight = 97;
		Missile[i].animationCol = 0;
		Missile[i].animationDirection = -1;
		Missile[i].animationRow = 0;
		Missile[i].image = mImage;
		Missile[i].live = false;
	}
};

void Player::DrawMiss(Player Missile[])
{
	
		for (int i = 0; i < 5; i++)
	{
		if (Missile[i].live)
		{
			int fx = Missile[i].animationCol * Missile[i].frameWidth;
			int fy = Missile[i].animationRow * Missile[i].frameHeight;

			al_draw_bitmap_region(Missile[i].image, fx, fy, Missile[i].frameWidth,
				Missile[i].frameHeight, Missile[i].xPos - Missile[i].frameWidth / 2, Missile[i].yPos - Missile[i].frameHeight / 2, 0);
		}
	}
};

void Player::FireMiss(Player Missile[], Player &Ship)
{
	
	for (int i = 0; i < 5; i++)
	 {
		if (!Missile[i].live)
		{
			Missile[i].xPos = Ship.xPos - 15;
			Missile[i].yPos = Ship.yPos - 15;
			Missile[i].live = true;
			break;
		  }
		if (Missile[i].live)
			break;
	}
};


void Player::UpdateMiss(Player Missile[])
{
	for (int i = 0; i < 5; i++)
	{
		if (Missile[i].live)
		{
			//Missile[i].animationCol = 0;
			
			Missile[i].yPos -= Missile[i].speed;

			if (++Missile[i].animationCol >= Missile[i].frameDelay)
			{
				if (++Missile[i].curFrame >= Missile[i].maxFrame)
					Missile[i].curFrame = 0;

				Missile[i].animationCol = 0;
			}

			
			
			/*if (Missile[i].animationCol <= Missile[i].frameDelay)
			{
				Missile[i].animationCol++;
				
				if (Missile[i].animationCol >= Missile[i].maxFrame)
					Missile[i].animationCol = 0;
				
				frameCount = 0;
			}*/
			if (Missile[i].yPos <= 0)
				Missile[i].live = false;
		
		}
	}
};

Player::~Player()
{
}
