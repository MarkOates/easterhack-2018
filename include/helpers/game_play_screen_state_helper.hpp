#pragma once


class GamePlayScreen;
class GamerInputScreen;


class GamePlayScreenStateHelper
{
private:
   GamePlayScreen *game_play_screen;
   float state_counter;
   bool _can_bypass_dialogue();

public:
   GamePlayScreenStateHelper(GamePlayScreen *game_play_screen);

   void process_key_down(int input_button);
   void set_state(int new_state);
   void update_state(GamerInputScreen *gamer_input_screen);
   void draw_state();

   void update_scene();
   void draw_scene_with_camera();

   void check_for_win_or_loss_condition();
};



