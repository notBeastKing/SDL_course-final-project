#include"particle.h"
#include<math.h>
#include<screen.h>
#include<iostream>
#include<stdlib.h> 
using namespace std;
namespace create2
{   
    particle::particle() {
        m_x = 0;
        m_y = 0;

        init();
    }

    void particle::init()
    {
        m_x = 0;
	    m_y = 0;
	    m_direction = (2 * M_PI * rand()) / RAND_MAX;
	    m_speed = (0.04 * rand()) / RAND_MAX;

	    m_speed *= m_speed;
    }



void particle::update(int interval)
    {
        m_direction += interval *0.003;

        double x_speed = m_speed * sin(m_direction);
        double y_speed = m_speed * cos(m_direction);

        m_x += x_speed * interval;
        m_y += y_speed * interval;

        if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1) {
		        init();
	    }

	        if(rand() < RAND_MAX/100) {
		        init();
	     }

    }




    void particle::update1( )
    {
       
        double m_speed = 0.0020*((((2.0*rand())/RAND_MAX))-1);
        double m_speed1 = 0.0020*((((2.0*rand())/RAND_MAX))-1);
        m_x += m_speed1;
        m_y += m_speed;

        if(m_x <=-1 || m_x >= 1)
        {
            m_speed1 = -m_speed1;
        }
        else if(m_y <=-1 || m_y >= 1)
        {
            m_speed = -m_speed;
        }
    }


    

}