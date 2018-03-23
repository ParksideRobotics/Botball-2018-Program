#include "score.h"
#include "util.h"
#define FORWARD 0
#define BACKWARD 1

#define TURN_COUNT 2500

void score()
{
    printf("skips 2 lines\n");
    skipLine(FORWARD, 2);

    printf("forward 6 milliseconds\n");
    moveForward(100,6);

    printf("not tracking spin right\n");
    while(!isTracking())
        spinRight(100, 1);

    printf("tracking spin right\n");
    while(isTracking())
        spinRight(100, 1);

    printf("not tracking move forward\n");
    while(!isTracking())
        moveForward(100, 1);

    printf("tracking move forward\n");
    while(isTracking())
        moveForward(100,1);

    printf("not tracking move forward\n");
    while(!isTracking())
        moveForward(100,1);

    printf("open claw\n");
    openClaw();

	while(isTracking())
    	moveForward(100,1);

    printf("close claw\n");
    closeClaw();

    skipLine(0,1);

}
