#include "../kipr/botball.h"
#include "chassis.h"
#include "score.h"
#include "servos.h"
#include "util.h"
#include "camerafunc.h"

typedef struct Interface {
    Movement* IMove;
    Score* IScore;
    Utilites* IUtil;
    Servos* IServos;
    camera* ICamera;  
} Interface;
extern Interface gInts;