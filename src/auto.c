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

// The only function that needs to be defined is the driveSet. It also needs to be called something other than driveSet.
// Changed name to goSet.


 void goSet(int left, int right)
 {
 		motorSet(frontRight_p, right);
 		motorSet(backRight_p, right);
 		motorSet(frontLeft_p, left);
 		motorSet(backLeft_p, left);
 }

void autonomous(){
  // Knock over Forward - 8.5 Seconds
  /*goSet(127, 127); //driving forward
  delay(3000); // driving forward for three seconds
  goSet(0, 0); // stop driving
  armSet(127); //arm goes up
  delay(1000); //arm up for one second
  armSet(0); // arm stop
  clawSet(127); // claw begins to open.
  delay(500); // begin to open claw to half open position
  clawSet(0); // claw stops after half a second
  goSet(127, 127); // drive forward again
  delay(3500); // drive forward for three and a half seconds
  goSet(0, 0); //drive stop
  goSet(-127, -127); // go backwards for half a second
  delay(500); // forward for half a second
  goSet(127, 127); // go back for three quarters of a second
  */

  // Cube Over - 9 Seconds
  armSet(127); // arm pp
  delay(500);
  armSet(0); // arm stop
  clawSet(127); // open claw
  delay(1000);
  clawSet(0); // claw stop (open to center)
  armSet(-127); // arm down to level
  delay(500);
  armSet(0); // arm stop
  goSet(127, 127); // go forward after claw is out
  delay(2000);
  goSet(0, 0); // stop drive
  clawSet(-127); // close claw on cube
  delay(1000);
  clawSet(0); // claw stop closing
  armSet(127); // arm up barely
  delay(250);
  armSet(0); // arm stop
  goSet(0, 127); // turn right 180
  delay(1000);
  goSet(0, 0); // stop turn
  armSet(127);
  goSet(-127, -127);
  delay(2000);
  goSet(0, 0);
  armSet(0);
  clawSet(127);
  delay(750);
  clawSet(0);
}
