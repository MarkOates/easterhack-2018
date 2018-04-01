


#include <motion_fx/motion_fx_manager.hpp>



void MotionFXManager::update()
{
   for (unsigned i=0; i<motion_fx.size(); i++)
   {
      motion_fx[i]->update();
      if (motion_fx[i]->is_finished())
      {
         delete motion_fx[i];
         motion_fx.erase(motion_fx.begin()+i);
         i--;
      }
   }
}



void MotionFXManager::draw()
{
   for (unsigned i=0; i<motion_fx.size(); i++)
      motion_fx[i]->draw();
}



void MotionFXManager::add_motion_fx(MotionFXBase *motion_fx)
{
   this->motion_fx.push_back(motion_fx);
}




