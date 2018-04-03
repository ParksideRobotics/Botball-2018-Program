#include "score.h"
#include "util.h"
#define FORWARD 0
#define BACKWARD 1


void score()
{

    //wait_for_light(1);

    printf("skips 2 lines\n");		//step 1 skips 2 lines
    skipLine(FORWARD, 2);

    stopWait();

    printf("move until 40 ticks\n"); //step 2 forwards 6 milliseconds
    clear_motor_position_counter(0);
    clear_motor_position_counter(1);
    //moveForward(100,10);

    moveForward(20);

    printf("open claw\n");		//step 3 open claw
    openClaw();

    printf("not tracking spin right-- finds left edge\n");		
    while(!isTracking())	//step 4 not tracking = turn right -- finds left edge
	    spinRight(100, 1);
    
    stopWait();

    printf("tracking spin right-- finds right edge\n");		
    while(isTracking())					//step 5 tracking = turn right -- finds left edge
        spinRight(100, 1);

    printf("not tracking move forward\n");		
    //step 6 not tracking = move forward
    /*while(!isTracking())
        moveForward(100, 1);*/

    moveForward(5150);

    //step 7 tracking = move forward
    printf("tracking move forward\n");
    /*while(isTracking())
        moveForward(100,1);*/

    moveForward(3207);

    /* printf("not tracking move forward\n");		//not tracking = move forward
    while(!isTracking())
        moveForward(100,1);*/


    printf("Tracking move forward\n");		//step 8 tracking = move forward
    /*while(isTracking())
        moveForward(100,1);*/

    moveForward(1015);

    printf("close claw\n");		//step 9 close claw
    closeClaw();

    moveBackward(3880);

    stopWait();

    printf("turn left\n");		//step 11 turn left
    spinLeft(100,2000);

    printf("move forward using ticks\n");		//step 12 move forwards 2.7 seconds 
    //moveForward(100,2700);

    moveForward(3880);

    printf("open claw\n");		//step 13 open claw
    openClaw();

    stopWait();

    moveBackward(3915);


    printf("turn right\n");		//step 15 turn right 
    spinRight(100,1600);


    moveForward(3880);
    moveForward(3880);

    printf("close claw\n");		//step 18 close claw
    closeClaw();


    moveBackward(3915);

    printf("turn left\n");		//step 20 turn left
    spinLeft(100,2000);

    moveForward(3915);

    stopWait();

    printf("open claw\n");		//step 22 open claw
    openClaw();

    moveBackward(3880);

    printf("turn right\n");		//step 24 turn right
    spinRight(100,1500);

    moveForward(3915);

    printf("open claw\n");		//step 26 open claw
    openClaw();

    moveForward(3880);

    printf("close claw\n");		//step 28 close claw
    closeClaw();



























}