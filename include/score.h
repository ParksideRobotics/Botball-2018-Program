#ifndef SCORE_H_
#define SCORE_H_

#include "../kipr/botball.h"
#include <stdbool.h>
#include <stdlib.h>

#include "chassis.h"
#include "util.h"
#include "servos.h"


typedef struct Score {
    void (*score)(void);
} Score;

Score SCORE;

// void score();

#endif /* SCORE_H_ */