#ifndef CAMERAFUNC_H_
#define CAMERAFUNC_H_

#include <kipr/botball.h>
#include <stdlib.h>
#include <stdbool.h>
#include "chassis.h"
#include "util.h"
#include "score.h"
#include "servos.h"

// Testing function pointers and structs :B1:
/*

                                       `.--:/++oooooooo+//:-.``                                      
                                `-/+syhdddddddddddddddddddddhhyo+:.`                                
                           `-/oyhddddddddddddddddddddddddddddddddddhs+:.                            
                        .:oydddddddddddddddddddddddddddddddddddddddddddhy+-`                        
                     ./shdddddddddddddhhyysssoooooooooosssyyhhdddddddddddddho:`                     
                  `:shdddddddddddhysoooooooooooooooooooooooooooosyhhddddddddddy+.                   
                ./yddddddddddhyooooooooooooooooooooooooooooooooooooooshdddddddddhs:`                
              .+hdddddddddhsoooooooooooooooooooooooooooooooooooooooooooosyddddddddds:`              
            `/hddddddddhsooooooooooooooooooooooooooooooooooooooooooooooooooshdddddddds-`            
          `:yddddddddhsooooooooooooooooooooooooooooooooooooooooooooooooooooooshdddddddho.           
         .ohdddddddhsooooooooooooooooooooooooooooooooooooooooooooooooooooooooooshdddddddy:`         
        -ydddddddhsooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooshddddddh+`        
       :hdddddddyooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooyddddddds.       
     `/hddddddhsooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooshmdddddy-      
    `/hdmddddhooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooyddddddy-     
    :hddddddyoooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooohdddddds.    
   -hdddddddssssssssyyyyyyyyyyyyyyyyyyyyyyyyyyyyyhhhhhhhhhhhhhhhhhhhhhhhhdhhyyyyyyyhdddddddddddo`   
  `sdddddddddddddddddddddddddddddddddddh/------/hmdddddddddddddddddddddddds-``````:hdddddddddddd/   
  /dddddddhhhhhhhhhhyyyyyyyhmddddddddd+`     `/hdddddddhssssssydddddddddh/`     .oddddddddddddddy.  
 .yddddddyoooooooooooooooo+ymdddddddy-      -ymdddddddmhoooooosddddddddo`     `/hmddddddddddddddd+  
 /dddddddoooooooooooooooooosddddddh+`     `+dmddddddddmyoooooooddddddy-      -sdddddddddddyhmddddy. 
`odddddmyooooooooooooooooooohdddds.      :hmdddddddddmhoooooooosdddd+`     `+ddddddddddddhoymddddh: 
.yddddddsoooooooooooooooooooohdd/      .sddddddddddddhoooooooooosdd/      -ymdddddddddddyo+sdddddd+ 
-hddddddooooooooooooooooooooooydy:`  `/hmdddddddddddyoooooooooooooyds:` `oddddddddddddhsoooodmdddds`
:dddddddooooooooooooooooooooooooshho/ymdddddddddddyoooooooooooooooooyhhshmdddddddmddysoooooohmdddds`
:dddddddooooooooooooooooooooooooooosyhdddddddhysooooooooooooooooooooooossyyhhhhyysoooooooooohmdddds`
-dddddddoooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooohmdddds`
-hddddddoooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooodddddds`
.yddddddsoooooooooooooooooooooooooooooooohhhhhhyooooooooooooooooooooooohhhhhhhooooooooooooosdddddd+ 
`odddddmyooooooooooooooooooooooooooooooooyddddddyoooooooooooooooooooooyddddddyoooooooooooo+ymddddh- 
 :hddddddoooooooooooooooooooooooooooooooooyddddddhooooooooooooooooooshddddddyoooooooooooooohmdddds` 
 `sddddddy+ooooooooooooooooooooooooooooooooydddddddhsoooooooooooooshdddddddsoooooooooooooosdddddd/  
  :hddddddoooooooooooooooooooooooooooooooooooyddddddddhyysssssyyhddddddddyoooooooooooooooodddddds`  
  `odddddmhooooooooooooooooooooooooooooooooooooyhdddddddddddddddddddddhyoooooooooooooooooydddddh-   
   .yddddddyooooooooooooooooooooooooooooooooooooosyhddddddddddddddhhysooooooooooooooooooydddddd+    
    -yddddddyooooooooooooooooooooooooooooooooooooooooossyyyyyysssooooooooooooooooooooooyddddddo`    
     :hddddddyooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooyddddddo.     
      :yddddddhsooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooohddddddo.      
       -ydddddddyoooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooosddddddd+`       
        .odddddddhsooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooshddddddh/`        
         `/hdddddddhooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooyddddddds-          
           .ohdddddddhsoooooooooooooooooooooooooooooooooooooooooooooooooooooosydddddddy/`           
            `:sddddddddhsooooooooooooooooooooooooooooooooooooooooooooooooooshdddddddh+.             
              `:sdddddddddysoooooooooooooooooooooooooooooooooooooooooooosyddddddddho.               
                `:ohddddddmddysoooooooooooooooooooooooooooooooooooooosydddddddddy+.                 
                   .+yddddddddddhhysoooooooooooooooooooooooooooossyhdddddddddhs:`                   
                     `-+yddddddddddddhhyysssoooooooooooosssyyhddddddddddddhs/.                      
                        `./shddddddddddddddddddddddddddddmmdddddddddddhy+:.                         
                            `-/oyhddddddddddddddddddddddddddddddddhs+:.`                            
                                 `.:+osyhdddddddddddddddddhhyso/-.`                                 
                                       ```.--:::////:::--.``
*/

typedef struct camera {
    bool cameraEnabled;
    int camera_height_mm;
    int std_object_height_mm;
    void (*setupCamera)(const char* config);
    void (*runCamera);
    int (*calcDist);
};
extern camera CAM;

#endif /* CAMERAFUNC_H_ */