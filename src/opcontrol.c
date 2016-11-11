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

/*
 * Runs the user operator control code. This function will be started in its own task with the
 * default priority and stack size whenever the robot is enabled via the Field Management System
 * or the VEX Competition Switch in the operator control mode. If the robot is disabled or
 * communications is lost, the operator control task will be stopped by the kernel. Re-enabling
 * the robot will restart the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the VEX Cortex will
 * run the operator control task. Be warned that this will also occur if the VEX Cortex is
 * tethered directly to a computer via the USB A to A cable without any VEX Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is available and
 * the scheduler is operational. However, proper use of delay() or taskDelayUntil() is highly
 * recommended to give other tasks (including system tasks such as updating LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop, even if empty.
 */
void operatorControl() {
	while (1) {
		// --------------Drive-------------
		driveSet(joystickGetAnalog(1, 1), joystickGetAnalog(1, 3)); // Tank drive

		// -------------Claw---------------
		if(joystickGetDigital(1, 6, JOY_DOWN)) // Close
		{
			clawSet(-127);
		}
		else if(joystickGetDigital(1, 6, JOY_UP)) // Open
		{
			clawSet(127);
		}
		else
		{
			clawSet(0);
		}
		// -------------Lift---------------
		if(joystickGetDigital(1, 5, JOY_DOWN)) // Down
		{
			armSet(-127);
		}
		else if(joystickGetDigital(1, 5, JOY_UP)) // Up
		{
			armSet(127);
			if(analogRead(pot_p) > 50) // open claw if arm is high enough to dump
			{
				clawSet(127);
			}
		}
		else
		{
			armSet(0);
		}
		delay(20);
	}
}

void driveSet(int right, int left)
{
	// Right side set to first argument. Left side set to second argument.
		motorSet(frontRight_p, right);
		motorSet(backRight_p, right);
		motorSet(frontLeft_p, left);
		motorSet(backLeft_p, left);
}

void clawSet(int motor)
{
	motorSet(rightClaw_p, motor);
	motorSet(leftClaw_p, -motor);
}

void armSet(int motor)
{
	motorSet(topLeftLift_p, -motor);
	motorSet(bottomLeftLift_p, motor);
	motorSet(topRightLift_p, motor);
	motorSet(bottomRight_p, -motor);
}
