#pragma once



#include <models/entities/entity_base.hpp>



class DoorEntity : public EntityBase
{
public:
   DoorEntity(ElementID *parent, std::string name, int destination_scene, std::string destination_door_name, ALLEGRO_BITMAP *door_img, float x, float y);
};



