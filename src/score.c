#include "score.h"
#include "util.h"
#define FORWARD 0
#define BACKWARD 1


void score()
{
    printf("skips 2 lines\n");		//step 1 skips 2 lines
    UTIL.skipLine(FORWARD, 2);

    #ifdef __DEBUG
    UTIL.stopWait();
    #endif

    printf("move until 40 ticks\n"); //step 2 forwards 6 milliseconds
    cmpc(0);
    cmpc(1);
    //moveForward(100,10);

    DRIVE.moveForwardA(20);

    printf("open claw\n");		//step 3 open claw
    SERVOS.openClaw();

    printf("not tracking spin right-- finds left edge\n");		
    while(!isTracking())	//step 4 not tracking = turn right -- finds left edge
	    spinRight(100, 1);
    
    #ifdef __DEBUG
    UTIL.stopWait();
    #endif

    printf("tracking spin right-- finds right edge\n");		
    while(isTracking())					//step 5 tracking = turn right -- finds left edge
        spinRight(100, 1);

    printf("not tracking move forward\n");		
    //step 6 not tracking = move forward
    /*while(!isTracking())
        moveForward(100, 1);*/

    DRIVE.moveForwardA(5150);

    //step 7 tracking = move forward
    printf("tracking move forward\n");
    /*while(isTracking())
        moveForward(100,1);*/

    DRIVE.moveForwardA(3207);

    /* printf("not tracking move forward\n");		//not tracking = move forward
    while(!isTracking())
        moveForward(100,1);*/


    printf("Tracking move forward\n");		//step 8 tracking = move forward
    /*while(isTracking())
        moveForward(100,1);*/

    DRIVE.moveForwardA(1015);

    printf("close claw\n");		//step 9 close claw
    closeClaw();

    DRIVE.moveBackwardA(3880);

    #ifdef __DEBUG
    UTIL.stopWait();
    #endif

    printf("turn left\n");		//step 11 turn left
    spinLeft(100,2000);

    printf("move forward using ticks\n");		//step 12 move forwards 2.7 seconds 
    //moveForward(100,2700);

    DRIVE.moveForwardA(3880);

    printf("open claw\n");		//step 13 open claw
    SERVOS.openClaw();

    #ifdef __DEBUG
    UTIL.stopWait();
    #endif

    DRIVE.moveBackwardA(3915);


    printf("turn right\n");		//step 15 turn right 
    DRIVE.spinRight(100,1600);


    DRIVE.moveForwardA(3880);
    DRIVE.moveForwardA(3880); // This has to be a mistake, right?

    printf("close claw\n");		//step 18 close claw
    closeClaw();


    DRIVE.moveBackwardA(3915);

    printf("turn left\n");		//step 20 turn left
    DRIVE.spinLeft(100,2000);

    DRIVE.moveForwardA(3915);

    #ifdef __DEBUG
    UTIL.stopWait();
    #endif

    printf("open claw\n");		//step 22 open claw
    SERVOS.openClaw();

    DRIVE.moveBackwardA(3880);

    printf("turn right\n");		//step 24 turn right
    DRIVE.spinRight(100,1500);

    DRIVE.moveForwardA(3915);

    printf("open claw\n");		//step 26 open claw
    SERVOS.openClaw();

    DRIVE.moveForwardA(3880);

    printf("close claw\n");		//step 28 close claw
    SERVOS.closeClaw();
}