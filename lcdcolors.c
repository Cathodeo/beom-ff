#include "lcdcolors.h"

ALLEGRO_COLOR darkest;
ALLEGRO_COLOR dark;
ALLEGRO_COLOR light;
ALLEGRO_COLOR lightest;

void init_lcdcolors() {
    darkest = al_map_rgb(20, 29, 23);
    dark = al_map_rgb(54, 78, 62);
    light = al_map_rgb(87, 126, 100);
    lightest = al_map_rgb(115, 166, 132);
}

void init_cgacolors() {
	darkest = al_map_rgb(0, 0, 0);
	dark = al_map_rgb(255, 85, 255);
	light = al_map_rgb(85, 255, 255);
	lightest = al_map_rgb(255, 255, 255);
}
