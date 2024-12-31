#ifndef PRIMITIVES_UI_H
#define PRIMITIVES_UI_H

#include <string.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "lcdcolors.h"
#include "fonts.h"

extern ALLEGRO_BITMAP *bgimg;
extern ALLEGRO_BITMAP *phoneimg;

void draw_textbox_base(char *text);
void draw_frame();

void init_phonebase();
void draw_phonebase();

void swap_bgimg(const char *filename);


#endif // End primitives_ui.h
