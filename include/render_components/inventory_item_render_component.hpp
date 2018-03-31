#pragma once


#include <framework/objects/bitmap_object.hpp>
#include <framework/placement2d.hpp>
#include <models/sprite_sheet.hpp>
#include <item_type_nums.hpp>


class InventoryItemRenderComponent
{
public:
   enum state_t
   {
      STATE_UNSELECTED,
      STATE_SELECTED,
      STATE_HILIGHTED
   };

private:
   int item_type;
   float inventory_screen_position_x, inventory_screen_position_y;
   placement2d place;
   int count;
   state_t state;
   SpriteSheet sprite_sheet;
   BitmapObject bitmap;

public:
   InventoryItemRenderComponent(item_t item_type, float inventory_screen_position_x, float inventory_screen_position_y);
   ~InventoryItemRenderComponent();

   void set_state(state_t new_state);
   void draw();
};


