#pragma once


class InventoryScreen;


class InventoryScreenRenderComponent
{
private:
   InventoryScreen *inventory_screen;

public:
   InventoryScreenRenderComponent(InventoryScreen *inventory_screen);
   ~InventoryScreenRenderComponent();

   void draw();
};


