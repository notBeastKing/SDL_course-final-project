#ifndef SWARM__W
#define SWARM__W

#include"particle.h"
using namespace create2;
namespace create3
{
        class swarm
    {
        private:
            particle *m_particles;
            int lasttime;
        public:
        const int Nparticles = (5000);
        void update(int ela);
        swarm();
        ~swarm();

        particle *get_particles()
        {
            return m_particles;
        }
        
        

    };

}
#endif 