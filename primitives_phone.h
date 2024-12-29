#ifndef PRIMITIVES_PHONE_H
#define PRIMITIVES_PHONE_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "lcdcolors.h"
#include "fonts.h"

void draw_signal_bars(float x, float y, int num_bars, float bar_width, float max_height, float gap);
void draw_battery_meter(float percentage);
void draw_main_title(char *text);
void draw_phoneui(float percentage, char *title, int signal_bars);

#endif // End primitives_phone.h
