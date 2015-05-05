#include "Player.h"
const int HEIGHT = 924;
const int WIDTH = 288;

Player::Player(){};

Player::Player(int x=300, int y=580, int liv=5, int spd=1, int bndx=4, int bndy=4, int scor=0, int maxF=60,
	           int curF=1, int fCount=0, int fDelay=2, int fWidth=343, int fHeight=171, int aniRow=0,
               int aniDir=0, int aniCol=0, ALLEGRO_BITMAP *im=0)
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
	ship.speed = 6;
	ship.boundx = 10;
	ship.boundy = 12;
	ship.score = 0;

	ship.maxFrame = 3;
	ship.curFrame = 0;
	ship.frameCount = 0;
	ship.frameDelay = 50;
	ship.frameWidth = 288;
	ship.frameHeight = 132;
	ship.animationCol = 1;
	ship.animationDirection = 1;
	ship.animationRow = 4;

	ship.image = image;
};

void Player::ResetShipAnimation(Player &ship, int position)
{
	if (position == 1)
		ship.animationRow = 3;
	else
		ship.curFrame = 0;
};

void Player::DrawShip(Player &ship)
{
	int fx = ship.curFrame * ship.frameWidth;
	int fy = ship.animationRow * ship.frameHeight;

	al_draw_bitmap_region(ship.image, fx, fy, ship.frameWidth,
		ship.frameHeight, ship.xPos - ship.frameWidth / 2, ship.yPos - ship.frameHeight / 2, 0);
};

void Player::MoveUp(Player &ship)
{
	ship.animationRow = 3;
	ship.yPos -= ship.speed;
	if (ship.yPos < 350)
		ship.yPos = 350;
	
};

void Player::MoveDown(Player &ship)
{
	ship.animationRow = 3;
	ship.yPos += ship.speed;
	if (ship.yPos > 650)
		ship.yPos = 650;
};

void Player::MoveLeft(Player &ship)
{
		ship.animationRow = 3;
		ship.animationRow = 2;
		ship.animationRow = 1;
		ship.animationRow = 0;
		ship.xPos -= ship.speed;
		if (ship.xPos < 0)
			ship.xPos = 0;
};

void Player::MoveRight(Player &ship)
{
	ship.animationRow = 3;
	ship.animationRow = 4;
	ship.animationRow = 5;
	ship.animationRow = 6;
	ship.xPos += ship.speed;
	if (ship.xPos > 600)
		ship.xPos = 600;
};

Player::~Player()
{
}
