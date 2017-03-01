#include "main.h"

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
  /*armSet(127); // arm pp
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
  armSet(127); // arm up
  goSet(-127, -127); // backwards
  delay(2000);
  goSet(0, 0); // stop drive
  armSet(0); // stop arm
  clawSet(-127); // open claw
  delay(750);
  clawSet(0); // stop open
  */

  //Base Stars - 10.35 seconds
  armSet(127); // arm up
  delay(1000);
  armSet(0); // arm stop
  clawSet(127); // claw open
  delay(750);
  clawSet(0); // claw stop
  armSet(-127); // lift down
  delay(1100);
  armSet(0); // lift stop
  goSet(127, 127); // go forward
  delay(1750);
  goSet(0, 0); // stop drive
  clawSet(127); // claw close
  delay(500);
  clawSet(0); // claw stop
  armSet(127); // arm up a bit
  delay(750);
  armSet(0); // arm stop
  goSet(-127, -127); // reverse out from cube
  delay(1000);
  goSet(0, 0); // drive stop
  goSet(-127, 127); // turn left
  delay(750);
  goSet(0, 0); // stop turn
  goSet(127, 127); // drive forward
  delay(1000);
  goSet(0, 0); // stop drive
  goSet(-127, 127); // turn left to back
  delay(1000);
  goSet(0, 0); // stop turn
  goSet(-127, -127); // drive back
  armSet(127); // begin to lift
  delay(1750);
  goSet(0, 0); // stop drive
  armSet(0); // stop lift
  clawSet(-127); // claw release
  delay(750);
  clawSet(0); // claw stop
}
