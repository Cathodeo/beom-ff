#include "primitives_phone.h"


void draw_signal_bars(float x, float y, int num_bars, float bar_width, float max_height, float gap) {
        
    for (int i = 0; i < num_bars; i++) {
        float bar_height = (max_height / num_bars) * (i + 1); // Increasing height
        float bar_x1 = x + i * (bar_width + gap);            // Left side of the bar
        float bar_y1 = y + (max_height - bar_height);        // Top side of the bar
        float bar_x2 = bar_x1 + bar_width;                  // Right side of the bar
        float bar_y2 = y + max_height;                      // Bottom side of the bar
        
        al_draw_filled_rectangle(bar_x1, bar_y1, bar_x2, bar_y2, darkest);
		//56 width + 50 offset = 106 
    }
    
}

void draw_battery_meter(float percentage)

{
	if (percentage < 0.0) percentage = 0.0;
	if (percentage > 1.0) percentage = 1.0;
	al_draw_rectangle(918, 50, 984, 90, darkest, 3);
	al_draw_filled_rectangle(924, 56, 924 + (44 * percentage), 84, darkest);
	
}

void draw_main_title(char *text)

{
	al_draw_justified_text(phone_title, darkest, 412, 974, 120, 200, 0, text); 
}


void draw_phoneui(float percentage, char *title, int signal_bars)
{
	al_clear_to_color(lightest);
	draw_signal_bars(50, 50, signal_bars, 8, 40, 6);
	draw_battery_meter(percentage);
	draw_main_title(title);
	al_flip_display();
}
