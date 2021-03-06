#ifndef __AF_FRAMEWORK_HEADER
#define __AF_FRAMEWORK_HEADER




#include <string>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_native_dialog.h>
#include <framework/bins/bitmap_bin.hpp>
#include <framework/bins/font_bin.hpp>
#include <framework/bins/model_bin.hpp>
#include <framework/bins/sample_bin.hpp>
#include <framework/config.hpp>
#include <framework/display.hpp>
#include <framework/motion.hpp>
#include <framework/screen.hpp>




class Framework
{
private:
   static Framework *instance;
   static Framework *get_instance();
   static bool initialized;
   Framework(std::string config_filename);
   ~Framework();

   Config config;
   FontBin fonts;
   SampleBin samples;
   BitmapBin bitmaps;
   ModelBin models;
   Motion motions;

public:
   static ALLEGRO_TEXTLOG *textlog;
   static ALLEGRO_JOYSTICK *joystick; // this needs some updating to allow for multiple joysticks
   static ALLEGRO_EVENT_QUEUE *event_queue;
   static ALLEGRO_FONT *builtin_font;
   static ALLEGRO_TIMER *primary_timer;
   static bool shutdown_program; // set this to true at any time to shutdown the program
   static Screen *current_screen;
   static ALLEGRO_EVENT *current_event;
   static double time_now; // used to be current_event_time

   static int key_alt, key_shift, key_ctrl;
   static bool drawing_profiler_graph;

   static ALLEGRO_FONT *font(std::string identifier);
   static ALLEGRO_BITMAP *bitmap(std::string identifier);
   static ALLEGRO_SAMPLE *sample(std::string identifier);
   static Model3D *model(std::string identifier);
   static Motion &motion(); // we'll do this for now
   static Config &get_config();

   static bool initialize(std::string config_filename="data/config/config.cfg");
   static bool destruct();
   static bool is_initialized();
   static Display *create_display(int width=1280, int height=720);
   static Display *create_display(int width, int height, int display_flags);
   static Display *create_display(int width, int height, int display_flags, int adapter);
   static Display *create_display(int width, int height, bool fullscreen);
   static Display *create_display(int width, int height, bool fullscreen, int adapter);
   static Display *create_display(Display::resolution_t resolution);

   static void use_screen(Screen *screen);
   static void run_loop();

   static std::string get_allegro_version();
   static std::string get_version();
   static void open_log_window();
   static void close_log_window();
   static void log(std::string message);
};




#endif
