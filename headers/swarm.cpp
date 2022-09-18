#include<swarm.h>

namespace create3
{
    swarm::swarm(): lasttime(0){
    
       m_particles = new particle[Nparticles];

    }
    swarm::~swarm()
    {
        delete [] m_particles;
    }

    void swarm::update(int elapse)
    {
        int interval = elapse - lasttime;

        for(int i = 0; i <Nparticles; i++)
            {
                 m_particles[i].update(interval);
        
            }

            lasttime = elapse;
    }
}