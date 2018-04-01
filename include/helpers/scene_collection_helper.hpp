#pragma once



#include <models/entities/damage_zone_entity.hpp>
#include <models/entities/door_entity.hpp>
#include <models/entities/entity_base.hpp>
#include <models/entities/item_entity.hpp>
#include <models/entities/kid_entity.hpp>
#include <models/entities/krampus_entity.hpp>
#include <models/scene.hpp>



class EnemyBase;
class KnightEntity;



class SceneCollectionHelper
{
private:
   Scene *scene;

public:
   SceneCollectionHelper(Scene *scene);

   std::vector<EntityBase *> get_all_entities();
   std::vector<EntityBase *> get_all_entities_y_sorted();
   std::vector<KidEntity *> get_kids();
   std::vector<KnightEntity *> get_knights();
   std::vector<EnemyBase *> get_enemies();
   std::vector<DamageZoneEntity *> get_damage_zones();
   std::vector<EntityBase *> get_entities_bound_in_world();
   std::vector<EntityBase *> get_all_flagged_for_deletion();
   std::vector<EnemyBase *> get_enemies_flagged_for_deletion();
   std::vector<KidEntity *> get_kids_flagged_for_deletion();
   std::vector<DoorEntity *> get_doors();
   std::vector<ItemEntity *> get_items();
   KrampusEntity *get_krampus();
   DoorEntity *get_door(char door_name);
};



