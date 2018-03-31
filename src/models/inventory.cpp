


#include <models/inventory.hpp>

#include <sstream>
#include <set>



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


int Inventory::get_ordered_item(int item_index)
{
   if (items.empty()) return 0;

   std::set<int> set(items.begin(), items.end());
   items.assign(set.begin(), set.end());
   if (item_index >= set.size()) return 0;

   return *std::next(set.begin(), item_index);
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



