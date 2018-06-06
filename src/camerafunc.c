#include "../kipr/botball.h"
#include "camerafunc.h"

Camera CAM;

#define x 'x'
#define y 'y'
#define z 'z'

// Setup Camera, defacto "constructor" of the camera "class".
// Specify config, this function doesn't do much, I just don't like using camera_open() and camera_load_config()
void setupCamera(const char* config)
{
    CAM.camera_height_mm = 100;
    CAM.std_object_height_mm = 30;

    camera_open_black();
    
    if(camera_open_black() != 1)
        return;

    camera_load_config(config);
    
    CAM.cameraEnabled = true;

    while(CAM.cameraEnabled)
        runCamera();

    camera_close();
}

// Get dimensions of an object. This is a messy function at the time.
// Will fix, but comes in handy when doing algorithims.
int getDimensions(char axis, int channel, int object)
{
    switch(axis)
    {
        case 'x': return get_object_bbox_width(channel, object); break;
        case 'y': return get_object_bbox_height(channel, object); break;
        default: break;
    } 
    return 0;
}

// Calculate Distance to an object using focal height and length algorithim. Default Function.
int calcDist()
{
    return (CAM.std_object_height_mm * get_camera_height()) / (getDimensions(y, 0, 0));
}

// Main function of the camera. Use this either in score() or run().
void runCamera()
{
    if(!CAM.cameraEnabled)
        return;
         
    //TODO: Add code. xd         
}