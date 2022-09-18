#ifndef SCREEN__H
#define SCREEN__H

// #pragma once

#include<SDL2/SDL.h>
#include<iostream>

using namespace std;
namespace create
{
class screan
{
     public:
        int const m_width = 900; //screen width and height
        int const m_height = 500;
        double m_x;
        double m_y;

    private:        // creating variables
        
        SDL_Window *m_window;
        SDL_Renderer *m_renderwin;
        SDL_Texture *m_texturewin;
        Uint32 *m_buffer = new Uint32[m_width * m_height];
        Uint32 *m_buffer2 =  new Uint32[m_width * m_height];

    public: //functions
    screan();

    bool createscreen();

    bool create_rend_texture();

    void setbufferfg(int color1 , int color2, int color3, int width, int height);

    void screen_update();

    bool draw();

    bool bgcolort(int r,int g, int b);

    bool setbgcolour(Uint8 red, Uint8 green, Uint8 blue);

    bool drawbg();

    void close();

    bool drawrect();

    void clear();

    void boxblur();

    
};
}


 #endif

//instead of using header gaurds we can use #pragma once