#include "../kipr/botball.h"
#include "camerafunc.h"

Camera CAM;

typedef struct {
    char x = 'x';
    char y = 'y';
    char z = 'z';
} Axes;
extern Axes gAxes;

void setupCamera(const char* config)
{
    CAM.camera_height_mm = 100;
    CAM.std_object_height_mm = 30;

    camera_open_black();
    
    if(camera_open_black() != 1)
        return;

    camera_load_config(config);
    
    CAM.cameraEnabled = true;
}

int getDimensions(char axis, int channel, int object)
{
    switch(axis)
    {
        case gAxes.x: return get_object_bbox_width(channel, object);
        case gAxes.y: return get_object_bbox_height(channel, object);
        default: break;
    } 
    return 0;
}

int calcDist()
{
    return (CAM.std_object_height_mm * get_camera_height()) / (getDimensions(y, 0, 0));
}

// Main function of the camera. Use this in score().
void runCamera()
{
    if(!CAM.cameraEnabled)
        return;

    while(!CAM.cameraEnabled)
    {
        
    }
         
    camera_close();    
}