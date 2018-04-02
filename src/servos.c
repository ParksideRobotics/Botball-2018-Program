#include "servos.h"

void openClaw()
{
    printf("open claw\n");
    enable_servo(SERVO_CLAW);
    set_servo_position(SERVO_CLAW, 700);
}

void closeClaw()
{
    printf("close claw\n");
    enable_servo(SERVO_CLAW);
    set_servo_position(SERVO_CLAW, 00);
}

