#pragma once



#include <string>
#include <vector>



class Inventory
{
public:
   std::vector<int> items;

public:
   Inventory();

   void add_item(int item_type);
   bool has_item(int item_type);

   std::string get_str();
};



