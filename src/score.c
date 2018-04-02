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

    int motor_0 = get_motor_position_counter(0);
    while(motor_0 < 20)
    {
        moveForward(100,1);
        motor_0 = get_motor_position_counter(0);
    }
    int motor_1 = get_motor_position_counter(1);
    printf("%d %d \n", motor_0, motor_1);

    stopWait();

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
    motor_0 = get_motor_position_counter(0);
    while(motor_0 < 5150)
    {
        moveForward(100,1);
        motor_0 = get_motor_position_counter(0);
    }
    motor_1 = get_motor_position_counter(1);
    printf("%d %d \n", motor_0, motor_1);


    //step 7 tracking = move forward
    printf("tracking move forward\n");
    /*while(isTracking())
        moveForward(100,1);*/
    motor_0 = get_motor_position_counter(0);
    while(motor_0 < 3207)
    {
        moveForward(100,1);
        motor_0 = get_motor_position_counter(0);
    }
    motor_1 = get_motor_position_counter(1);
    printf("%d %d \n", motor_0, motor_1);

    stopWait();

    /* printf("not tracking move forward\n");		//not tracking = move forward
    while(!isTracking())
        moveForward(100,1);*/


    printf("Tracking move forward\n");		//step 8 tracking = move forward
    /*while(isTracking())
        moveForward(100,1);*/
    motor_1 = get_motor_position_counter(1);
    while(motor_1 < 1015)    
    {
        moveForward(100,1);
        motor_1 = get_motor_position_counter(1);
    }    
    motor_0 = get_motor_position_counter(0);           
    printf("%d %d \n", motor_0, motor_1);

    printf("close claw\n");		//step 9 close claw
    closeClaw();

    printf("move backwards 2 seconds\n");		//step 10 move backwards 2 seconds
    //moveBackward(100,2000);
    motor_0 = get_motor_position_counter(0);
    while(motor_0 > 3880)
    {    
        moveBackward(100,1);
        motor_0 = get_motor_position_counter(0);   
    }
    motor_1 = get_motor_position_counter(1);
    printf("%d %d \n", motor_0, motor_1);

    stopWait();

    printf("turn left\n");		//step 11 turn left
    spinLeft(100,2000);

    printf("move forward using ticks\n");		//step 12 move forwards 2.7 seconds 
    //moveForward(100,2700);
    motor_1 = get_motor_position_counter(0);
    while(motor_1 < 3880)
    {
        moveForward(100,1);
        motor_1 = get_motor_position_counter(0);   
    }

    motor_1 = get_motor_position_counter(1);
    printf("%d %d \n", motor_0, motor_1);


    stopWait();

    printf("open claw\n");		//step 13 open claw
    openClaw();

    stopWait();

    printf("move backwards 2.7 seconds\n");		//step 14 move backwards 2.7 seconds
    // moveBackward(100,2700);
    motor_1 = get_motor_position_counter(1);
    while(motor_1 > 3915)
    {    
        moveBackward(100,1);   
        motor_1 = get_motor_position_counter(1);   
    }
    motor_0 = get_motor_position_counter(0);
    printf("%d %d \n", motor_0, motor_1);


    printf("turn right\n");		//step 15 turn right 
    spinRight(100,1600);

    stopWait();

    printf("move forward 2.2 seconds\n");		//step 16 move forward 2.2 seconds
    //moveForward(100,2200);
    motor_0 = get_motor_position_counter(0);
    while(motor_0 < 3880)
    {    
        moveForward(100,1);   
        motor_0 = get_motor_position_counter(0);   
    }
    motor_1 = get_motor_position_counter(1);
    printf("%d %d \n", motor_0, motor_1);

    stopWait();

    printf("move forward 2 milliseconds\n");		//step 17 move forward 2 milliseconds
    //moveForward(100,20);
    motor_0 = get_motor_position_counter(0);
    while(motor_0 < 3880)
    {    
        moveForward(100,1);   
        motor_0 = get_motor_position_counter(0);   
    }    
    motor_1 = get_motor_position_counter(1);
    printf("%d %d \n", motor_0, motor_1);

    printf("close claw\n");		//step 18 close claw
    closeClaw();

    stopWait();

    printf("move backwards 3 seconds\n");		//step 19 move backwards 3 seconds
    //moveBackward(100,3000);
    motor_1 = get_motor_position_counter(1);
    while(motor_1 > 3915)
    {    
        moveBackward(100,1);   
        motor_1 = get_motor_position_counter(1);   
    } 
    motor_0 = get_motor_position_counter(0);
    printf("%d %d \n", motor_0, motor_1);

    printf("turn left\n");		//step 20 turn left
    spinLeft(100,2000);

    printf("move forward 2.7 seconds\n");		//step 21 move forward 2.7 seconds
    //moveForward(100,2700);
    motor_1 = get_motor_position_counter(1);
    while(motor_1 < 3915)
    {
        moveForward(100,1);
        motor_1 = get_motor_position_counter(1);
    }
    motor_0 = get_motor_position_counter(0);
    printf("%d %d \n", motor_0, motor_1);

    stopWait();

    printf("open claw\n");		//step 22 open claw
    openClaw();

    printf("move backwards 2.7 seconds\n");		//step 23 move backwards 2.7 seconds
    //moveBackward(100,2700);
    motor_0 = get_motor_position_counter(0);
    while(motor_0 > 3880)
    {
        moveBackward(100,1);   
        get_motor_position_counter(0);   
    }    
    motor_1 = get_motor_position_counter(1);
    printf("%d %d \n", motor_0, motor_1);

    stopWait();

    printf("turn right\n");		//step 24 turn right
    spinRight(100,1500);

    printf("move forward 3.2 seconds\n");		//step 25 move forward 3.2 seconds
    //moveForward(100,3200);
    motor_1 = get_motor_position_counter(1);
    while(motor_1 < 3915)
    {    
        moveForward(100,1);   
        motor_1 = get_motor_position_counter(1);   
    }    
    motor_0 = get_motor_position_counter(0);
    printf("%d %d \n", motor_0, motor_1);

    stopWait();

    printf("open claw\n");		//step 26 open claw
    openClaw();

    printf("move forward 2 milliseconds\n");		//step 27 move forward 2 milliseconds
    //moveForward(100,20);
    motor_0 = get_motor_position_counter(0);
    while(motor_0 < 3880)
    {    
        moveForward(100,1);   
        motor_0 = get_motor_position_counter(0);   
    }
    motor_1 = get_motor_position_counter(1);
    printf("%d %d \n", motor_0, motor_1);

    printf("close claw\n");		//step 28 close claw
    closeClaw();



























}