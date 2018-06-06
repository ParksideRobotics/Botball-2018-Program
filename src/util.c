#include <stdbool.h>
#include "util.h"
#include "chassis.h"
#include "score.h"

#define NOT_TRACKING() analog(LINE_TRACKER) < 1400
#define TRACKING() analog(LINE_TRACKER) > 1400
#define FORWARD 0
#define BACKWARD 1

void init()
{
    #ifndef __DEBUG
    wait_for_light(1);
    #endif
    enable_servos();
}

void shutDown()
{
    disable_servos();
    ao();
}

bool isTracking()
{
    if(TRACKING())
        return true;

    return false;
}

void skipLine(int direction, int linesToSkip)
{
    int i;
    for(i=0;i<linesToSkip;i++)
    {
        if(FORWARD == direction){
            while(!isTracking())
                DRIVE.moveForward(100, 1);
            while(isTracking())
                DRIVE.moveForward(100, 1);
        }
        if(BACKWARD == direction) {
            while(!isTracking())
                DRIVE.moveBackward(100, 1);          
            while(isTracking())
                DRIVE.moveBackward(100, 1);
        }
    }
}


void trackEdge()
{
    while(isTracking())
        DRIVE.veerRight(75, 10, 500);

    while(!isTracking())
        DRIVE.veerLeft(75, 10, 500);
}

void trackLine()
{
    getToPos();

    cmpc(RIGHT_MOTOR);
    cmpc(LEFT_MOTOR);

    SCORE.score();
}

void getToPos()
{

    /*
    1. Reach the first line
    2. Cross the first line
    3. Reach the second line
    4. Cross the second line
    */

    skipLine(FORWARD, 2);
    
    DRIVE.moveForward(100,6);
        

    while(!isTracking())
        DRIVE.spinRight(100, 1);
   
    while(isTracking())
        DRIVE.spinRight(100, 1);
    
    while(!isTracking())
    	DRIVE.moveForward(100, 1);    
}

void stopWait()
{
	
	alloff();
    
    wait_for_any_button();
        
    wait_for_milliseconds(1000);
      
}        
