

#include <render_components/inventory_screen_render_component.hpp>

#include <allegro5/allegro_primitives.h>
#include <framework/display.hpp>
#include <framework/color.hpp>
#include <models/inventory_screen.hpp>
#include <item_type_nums.hpp>



InventoryScreenRenderComponent::InventoryScreenRenderComponent(InventoryScreen *inventory_screen, Display *display)
   : inventory_screen(inventory_screen)
   , display(display)
   , fonts()
   , title(TextObject("Inventory"))
   , item_render_components()
{
   ALLEGRO_FONT *font = fonts["ChronoTrigger.ttf 60"];

   title.font(font)
      .align(0.5, 1.1)
      .scale(1, 1)
      .position(display->center(), display->middle()-100);

   int spacing = 150;
   int center = display->width() / 2;
   int top_row = display->height() / 6 * 3;
   int bottom_row = display->height() / 6 * 4;

   item_render_components.push_back(new InventoryItemRenderComponent(ITEM_TYPE_CLUB, 0, center - spacing*-2, top_row));
   item_render_components.push_back(new InventoryItemRenderComponent(ITEM_TYPE_STONE_OF_DEFIANCE, 1, center - spacing*-1, top_row));
   item_render_components.push_back(new InventoryItemRenderComponent(ITEM_TYPE_NAUGHTY_LIST, 2, center - spacing*+0, top_row));
   item_render_components.push_back(new InventoryItemRenderComponent(ITEM_TYPE_SILVER_SHIELD, 3, center - spacing*+1, top_row));
   item_render_components.push_back(new InventoryItemRenderComponent(ITEM_TYPE_GOLDEN_SHIELD, 4, center - spacing*+2, top_row));

   item_render_components.push_back(new InventoryItemRenderComponent(ITEM_TYPE_SILVER_SWORD, 5, center - spacing*-2, bottom_row));
   item_render_components.push_back(new InventoryItemRenderComponent(ITEM_TYPE_GOLDEN_SWORD, 6, center - spacing*-1, bottom_row));
   item_render_components.push_back(new InventoryItemRenderComponent(ITEM_TYPE_KEY, 7, center - spacing*+0, bottom_row));
   item_render_components.push_back(new InventoryItemRenderComponent(ITEM_TYPE_NONE, 8, center - spacing*+1, bottom_row));
   item_render_components.push_back(new InventoryItemRenderComponent(ITEM_TYPE_NONE, 9, center - spacing*+2, bottom_row));
}


InventoryScreenRenderComponent::~InventoryScreenRenderComponent()
{
   for (auto &item_render_component : item_render_components) delete item_render_component;
}


void InventoryScreenRenderComponent::set_hilighted(int box_num)
{
   for (auto &item_render_component : item_render_components)
   {
      if (item_render_component->is_box_num(box_num)) item_render_component->set_hilighted();
      else item_render_component->set_hilighted(false);
   }
}


void InventoryScreenRenderComponent::set_selected(int box_num)
{
   for (auto &item_render_component : item_render_components)
   {
      if (item_render_component->is_box_num(box_num)) item_render_component->set_selected();
      else item_render_component->set_selected(false);
   }
}


void InventoryScreenRenderComponent::draw()
{
   if (!inventory_screen) throw std::runtime_error("InventoryScreenRenderComponent::draw(): cannot draw() on a nullptr inventory_screen");
   if (!display) throw std::runtime_error("InventoryScreenRenderComponent::draw(): cannot draw() on a nullptr display");

   float padding = 40;
   al_draw_filled_rectangle(padding, padding, display->width()-padding, display->height()-padding, color::black);
   title.draw();

   for (auto &item_render_component : item_render_components) item_render_component->draw();
}


