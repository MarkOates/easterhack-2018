


#include <models/inventory.h>

#include <sstream>



Inventory::Inventory()
   : items()
{}



void Inventory::add_item(int item_type)
{
   items.push_back(item_type);
}



bool Inventory::has_item(int item_type)
{
   for (unsigned i=0; i<items.size(); i++)
      if (items[i] == item_type) return true;
   return false;
}



std::string Inventory::get_str()
{
   std::stringstream result;
   for (auto &i : items)
   {
      result << i << " ";
   }
   return result.str();
}



