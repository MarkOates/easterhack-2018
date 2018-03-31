

#include <render_components/inventory_screen_render_component.hpp>

#include <allegro5/allegro_primitives.h>
#include <framework/display.hpp>
#include <framework/color.hpp>
#include <models/inventory_screen.hpp>



InventoryScreenRenderComponent::InventoryScreenRenderComponent(InventoryScreen *inventory_screen, Display *display)
   : inventory_screen(inventory_screen)
   , display(display)
   , fonts()
   , title(TextObject("Inventory"))
{
   ALLEGRO_FONT *font = fonts["ChronoTrigger.ttf 60"];

   title.font(font)
      .align(0.5, 1.1)
      .scale(1, 1)
      .position(display->center(), display->middle()-100);
}


InventoryScreenRenderComponent::~InventoryScreenRenderComponent()
{
}


void InventoryScreenRenderComponent::draw()
{
   if (!inventory_screen) throw std::runtime_error("InventoryScreenRenderComponent::draw(): cannot draw() on a nullptr inventory_screen");
   if (!display) throw std::runtime_error("InventoryScreenRenderComponent::draw(): cannot draw() on a nullptr display");

   float padding = 40;
   al_draw_filled_rectangle(padding, padding, display->width()-padding, display->height()-padding, color::black);
   title.draw();
}


