#pragma once



#include <entities/damage_zone_entity.h>
#include <entities/door_entity.h>
#include <entities/entity_base.h>
#include <entities/item_entity.h>
#include <entities/kid_entity.h>
#include <entities/krampus_entity.h>
#include <models/scene.h>



class SceneCollectionHelper
{
private:
   Scene *scene;

public:
   SceneCollectionHelper(Scene *scene);

   std::vector<EntityBase *> get_all_entities();
   std::vector<EntityBase *> get_all_entities_y_sorted();
   std::vector<KidEntity *> get_kids();
   std::vector<DamageZoneEntity *> get_damage_zones();
   std::vector<EntityBase *> get_entities_bound_in_world();
   std::vector<EntityBase *> get_all_flagged_for_deletion();
   std::vector<KidEntity *> get_kids_flagged_for_deletion();
   std::vector<DoorEntity *> get_doors();
   std::vector<ItemEntity *> get_items();
   KrampusEntity *get_krampus();
   DoorEntity *get_door(char door_name);
};



