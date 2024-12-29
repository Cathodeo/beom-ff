#include <allegro5/allegro.h>           // Core Allegro library
#include <allegro5/allegro_primitives.h> // For drawing shapes (optional)
#include <stdio.h>
#include "dbconnect.h"
#include "dbquery.h"
#include "primitives_phone.h"
#include "lcdcolors.h"

int main() {
	
	sqlite3 *db = db_open("db/beom.db");
    // Initialize Allegro library
    if (!al_init()) {
        fprintf(stderr, "Failed to initialize Allegro!\n");
        return -1;
    }
    
    if (!al_init_primitives_addon()) {  // Initialize the primitives addon
        fprintf(stderr, "Failed to initialize the primitives addon.\n");
        return -1;
    }
    
    
    al_init_font_addon();
    if (!al_init_ttf_addon()) {
        fprintf(stderr, "Failed to initialize TTF addon!\n");
        return -1;
    }

    // Create a display (window) on XGA resolution
    ALLEGRO_DISPLAY *display = al_create_display(1024, 768);
    if (!display) {
        fprintf(stderr, "Failed to create display!\n");
        return -1;
    }

    // Set the display title (optional)
    al_set_window_title(display, "Beom-ff");
    

    // Initialize the keyboard subsystem (optional)
    if (!al_install_keyboard()) {
        fprintf(stderr, "Failed to initialize keyboard input!\n");
        al_destroy_display(display);
        return -1;
    }

    // Create an event queue to handle input and other events
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    if (!event_queue) {
        fprintf(stderr, "Failed to create event queue!\n");
        al_destroy_display(display);
        return -1;
    }

    // Register the display and keyboard to the event queue
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    // Main loop control flag
    bool running = true;
    
    
		init_lcdcolors();
		init_fonts();

    // Main game loop
    while (running) {
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event); // Wait for an event

        // Handle events
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            // Exit if the display close button is pressed
            running = false;
        } else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            // Exit if the escape key is pressed
            if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                running = false;
            }
        }
		
		draw_phoneui(0.4, "Agenda", 3);
		
    }

    // Clean up resources
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
	db_close(db);

    return 0;
}
