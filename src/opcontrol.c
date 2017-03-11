/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"

const unsigned int motors[128] =
{
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0, 21, 21, 21, 22, 22, 22, 23, 24, 24,
 25, 25, 25, 25, 26, 27, 27, 28, 28, 28,
 28, 29, 30, 30, 30, 31, 31, 32, 32, 32,
 33, 33, 34, 34, 35, 35, 35, 36, 36, 37,
 37, 37, 37, 38, 38, 39, 39, 39, 40, 40,
 41, 41, 42, 42, 43, 44, 44, 45, 45, 46,
 46, 47, 47, 48, 48, 49, 50, 50, 51, 52,
 52, 53, 54, 55, 56, 57, 57, 58, 59, 60,
 61, 62, 63, 64, 65, 66, 67, 67, 68, 70,
 71, 72, 72, 73, 74, 76, 77, 78, 79, 79,
 80, 81, 83, 84, 84, 86, 86, 87, 87, 88,
 88, 89, 89, 90, 90,127,127,127
};

int lin (int power)
{
	if(power > 127) power = 127;
	if(power < -127) power = -127;
	if(power >= 0) return motors[power]; // Array can't handle negatives.
	return -lin(-power);
}

int rectify(int in)
{
  if (in < -127) return -127;
  if (in > 127) return 127;
  return in;
}

void driveSet(int left, int right);
void clawControl(int left, int right);

void operatorControl() {
  bool manualClaw = true;
  bool clawClosing = false;
	while (1) {
    int clawTarget;
		// --------------Drive-------------
		driveSet(joystickGetAnalog(1, 3), -joystickGetAnalog(1, 2)); // Tank drive
		// int joyX = joystickGetAnalog(1, 1);
		// int joyY = joystickGetAnalog(1, 2);
		// driveSet(lin(joyY + joyX), lin(joyY - joyX)); // Arcade Drive




		// -------------Claw---------------
    bool clawDown = joystickGetDigital(1, 6, JOY_DOWN);
    bool clawUp = joystickGetDigital(1, 6, JOY_UP);
    bool clawAutoOpen = joystickGetDigital(1, 8, JOY_DOWN);
    if(clawUp)
    {
      clawClosing = false;
      manualClaw = true;
      clawSet(127);
    }
    else if(clawDown)
    {
      clawClosing = true;
      manualClaw = true;
      clawSet(-127);
    }
    else
    {
      if (clawClosing) clawSet(-10);
      else
      {
        if(manualClaw)
        {
          clawTarget = analogRead(rightClawPot_p);
          int Err = clawTarget - analogRead(leftClawPot_p);
          motorSet(leftClaw_p, 0.3*(Err));
          motorSet(rightClaw_p, 0);
        }
        else
        {
          int rErr = clawTarget - analogRead(rightClawPot_p);
          int lErr = clawTarget - analogRead(leftClawPot_p);
          motorSet(leftClaw_p, 0.3*(lErr));
          motorSet(rightClaw_p, 0.3*(-rErr));
        }
      }
    }
    if (clawAutoOpen)
    {
      clawClosing = false;
      manualClaw = false;
      clawTarget = 1200;
    }


    // ---------- Lift ---------
		int armUp = joystickGetDigital(1, 5, JOY_UP);
    int armDown = joystickGetDigital(1, 5, JOY_DOWN);
    long height = encoderGet(liftEnc);
    int armTarget;
    bool liftLimit = digitalRead(liftLimit_p);
    if (!liftLimit) encoderReset(liftEnc);
    if(armUp)
    {
      armSet(127);
      armTarget = height;
      if(height > 360)
      {
        clawClosing = false;
        manualClaw = false;
        clawTarget = 1200;
      }
    }
    else if(armDown)
    {
      armTarget = height;
      armSet(-127);

    }
    else
    {
      // armSet(0);
      if(height > 10 && height < 360)
      {
        armSet(0.4*(armTarget - height));
      }
      else
      {
        armTarget = height;
        armSet(0);
      }

    }
		delay(20);
	}
}

void driveSet(int left, int right)
{
		right = lin(right);
		left = lin(left);
		motorSet(frontRight_p, right);
		motorSet(backRight_p, right);
		motorSet(frontLeft_p, left);
		motorSet(backLeft_p, left);
}

// void clawControl(int lPos, int rPos)
// {
//   int lErr = rectify(lPos - analogRead(rightClawPot_p));
//   int rErr = rectify(rPos - analogRead(leftClawPot_p));
//   motorSet(leftClaw_p, lErr);
//   motorSet(rightClaw_p, rErr);
// }

void clawSet(int power)
{
	motorSet(rightClaw_p, -power);
	motorSet(leftClaw_p, power);
}

void armSet(int power)
{
	motorSet(topLeftLift_p, -power);	motorSet(bottomLeftLift_p, power);
	motorSet(topRightLift_p, power);
	motorSet(bottomRightLift_p, -power);
}
