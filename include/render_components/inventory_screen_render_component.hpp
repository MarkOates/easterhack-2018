#pragma once


#include <framework/objects/text_object.hpp>
#include <render_components/inventory_item_render_component.hpp>


class InventoryScreen;
class Display;


class InventoryScreenRenderComponent
{
private:
   InventoryScreen *inventory_screen;
   Display *display;
   FontBin fonts;
   TextObject title;
   std::vector<InventoryItemRenderComponent *> item_render_components;

public:
   InventoryScreenRenderComponent(InventoryScreen *inventory_screen, Display *display);
   ~InventoryScreenRenderComponent();

   void set_hilighted(int box_num);
   void set_selected(int box_num);

   void draw();
};


