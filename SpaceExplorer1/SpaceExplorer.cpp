#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include"Background.h"

//Globals: GUI Setup
const int WIDTH = 600;
const int HEIGHT = 650;

int main()
{
	//variables
	bool done = false;
	bool render = false;

	Background BG;
	Background MG1;
	Background MG2;
	Background MG3;
	Background FG;

	//allegro variables
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer;
	ALLEGRO_BITMAP *bgImage = NULL;
	ALLEGRO_BITMAP *mgImage1 = NULL;
	ALLEGRO_BITMAP *mgImage2 = NULL;
	ALLEGRO_BITMAP *mgImage3 = NULL;
	ALLEGRO_BITMAP *fgImage = NULL;

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

	bgImage = al_load_bitmap("spaceBG.jpg");
	mgImage1 = al_load_bitmap("planet1.jpg");
	al_convert_mask_to_alpha(mgImage1, al_map_rgb(0, 0, 0));
	mgImage2 = al_load_bitmap("planet2.jpg");
	al_convert_mask_to_alpha(mgImage2, al_map_rgb(0, 0, 0));
	mgImage3 = al_load_bitmap("planet3.jpg");
	al_convert_mask_to_alpha(mgImage3, al_map_rgb(0, 0, 0));
	fgImage = al_load_bitmap("spaceFG.png");

	BG.InitBackground(BG, 0, 0, 0, 0.8, 600, 1920, 1, 1, bgImage);
	MG1.InitBackground(MG1, 0, 0, 0, 1.2, 600, 2000, 1, 1, mgImage1);
	MG2.InitBackground(MG2, 0, 0, 0, 1.2, 600, 6512, 1, 1, mgImage2);
	MG3.InitBackground(MG3, 0, 0, 0, 1.2, 600, 1563, 1, 1, mgImage3);
	FG.InitBackground(FG, 0, 0, 0, 1.8, 600, 800, 1, 1, fgImage);

	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / 60);

	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_start_timer(timer);
	while (!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_LEFT:

				break;
			case ALLEGRO_KEY_RIGHT:

				break;
			case ALLEGRO_KEY_UP:

				break;
			case ALLEGRO_KEY_DOWN:

				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			BG.UpdateBackground(BG);
			MG1.UpdateBackground(MG1);
			MG2.UpdateBackground(MG2);
			MG3.UpdateBackground(MG3);
			FG.UpdateBackground(FG);
			render = true;
		}

		if (render && al_is_event_queue_empty(event_queue))
		{
			render = false;

			BG.DrawBackground(BG);
			MG1.DrawBackground(MG1);
			MG2.DrawBackground(MG2);
			MG3.DrawBackground(MG3);
			FG.DrawBackground(FG);

			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
	}

	al_destroy_bitmap(bgImage);
	al_destroy_bitmap(mgImage1);
	al_destroy_bitmap(mgImage2);
	al_destroy_bitmap(mgImage3);
	al_destroy_bitmap(fgImage);
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);						//destroy our display object

	return 0;
}

