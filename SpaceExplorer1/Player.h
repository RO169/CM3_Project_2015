//class for player
#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class Player
{
private:
	int xPos;
	int yPos;
	int lives;
	int speed;
	int boundx;
	int boundy;
	int score;

	int maxFrame;
	int curFrame;
	int frameCount;
	int frameDelay;
	int frameWidth;
	int frameHeight;
	int animationRow;
	int animationDirection;
	int animationCol;

	ALLEGRO_BITMAP *image;
public:
	bool live;
	Player();
	Player(int x, int y, int liv, int spd, int bndx, int bndy, int scor, int maxF,
		   int curF, int fCount, int fDelay, int fWidth, int fHeight, int aniCols,
		   int aniDir, int aniColr, ALLEGRO_BITMAP *im, bool live);
	
	void InitShip(Player &ship, ALLEGRO_BITMAP *image);
	void ResetShipAnimation(Player &ship, int position);
	void DrawShip(Player &ship);
	void MoveUp(Player &ship);
	void MoveDown(Player &ship);
	void MoveLeft(Player &ship);
	void MoveRight(Player &ship);
	
	void InitMiss(Player miss[], Player &Ship, ALLEGRO_BITMAP *mImage);
	void DrawMiss(Player miss[]);
	void FireMiss(Player miss[], Player &Ship);
	void UpdateMiss(Player miss[]);
	
	~Player();
};

