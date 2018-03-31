#pragma once



#include <framework/objects/bitmap_object.h>
#include <framework/placement2d.h>
#include <framework/element_id.h>



class EntityBase : public ElementID
{
public:
   placement2d place;
   placement2d velocity;
   BitmapObject bitmap;

   EntityBase(ElementID *parent, std::string type, float x, float y);
   virtual ~EntityBase();

   virtual void update();
   virtual void draw();

   void flag_for_deletion();
   bool collides(const EntityBase &other);
};



