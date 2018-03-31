#pragma once


#include <framework/motion.hpp>


class Inventory;
class Display;


class InventoryScreen // (not actually a "Screen" in the framework sense)
{
private:
   Inventory *inventory;
   Motion motion;
   float display_counter;
   int rows, columns;
   int cursor_x, cursor_y;
   int selector_x, selector_y;

public:
   InventoryScreen(Inventory *inventory);
   ~InventoryScreen();

   int get_selected_item();

   void show();
   void hide();
   void move_cursor_up();
   void move_cursor_down();
   void move_cursor_left();
   void move_cursor_right();
   void select_item_at_cursor();

   void update(float time_now);
   void draw(Display *display);
};


