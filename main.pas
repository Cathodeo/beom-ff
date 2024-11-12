program AllegroSample;

uses
  Allegro5, al5image, al5primitives, al5font, al5ttf, al5base;

const
   BASE_WIDTH = 720;
   BASE_HEIGHT = 480;

var
  Display: ALLEGRO_DISPLAYptr;
  EventQueue: ALLEGRO_EVENT_QUEUEptr;
  Event: ALLEGRO_EVENT;
  Bitmap: ALLEGRO_BITMAPptr;
  Running: Boolean;
  Font: ALLEGRO_FONTptr;
 

begin
  // Initialize Allegro
  if not al_init then
  begin
    WriteLn('Failed to initialize Allegro.');
    Halt(1);
  end;

  // Initialize addons
  al_init_image_addon;
  al_init_primitives_addon;
  al_init_font_addon;
  al_init_ttf_addon;

  // Install keyboard
  if not al_install_keyboard then
  begin
    WriteLn('Failed to initialize keyboard.');
    Halt(1);
  end;

  // Create display
  al_set_new_display_flags(ALLEGRO_WINDOWED);

  
  Display := al_create_display(720, 480);
  if Display = nil then
  begin
    WriteLn('Failed to create display.');
    Halt(1);
  end;

  // Load bitmap
  Bitmap := al_load_bitmap('assets/bgr/B01Skyline.png');
  if Bitmap = nil then
  begin
    WriteLn('Failed to load bitmap.');
    al_destroy_display(Display);
    Halt(1);
  end;

  // Load font
  Font := al_load_ttf_font('assets/ttf/PC98.ttf', 16, 0);
  if Font = nil then
  begin
    WriteLn('Failed to load font.');
    al_destroy_bitmap(Bitmap);
    al_destroy_display(Display);
    Halt(1);
  end;

  // Create event queue
  EventQueue := al_create_event_queue;
  if EventQueue = nil then
  begin
    WriteLn('Failed to create event queue.');
    al_destroy_font(Font);
    al_destroy_bitmap(Bitmap);
    al_destroy_display(Display);
    Halt(1);
  end;

  // Register event sources
  al_register_event_source(EventQueue, al_get_display_event_source(Display));
  al_register_event_source(EventQueue, al_get_keyboard_event_source);

  Running := True;
  while Running do
  begin
    // Clear display
    al_clear_to_color(al_map_rgb(0, 0, 0));

    // Draw bitmap
    al_draw_bitmap(Bitmap, 54, 18, 0);

    // Draw text
    al_draw_text(Font, al_map_rgb(255, 255, 255), 18, 400, ALLEGRO_ALIGN_LEFT, 'Hello, Allegro!');

    // Flip display
    al_flip_display;

    // Wait for event
    al_wait_for_event(EventQueue, @Event);

    case Event.ftype of
      ALLEGRO_EVENT_DISPLAY_CLOSE:
        Running := False;
      ALLEGRO_EVENT_KEY_DOWN:
        if Event.keyboard.keycode = ALLEGRO_KEY_ESCAPE then
          Running := False;
    end;
  end;

  // Clean up
  al_destroy_event_queue(EventQueue);
  al_destroy_font(Font);
  al_destroy_bitmap(Bitmap);
  al_destroy_display(Display);
end.
