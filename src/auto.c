/** @file auto.c
 * @brief File for autonomous code
 *
 * This file should contain the user autonomous() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"

/*
 * Runs the user autonomous code. This function will be started in its own task with the default
 * priority and stack size whenever the robot is enabled via the Field Management System or the
 * VEX Competition Switch in the autonomous mode. If the robot is disabled or communications is
 * lost,  the autonomous task will be stopped by the kernel. Re-enabling the robot will restart
 * the task, not re-start it from where it left off.
 *
 * Code running in the autonomous task cannot access information from the VEX Joystick. However,
 * the autonomous function can be invoked from another task if a VEX Competition Switch is not
 * available, and it can access joystick information if called in this way.
 *
 * The autonomous task may exit, unlike operatorControl() which should never exit. If it does
 * so, the robot will await a switch to another mode or disable/enable cycle.
 */

 void driveSet(int left, int right)
 {
 		motorSet(frontRight_p, right);
 		motorSet(backRight_p, right);
 		motorSet(frontLeft_p, left);
 		motorSet(backLeft_p, left);
 }

 void armSet(int power)
 {
 	motorSet(topLeftLift_p, -power);
 	motorSet(bottomLeftLift_p, power);
 	motorSet(topRightLift_p, power);
 	motorSet(bottomRightLift_p, -power);
 }

 void clawSet(int power)
 {
   motorSet(rightClaw_p, -power);
   motorSet(leftClaw_p, power);
 }

void autonomous()
{
  driveSet(127, 127);
  delay(3000);
  driveSet(0, 0);
  armSet(127);
  delay(1000);
  armSet(0);
  clawSet(127);
  delay(500);
  driveSet(127, 127);
  delay(3500);
  driveSet(-127, -127);
  delay(1000);
  driveSet(127, 127);
}
