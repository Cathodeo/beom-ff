#include "primitives_ui.h"


void draw_textbox_base(char *text)

{
   al_clear_to_color(light);
   al_draw_rounded_rectangle(25, 650, 999, 743,
   15, 15, dark, 2);
   al_draw_filled_rounded_rectangle(25, 650, 999, 743,
   15, 15, lightest);
   al_draw_justified_text(ui, darkest, 40, 665, 120, 200, 0, text); 
   
}

void draw_frame()

{
	al_draw_rounded_rectangle(25, 25, 625, 625, 15, 15, dark, 4);
}
