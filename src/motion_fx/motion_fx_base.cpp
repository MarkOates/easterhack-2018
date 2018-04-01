


#include <motion_fx/motion_fx_base.hpp>



MotionFXBase::MotionFXBase(float x, float y)
   : x(x)
   , y(y)
   , finished(false)
{}



MotionFXBase::~MotionFXBase() {}



bool MotionFXBase::is_finished() { return finished; }



void MotionFXBase::start() {}



void MotionFXBase::update() {}



void MotionFXBase::draw() {}



