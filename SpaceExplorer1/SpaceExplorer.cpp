#include<cstdlib>
#include<ctime>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include"Background.h"
#include"Player.h"

//Globals
const int WIDTH = 600;
const int HEIGHT = 650;
enum KEYS{ UP, DOWN, LEFT, RIGHT, SPACE };
bool keys[5] = { false, false, false, false, false };

int main()
{
	//variables
	bool done = false;
	bool render = false;

	Background BG;
	Background MG1;
	Background MG2;
	Background MG3;
	Background MG4;
	Background FG;
	
	Player Ship;
	Player Missile[5];

	//allegro variables
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer;
	ALLEGRO_BITMAP *bgImage = NULL;                      //background
	ALLEGRO_BITMAP *mgImage1 = NULL;                     //middleground 1
	ALLEGRO_BITMAP *mgImage2 = NULL;                     //middleground 2
	ALLEGRO_BITMAP *mgImage3 = NULL;                     //middleground 3
	ALLEGRO_BITMAP *mgImage4 = NULL;                     //middleground 4
	ALLEGRO_BITMAP *fgImage = NULL;                      //foreground
	ALLEGRO_BITMAP *pImage = NULL;                       //player sprite
	ALLEGRO_BITMAP *mImage = NULL;                       //missile sprite

	//program init
	if (!al_init())										//initialize Allegro
		return -1;

	display = al_create_display(WIDTH, HEIGHT);			//create our display object

	if (!display)										//test display object
		return -1;

	//addon init
	al_install_keyboard();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();

	//background images
	srand(time(0));
	int num = ((rand() % 6000) + 2000);                //use random numbers for planet appearance repitition

	bgImage = al_load_bitmap("spaceBG.jpg");
	mgImage1 = al_load_bitmap("MG-1.png");
	al_convert_mask_to_alpha(mgImage1, al_map_rgb(255, 255, 255));
	mgImage2 = al_load_bitmap("MG-2.png");
	al_convert_mask_to_alpha(mgImage2, al_map_rgb(255, 255, 255));
	mgImage3 = al_load_bitmap("MG-3.png");
	al_convert_mask_to_alpha(mgImage3, al_map_rgb(255, 255, 255));
	mgImage4 = al_load_bitmap("MG-4.png");
	al_convert_mask_to_alpha(mgImage3, al_map_rgb(255, 255, 255));
	fgImage = al_load_bitmap("spaceFG.png");

	BG.InitBackground(BG, 0, 0, 1, 1.4, 600, 1920, 1, 1, bgImage);
	FG.InitBackground(FG, 0, 0, 0, 2, 600, 800, 1, 1, fgImage);
	MG1.InitBackground(MG1, 0, 0, 0.2, 0.8, 600, num, 2, 1, mgImage1);
	MG2.InitBackground(MG2, 0, 0, 4, 0.7, 600, 100 + num, 1, 1, mgImage2);
	MG3.InitBackground(MG3, 0, 0, 0.1, 0.6, 600, 210 + num * num, -3, 1, mgImage3);
	MG4.InitBackground(MG4, 0, 0, 0.02, 0.6, 600, 1500 + num, 1, 1, mgImage4);

	//player pImage
	pImage = al_load_bitmap("Ship.png");
	al_convert_mask_to_alpha(pImage, al_map_rgb(0, 0, 0));
	Ship.InitShip(Ship, pImage);

	//missile image
	mImage = al_load_bitmap("miss.png");
	al_convert_mask_to_alpha(mImage, al_map_rgb(255, 255, 255));
	Missile[5].InitMiss(Missile, Ship, mImage);


	//event handlers
	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / 60);

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_start_timer(timer);
	
	//game loop
	while (!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
			
		if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			BG.UpdateBackground(BG);
			MG1.UpdateBackground(MG1);
			MG2.UpdateBackground(MG2);
			MG3.UpdateBackground(MG3);
			MG3.UpdateBackground(MG4);
			FG.UpdateBackground(FG);
			Missile[5].UpdateMiss(Missile);
			render = true;

			//redraw = true;
			
			if (keys[UP])
				Ship.MoveUp(Ship);
			else if (keys[DOWN])
				Ship.MoveDown(Ship);
			else
				Ship.ResetShipAnimation(Ship, 1);

			if (keys[LEFT])
				Ship.MoveLeft(Ship);
			else if (keys[RIGHT])
				Ship.MoveRight(Ship);
			else
				Ship.ResetShipAnimation(Ship, 2);

			if (keys[SPACE])
			   Missile[5].FireMiss(Missile, Ship);
			
			/*
			if (!isGameOver)
			{
				UpdateBullet(bullets, NUM_BULLETS);
				StartComet(comets, NUM_COMETS);
				UpdateComet(comets, NUM_COMETS);
				CollideBullet(bullets, NUM_BULLETS, comets, NUM_COMETS, ship);
				CollideComet(comets, NUM_COMETS, ship);

				if (ship.lives <= 0)
					isGameOver = true;
			}*/
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[SPACE] = true;
			/*	FireBullet(bullets, NUM_BULLETS, ship); */
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = false;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = false;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[SPACE] = false;
				break;
			}
		}


		if (render && al_is_event_queue_empty(event_queue))
		{
			render = false;

			BG.DrawBackground(BG);
			MG1.DrawBackground(MG1);
			MG2.DrawBackground(MG2);
			MG3.DrawBackground(MG3);
			FG.DrawBackground(FG);

			Missile[0].DrawMiss(Missile);
			Ship.DrawShip(Ship);

			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
	}

	//destroy loaded addons to free up memory

	al_destroy_bitmap(bgImage);
	al_destroy_bitmap(mgImage1);
	al_destroy_bitmap(mgImage2);
	al_destroy_bitmap(mgImage3);
	al_destroy_bitmap(mgImage4);
	al_destroy_bitmap(fgImage);
	al_destroy_bitmap(pImage);
	al_destroy_bitmap(mImage);
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);						

	return 0;
}

