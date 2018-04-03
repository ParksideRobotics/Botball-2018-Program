#include <kipr/botball.h>

#define LEFT_MOTOR 0
#define RIGHT_MOTOR 1

void moveForward(int distance);

void moveBackward(int distance);

void moveForward(int speed, int time);

void moveBackward(int speed, int time);

void spinLeft(int speed, int time);

void spinRight(int speed, int time);

void veerRight(int speed, int veerOffset, int time);

void veerLeft(int speed, int veerOffset, int time);

void turnLeft(int speed, int time);

void turnRight(int speed, int time);
