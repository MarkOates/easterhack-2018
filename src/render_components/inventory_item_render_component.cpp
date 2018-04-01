


#include <render_components/inventory_item_render_component.hpp>

#include <allegro5/allegro_primitives.h>
#include <framework/color.hpp>



InventoryItemRenderComponent::InventoryItemRenderComponent(item_t item_type, int box_num, float inventory_screen_position_x, float inventory_screen_position_y)
   : item_type(item_type)
   , inventory_screen_position_x(inventory_screen_position_x)
   , inventory_screen_position_y(inventory_screen_position_y)
   , place(inventory_screen_position_x, inventory_screen_position_y, 80, 80)
   , count(5)
   , sprite_sheet(SPRITES_GRID_FILENAME, SPRITES_GRID_SPRITE_WIDTH, SPRITES_GRID_SPRITE_HEIGHT, SPRITES_GRID_SPRITE_SCALING)
   , bitmap(nullptr)
   , box_num(box_num)
   , selected(false)
   , hilighted(false)
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
      bitmap.bitmap(sprite_sheet.get_sprite(28));
      break;
   case ITEM_TYPE_GOLDEN_SHIELD:
      bitmap.bitmap(sprite_sheet.get_sprite(29));
      break;
   case ITEM_TYPE_SILVER_SWORD:
      bitmap.bitmap(sprite_sheet.get_sprite(30));
      break;
   case ITEM_TYPE_GOLDEN_SWORD:
      bitmap.bitmap(sprite_sheet.get_sprite(31));
      break;
   }
}



InventoryItemRenderComponent::~InventoryItemRenderComponent()
{
}



void InventoryItemRenderComponent::set_selected(bool selected)
{
   this->selected = selected;
}



void InventoryItemRenderComponent::set_hilighted(bool hilighted)
{
   this->hilighted = hilighted;
}



bool InventoryItemRenderComponent::is_box_num(int box_num)
{
   return this->box_num == box_num;
}



void InventoryItemRenderComponent::draw()
{
   place.start_transform();

   float circle_radius = place.w/3*2;

   if (selected) al_draw_filled_circle(place.w/2, place.h/2, circle_radius, color::yellow);
   else al_draw_filled_circle(place.w/2, place.h/2, circle_radius, color::midnightblue);

   if (hilighted) al_draw_circle(place.w/2, place.h/2, circle_radius, color::orange, 9);

   bitmap.draw();

   place.restore_transform();
}



