#include "chassis.h"

void moveForward(int distance) {
    printf("Moving forward for distance %d", distance);
    int dist = 0;
    while(dist < distance) {
        moveForward(100,1);
        dist = get_motor_position_counter(LEFT_MOTOR);
        printf("...%d", dist);
    }
    printf("\n");
    #ifdef __DEBUG
    stopWait();
    #endif
}

void moveBackward(int distance) {
    printf("Moving backwards for distance %d", distance);
    int dist = distance;
    while(dist > 0) {
        moveBackward(100,1);
        dist = get_motor_position_counter(LEFT_MOTOR);
        printf("...%d", dist);
    }
    printf("\n");
    #ifdef __DEBUG
    stopWait();
    #endif
}
void moveForward(int speed, int time)
{
    motor(LEFT_MOTOR, speed);
    motor(RIGHT_MOTOR, speed);
	msleep(time);
    motor(LEFT_MOTOR, 0);
    motor(RIGHT_MOTOR, 0);
}

void moveBackward(int speed, int time)
{
    motor(LEFT_MOTOR, speed*-1);
    motor(RIGHT_MOTOR, speed*-1);
	msleep(time);
    motor(LEFT_MOTOR, 0);
    motor(RIGHT_MOTOR, 0);
}

void spinLeft(int speed, int time)
{
    motor(LEFT_MOTOR, speed*-1);
    motor(RIGHT_MOTOR, speed);
    msleep(time);
    motor(LEFT_MOTOR, 0);
    motor(RIGHT_MOTOR, 0);
}

void spinRight(int speed, int time)
{
    motor(LEFT_MOTOR, speed);
    motor(RIGHT_MOTOR, speed*-1);
    msleep(time);
    motor(LEFT_MOTOR, 0);
    motor(RIGHT_MOTOR, 0);
}


void veerRight(int speed, int veerOffset, int time)
{
    motor(LEFT_MOTOR, speed);
    motor(RIGHT_MOTOR, speed-veerOffset);
    msleep(time);
    motor(LEFT_MOTOR, 0);
    motor(RIGHT_MOTOR, 0);
}

void veerLeft(int speed, int veerOffset, int time)
{
    motor(RIGHT_MOTOR, speed);
    motor(LEFT_MOTOR, speed-veerOffset);
    msleep(time);
    motor(LEFT_MOTOR, 0);
    motor(RIGHT_MOTOR, 0);
}

void turnLeft(int speed, int time)
{
    motor(LEFT_MOTOR, speed*-0.85);
    msleep(time);
    motor(LEFT_MOTOR, 0);
}

void turnRight(int speed, int time)
{
    motor(RIGHT_MOTOR, speed*-0.85);
    msleep(time);
    motor(RIGHT_MOTOR, 0);
}

