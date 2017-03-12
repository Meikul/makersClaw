#include "main.h"
#include <math.h>

void goSet(int left, int right)
{
   motorSet(frontRight_p, right);
   motorSet(backRight_p, right);
   motorSet(frontLeft_p, left);
   motorSet(backLeft_p, left);
}

void armWait(int angle)
{
  encoderReset(liftEnc);
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
  goSet(-70, 70);
  armWait(300);
  clawSet(127);
  delay(300);
  goSet(0, 0);
  clawWait(1200);
  armSet(0);
  goSet(0, 0);
  delay(300);
  armSet(-127);
  armWait(-360);
  armSet(0);
}

void goBack()
{
  goSet(-127, 127);
}

void goForward()
{
  goSet(127, -127);
}

void goLeft()
{
  goSet(-100, -100);
}

void goRight()
{
  goSet(100, 100);
}

void goStop()
{
    goSet(0, 0);
}

void rampDown()
{
  int begSpeed = motorGet(3);
  int fSpeed = begSpeed;
  int sign = begSpeed/abs(begSpeed);
  begSpeed = abs(begSpeed);

  for(int i = 0; abs(fSpeed)>10; i++)
  {
    // fSpeed = (begSpeed - ((begSpeed/4) * log(i)))*sign;
    fSpeed = (begSpeed - (i*(begSpeed/4)))*sign;
    goSet(fSpeed, -fSpeed);
    delay(20);
  }
  goSet(0, 0);
}

void autonomous()
{
  goBack();
  armSet(127);
  delay(200);
  armSet(0);
  clawSet(-127);
  delay(230);
  rampDown();
  clawWait(1200);
  goForward();
  for(int i = 0; i<3; i++)
  {
    delay(250);
    rampDown();
    clawSet(-127);
    delay(500);
    goBack();
    delay(350);
    dump();
    goForward();
    delay(950);
    goStop();
  }
  delay(750);
  armSet(-127);
  armWait(0);
  goLeft();
  delay(500);
  goStop();
  clawSet(127);
  clawWait(850);
  clawSet(0);
  goForward();
  delay(1000);
  rampDown();
  clawSet(-127);
  clawWait(500);
  goRight();
  delay(505);
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
