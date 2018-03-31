#pragma once


#include <framework/objects/text_object.hpp>


class InventoryScreen;
class Display;


class InventoryScreenRenderComponent
{
private:
   InventoryScreen *inventory_screen;
   Display *display;
   FontBin fonts;
   TextObject title;

public:
   InventoryScreenRenderComponent(InventoryScreen *inventory_screen, Display *display);
   ~InventoryScreenRenderComponent();

   void draw();
};


