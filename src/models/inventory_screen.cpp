


#include <framework/display.hpp>
#include <emitters/user_event_emitter.hpp>
#include <models/inventory.hpp>
#include <models/inventory_screen.hpp>
#include <render_components/inventory_screen_render_component.hpp>
#include <music_track_nums.hpp>
#include <user_events.hpp>



InventoryScreen::InventoryScreen(Inventory *inventory, Display *display)
   : inventory(inventory)
   , motion()
   , display_counter(0)
   , rows(2)
   , columns(5)
   , cursor_x(0)
   , cursor_y(0)
   , selector_x(0)
   , selector_y(0)
   , inventory_screen_render_component(this, display)
{
}



InventoryScreen::~InventoryScreen()
{}



int InventoryScreen::get_selected_item()
{
   if (!inventory) throw std::runtime_error("InventoryScreen: cannot get_selected_item() with a nullptr inventory");
   return inventory->get_ordered_item(selector_y * columns + selector_x);
}



void InventoryScreen::show()
{
   UserEventEmitter::emit_event(PLAY_SOUND_EFFECT, 0, (intptr_t)(new std::string(FAIL_MOAN_SOUND_EFFECT)));
   motion.cmove_to(&display_counter, 1.0, 1.0);
}



void InventoryScreen::hide()
{
   motion.cmove_to(&display_counter, 0.0, 1.0);
}



void InventoryScreen::move_cursor_up()
{
   cursor_y = (cursor_y - 1 + rows) % rows;
}



void InventoryScreen::move_cursor_down()
{
   cursor_y = (cursor_y + 1) % rows;
}



void InventoryScreen::move_cursor_left()
{
   cursor_x = (cursor_x - 1 + rows) % rows;
}



void InventoryScreen::move_cursor_right()
{
   cursor_x = (cursor_x + 1) % rows;
}



void InventoryScreen::select_item_at_cursor()
{
   selector_x = cursor_x;
   selector_y = cursor_y;
}



void InventoryScreen::update(float time_now)
{
   motion.update(time_now);
}



void InventoryScreen::draw(Display *display)
{
   inventory_screen_render_component.draw();
}



