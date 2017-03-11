#include "main.h"

void goSet(int left, int right)
{
   motorSet(frontRight_p, right);
   motorSet(backRight_p, right);
   motorSet(frontLeft_p, left);
   motorSet(backLeft_p, left);
}

void armWait(int angle)
{
  if(angle > 0)
  {
    while(encoderGet(liftEnc) < angle)
    {
      delay(20);
    }
  }
  else
  {
    while(encoderGet(liftEnc) > angle)  {
      delay(20);
    }
  }
}

void clawWait(int target){
  int right = analogRead(rightClawPot_p);
  int left = analogRead(leftClawPot_p);
  while((abs(right-target)>20)&&(abs(left-target)>20)){
    right = analogRead(rightClawPot_p);
    left = analogRead(leftClawPot_p);
    int rPower = right - target;
    int lPower = left - target;
    if(rPower > 127) rPower = 127;
    if(rPower < -127) rPower = -127;
    if(lPower > 127) lPower = 127;
    if(lPower < -127) lPower = -127;
    motorSet(rightClaw_p, rPower);
    motorSet(leftClaw_p, -lPower);
    clawSet(0);
  }
}


void driveWait(int ticks)
{
  encoderReset(lDrive);
  encoderReset(rDrive);

  if(ticks > 0)
  {
    while(encoderGet(lDrive) < ticks || encoderGet(rDrive) < ticks)
    {
      delay(20);
    }
  }
  else
  {
    while(encoderGet(lDrive) > ticks || encoderGet(rDrive) > ticks)
    {
      delay(20);
    }
  }
}

void dump()
{
  armSet(127);
  armWait(150);
  goSet(-100, 100);
  armWait(360);
  clawWait(1200);
  armSet(0);
  goSet(0, 0);
  delay(1000);
  armSet(-127);
  armWait(10);
  armSet(0);
}

void goForward()
{
  goSet(127, -127);
}

void goBack()
{
  goSet(-127, 127);
}

void goLeft()
{
  goSet(100, 100);
}

void goRight()
{
  goSet(-100, -100);
}

void goStop()
{
    goSet(0, 0);
}


void autonomous()
{
  goBack();
  driveWait(-100);
  goStop();
  clawWait(1200);
  goForward();
  driveWait(100);
  goStop();
  clawWait(500);
  goBack();
  driveWait(150);
  goStop();
  dump();
}


// goSet(-127, 127);
// delay(750);
// goSet(0, 0);
// clawSet(127);
// goSet(127, -127);
// delay(750);
// goSet(0, 0);
// clawSet(0);
// dump();
