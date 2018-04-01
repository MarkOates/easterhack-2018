


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
   , cursor(0)
   , selector(0)
   , inventory_screen_render_component(this, display)
{
}



InventoryScreen::~InventoryScreen()
{}



int InventoryScreen::get_num_items()
{
   return rows * columns;
}



int InventoryScreen::get_selected_item()
{
   if (!inventory) throw std::runtime_error("InventoryScreen: cannot get_selected_item() with a nullptr inventory");
   return inventory->get_ordered_item(selector);
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
   cursor = (cursor - columns + get_num_items()) % get_num_items();
   inventory_screen_render_component.set_hilighted(cursor);
}



void InventoryScreen::move_cursor_down()
{
   cursor = (cursor + columns) % get_num_items();
   inventory_screen_render_component.set_hilighted(cursor);
}



void InventoryScreen::move_cursor_left()
{
   cursor = (cursor + 1 + get_num_items()) % get_num_items();
   inventory_screen_render_component.set_hilighted(cursor);
}



void InventoryScreen::move_cursor_right()
{
   cursor = (cursor - 1 + get_num_items()) % get_num_items();
   inventory_screen_render_component.set_hilighted(cursor);
}



void InventoryScreen::select_item_at_cursor()
{
   selector = cursor;
   inventory_screen_render_component.set_selected(selector);
}



void InventoryScreen::update(float time_now)
{
   motion.update(time_now);
}



void InventoryScreen::draw(Display *display)
{
   inventory_screen_render_component.draw();
}



