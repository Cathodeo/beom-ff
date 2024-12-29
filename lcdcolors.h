#ifndef LCDCOLORS_H
#define LCDCOLORS_H

#include <allegro5/allegro.h>

extern ALLEGRO_COLOR darkest;
extern ALLEGRO_COLOR dark;
extern ALLEGRO_COLOR light;
extern ALLEGRO_COLOR lightest;

void init_lcdcolors();
void init_cgacolors();

#endif // LCDCOLORS_H
