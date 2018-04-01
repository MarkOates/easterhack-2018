#pragma once



#include <motion_fx/motion_fx_base.hpp>
#include <vector>



class MotionFXManager
{
public:
   std::vector<MotionFXBase *> motion_fx;
   void update();
   void draw();
   void add_motion_fx(MotionFXBase *motion_fx);
};



