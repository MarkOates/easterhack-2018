#pragma once


class MotionFXBase
{
public:
   float x, y;
   bool finished;

   MotionFXBase(float x, float y);
   virtual ~MotionFXBase();

   bool is_finished();
   virtual void start();
   virtual void update();
   virtual void draw();
};



