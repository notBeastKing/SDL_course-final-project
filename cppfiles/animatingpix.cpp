#include<iostream>
#include<stdlib.h>
#include<screen.h>
#include<math.h>
#include<time.h>
#include"swarm.h"
#include"particle.h"

using namespace std;
using namespace create;
using namespace create2;
using namespace create3;

int main(int argc, char *argv[])
{
    srand(time(NULL));

    screan anim;

    swarm warm;

    anim.createscreen();

    anim.create_rend_texture();

    const particle *const pparticles = warm.get_particles();
     double speed = 0.0001;
while(true)
{   
    int elapsed = SDL_GetTicks();

    
    warm.update(elapsed);
    
   for(int i = 0; i <warm.Nparticles; i++)
   {
        particle particles = pparticles[i];



        int x = (particles.m_x + 1) * anim.m_width/2;
        int y = (particles.m_y  * anim.m_width/2) + anim.m_height/2;

        anim.setbufferfg(255,255,255,x,y);
   }
   anim.draw();
   anim.boxblur();
   
    SDL_Event event;

    while(SDL_PollEvent(&event))
    {
        
      if(event.type == SDL_QUIT)
        {
           anim.close();
           break;
        }
    }       
   
    
   
}

anim.close();
   
   return 0;
}