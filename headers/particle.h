#ifndef SCREEN3__
#define SCREEN3__

namespace create2{
class particle
{
    public:
        double m_x;
        double m_y;
       double m_speed;
       double m_direction;
        void update(int interval);
        void update1();
        void init();
        particle();
    private:
       
};
}

#endif