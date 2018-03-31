


#include <controllers/player_krampus_controller.hpp>

#include <framework/screens/gamer_input_screen.hpp>
#include <framework/useful.hpp> // for key_pressed()



PlayerKrampusController::PlayerKrampusController()
   : krampus(nullptr)
{}



void PlayerKrampusController::set_krampus(KrampusEntity *new_krampus)
{
   krampus = new_krampus;
}



bool PlayerKrampusController::has_a_krampus()
{
   return krampus != nullptr;
}



void PlayerKrampusController::on_key_down(int input_button)
{
   if (!has_a_krampus()) return;

   switch(input_button)
   {
   case GAMER_BUTTON_A: krampus->attack(); break;
   case GAMER_BUTTON_C: krampus->use_stone_of_defiance(); break;
   default: break;
   }
}



void PlayerKrampusController::on_key_up(int input_button)
{
   if (!has_a_krampus()) return;

   switch(input_button)
   {
   case GAMER_BUTTON_UP: krampus->stand_still(); break;
   case GAMER_BUTTON_DOWN: krampus->stand_still(); break;
   case GAMER_BUTTON_RIGHT: krampus->stand_still(); break;
   case GAMER_BUTTON_LEFT: krampus->stand_still(); break;
   default: break;
   }
}



void PlayerKrampusController::update_polled_keyboard_input()
{
   if (krampus->is_idle())
   {
      if (key_pressed(ALLEGRO_KEY_RIGHT)) krampus->walk_right();
      if (key_pressed(ALLEGRO_KEY_LEFT)) krampus->walk_left();
      if (key_pressed(ALLEGRO_KEY_UP)) krampus->walk_up();
      if (key_pressed(ALLEGRO_KEY_DOWN)) krampus->walk_down();
   }
}



