#include "primitives_ui.h"

ALLEGRO_BITMAP *bgimg;
ALLEGRO_BITMAP *phoneimg;

void draw_textbox_base(char *text)

{
   al_clear_to_color(light);
   al_draw_rounded_rectangle(25, 650, 999, 700,
   15, 15, dark, 2);
   al_draw_filled_rounded_rectangle(25, 650, 999, 700,
   15, 15, lightest);
   al_draw_justified_text(ui, darkest, 40, 665, 662, 200, 0, text); 
   
}

void draw_frame()

{
	al_draw_rounded_rectangle(25, 25, 625, 625, 15, 15, dark, 4);
}

void init_phonebase()

{
		phoneimg = al_load_bitmap("img/phone.png");
}

void draw_phonebase()

{
	al_draw_bitmap(phoneimg, 720, 25, 0);
}

void swap_bgimg(const char *filename) {
    char fullpath[128]; // Increased buffer size to avoid overflow
    snprintf(fullpath, sizeof(fullpath), "img/%s", filename);

    // Destroy the previous bitmap if it exists
    if (bgimg) {
        al_destroy_bitmap(bgimg);
    }

    // Load the new background image
    bgimg = al_load_bitmap(fullpath);
    if (!bgimg) {
        fprintf(stderr, "Failed to load image: %s\n", fullpath);
        return;
    }

    // Get the dimensions of the image
    int img_width = al_get_bitmap_width(bgimg);
    int img_height = al_get_bitmap_height(bgimg);

    // Draw the bitmap scaled to desired dimensions
    al_draw_scaled_bitmap(
        bgimg,
        0, 0,                // Source origin
        img_width, img_height, // Source dimensions
        25, 25,              // Destination origin
        600, 600,            // Destination dimensions (hardcoded for now)
        0                    // Flags
    );

    // Optionally, flip the display if you're testing directly
    al_flip_display();
}

