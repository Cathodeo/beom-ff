#include "fonts.h"

ALLEGRO_FONT *phone_text;
ALLEGRO_FONT *phone_title;
ALLEGRO_FONT *ui;
ALLEGRO_FONT *terminal;

void init_fonts() {
	
	phone_text = al_load_ttf_font("font/fc22.ttf", 16, 0);
	phone_title = al_load_ttf_font("font/fc22.ttf", 64, 0);
	ui = al_load_ttf_font("font/98.ttf", 14, 0);
	terminal = al_load_ttf_font("font/hbios.ttf", 14, 0);
	
}
