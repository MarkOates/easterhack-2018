

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

   item_render_components.push_back(new InventoryItemRenderComponent(ITEM_TYPE_CLUB, center - spacing*-2, top_row));
   item_render_components.push_back(new InventoryItemRenderComponent(ITEM_TYPE_NAUGHTY_LIST, center - spacing*-1, top_row));
   item_render_components.push_back(new InventoryItemRenderComponent(ITEM_TYPE_KEY, center - spacing*+0, top_row));
   item_render_components.push_back(new InventoryItemRenderComponent(ITEM_TYPE_KEY, center - spacing*+1, top_row));
   item_render_components.push_back(new InventoryItemRenderComponent(ITEM_TYPE_KEY, center - spacing*+2, top_row));

   item_render_components.push_back(new InventoryItemRenderComponent(ITEM_TYPE_STONE_OF_DEFIANCE, center - spacing*-2, bottom_row));
   item_render_components.push_back(new InventoryItemRenderComponent(ITEM_TYPE_STONE_OF_DEFIANCE, center - spacing*-1, bottom_row));
   item_render_components.push_back(new InventoryItemRenderComponent(ITEM_TYPE_STONE_OF_DEFIANCE, center - spacing*+0, bottom_row));
   item_render_components.push_back(new InventoryItemRenderComponent(ITEM_TYPE_STONE_OF_DEFIANCE, center - spacing*+1, bottom_row));
   item_render_components.push_back(new InventoryItemRenderComponent(ITEM_TYPE_STONE_OF_DEFIANCE, center - spacing*+2, bottom_row));
}


InventoryScreenRenderComponent::~InventoryScreenRenderComponent()
{
   for (auto &item_render_component : item_render_components) delete item_render_component;
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


