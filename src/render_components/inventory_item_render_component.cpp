


#include <render_components/inventory_item_render_component.hpp>

#include <allegro5/allegro_primitives.h>
#include <framework/color.hpp>



InventoryItemRenderComponent::InventoryItemRenderComponent(item_t item_type, float inventory_screen_position_x, float inventory_screen_position_y)
   : item_type(item_type)
   , inventory_screen_position_x(inventory_screen_position_x)
   , inventory_screen_position_y(inventory_screen_position_y)
   , place(inventory_screen_position_x, inventory_screen_position_y, 80, 80)
   , count(5)
   , state(STATE_UNSELECTED)
   , sprite_sheet(SPRITES_GRID_FILENAME, SPRITES_GRID_SPRITE_WIDTH, SPRITES_GRID_SPRITE_HEIGHT, SPRITES_GRID_SPRITE_SCALING)
   , bitmap(nullptr)
{
   bitmap.position(place.w/2, place.h/2)
      .align(0.5, 0.5)
      .scale(1.5);

   switch (item_type)
   {
   case ITEM_TYPE_CLUB:
      bitmap.bitmap(sprite_sheet.get_sprite(23));
      break;
   case ITEM_TYPE_STONE_OF_DEFIANCE:
      bitmap.bitmap(sprite_sheet.get_sprite(24));
      break;
   case ITEM_TYPE_NAUGHTY_LIST:
      bitmap.bitmap(sprite_sheet.get_sprite(25));
      break;
   case ITEM_TYPE_KEY:
      bitmap.bitmap(sprite_sheet.get_sprite(26));
      break;
   case ITEM_TYPE_SILVER_SHIELD:
      bitmap.bitmap(sprite_sheet.get_sprite(29));
      break;
   case ITEM_TYPE_GOLDEN_SHIELD:
      bitmap.bitmap(sprite_sheet.get_sprite(30));
      break;
   case ITEM_TYPE_SILVER_SWORD:
      bitmap.bitmap(sprite_sheet.get_sprite(31));
      break;
   case ITEM_TYPE_GOLDEN_SWORD:
      bitmap.bitmap(sprite_sheet.get_sprite(32));
      break;
   }
}



InventoryItemRenderComponent::~InventoryItemRenderComponent()
{
}



void InventoryItemRenderComponent::set_state(InventoryItemRenderComponent::state_t new_state)
{
   switch(new_state)
   {
   case STATE_UNSELECTED:
      state = STATE_UNSELECTED;
      break;
   case STATE_HILIGHTED:
      state = STATE_HILIGHTED;
      break;
   case STATE_SELECTED:
      state = STATE_SELECTED;
      break;
   }
}



void InventoryItemRenderComponent::draw()
{
   place.start_transform();

   switch(state)
   {
   case STATE_UNSELECTED:
      al_draw_filled_circle(place.w/2, place.h/2, place.h/2, color::midnightblue);
      break;
   case STATE_SELECTED:
   case STATE_HILIGHTED:
      al_draw_filled_circle(place.w/2, place.h/2, place.h/2, color::yellow);
      al_draw_circle(place.w/2, place.h/2, place.h/2, color::orange, 3);
      break;
   }

   bitmap.draw();

   place.restore_transform();
}



