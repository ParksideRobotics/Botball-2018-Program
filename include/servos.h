#ifndef SERVOS_H_
#define SERVOS_H_

#include "../kipr/botball.h"

#define SERVO_CLAW 0

typedef struct Servos {
    void (*openClaw)(void);
    void (*closeClaw)(void);
} Servos;
Servos SERVOS;

//void openClaw();
//void closeClaw();

#endif /* SERVOS_H_ */