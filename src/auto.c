#include "main.h"

 int lCounts = encoderGet(lDrive);
 int rCounts = encoderGet(rDrive);


 void goSet(int left, int right)
 {
 		motorSet(frontRight_p, right);
 		motorSet(backRight_p, right);
 		motorSet(frontLeft_p, left);
 		motorSet(backLeft_p, left);
 }

void autonomous(){
  // if(digitalRead(starAuton_p) == 0) {
  //   goSet(-80, 127); //driving forward
  //   delay(1800); // driving forward for three seconds
  //   goSet(0, 0); // stop driving
  //   armSet(127); //arm goes up
  //   clawSet(-107); // claw begins to open.
  //   delay(1000); //arm up for one second
  //   armSet(0); // arm stop
  //   clawSet(0);
  //   armSet(-127);
  //   delay(1000);
  //   armSet(0);
  // }

  // Knock over Forward - 8.5 Seconds
  /*goSet(127, 127); //driving forward
  delay(3000); // driving forward for three seconds
  goSet(0, 0); // stop driving
  armSet(127); //arm goes up
  delay(1000); //arm up for one second
  armSet(0); // arm stop
  clawSet(1127); // claw begins to open.
  delay(500); // begin to open claw to half open position
  clawSet(0); // claw stops after half a second
  goSet(127, 127); // drive forward again
  delay(3500); // drive forward for three and a half seconds
  goSet(0, 0); //drive stop
  goSet(-127, -127); // go backwards for half a second
  delay(500); // forward for half a second
  goSet(127, 127); // go back for three quarters of a second
  */

  //if (digitalRead(cubeAndStar_p) == 0) {
  // Cube Over - 12.725 Seconds
  /*armSet(127);
  delay(100);
  armSet(0);
  armSet(-127);
  delay(120);
  armSet(0);
  goSet(127, -127);
  clawSet(-127);
  delay(400);
  clawSet(0);
  delay(450);
  goSet(0, 0);
  clawSet(-127);
  delay(500);
  armSet(127);
  goSet(-127, -127);
  armSet(60);
  delay(200);
  goSet(-127, 127);
  delay(300);
  armSet(127);
  clawSet(127);
  delay(600);
  goSet(0, 0);
  armSet(0);
  clawSet(0);
  */
//}
  //if (digitalRead(cubeAndStar_p) == 0) {
    // goSet(-127, 80); //driving forward
    // delay(1800); // driving forward for three seconds
    // goSet(0, 0); // stop driving
    // armSet(127); //arm goes up
    // clawSet(-107); // claw begins to open.
    // delay(1000); //arm up for one second
    // armSet(0); // arm stop
    // clawSet(0);
    // armSet(-127);
    // delay(1000);
    // armSet(0);
  //}

  if (digitalRead(skillsAuton_p) == 0) {
    encoderReset(lDrive);
    encoderReset(rDrive);

}
  //Base Stars - 10.35 seconds
  /*armSet(127); // arm up
  delay(1000);
  armSet(0); // arm stop
  clawSet(1127); // claw open
  delay(750);
  clawSet(0); // claw stop
  armSet(-127); // lift down
  delay(1100);
  armSet(0); // lift stop
  goSet(127, 127); // go forward
  delay(1750);
  goSet(0, 0); // stop drive
  clawSet(1127); // claw close
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
  */
}
