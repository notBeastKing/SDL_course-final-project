#include<screen.h>


namespace create
{
    bool screan::draw() // updating and displaying and rendering textures
    {
        SDL_UpdateTexture(m_texturewin, NULL, m_buffer, m_width * sizeof(Uint32)); // use this function only when you need 
                                                                                // to use pixel access 
        SDL_RenderClear(m_renderwin);
        SDL_RenderCopy(m_renderwin,m_texturewin,NULL, NULL);
        SDL_RenderPresent(m_renderwin);
        
         cout<<SDL_GetError()<<"\n";

        return true;
    }


     bool screan::drawbg()
    {
         SDL_RenderClear(m_renderwin);
         SDL_RenderPresent(m_renderwin);

         return true;
    }


    
    bool screan::  setbgcolour(Uint8 r, Uint8 g, Uint8 b )
    {
        SDL_SetRenderDrawColor(m_renderwin,r,g,b,255);

         return true;
    }


    void screan::setbufferfg(int b1, int g1, int r1, int w, int h) //setting buffer for pixel access(ie giving the buffer 
                                                                    // to the texture update function)
    {
        if(w < 0 || w >= m_width || h < 0 || h >= m_height)
        {
            return;
        }
        Uint8 alpha = 0x00;
        int colour = 0;
        
        colour +=alpha;
        colour <<=8;
        colour +=b1;
        colour <<=8;
        colour +=g1;
        colour <<=8;
        colour +=r1;
        
       

        m_buffer[(h * m_width) + w] = colour; 
        //here we are multiplying the height with the width to go to the right row and then adding the 
        //width we want to that it goes to the right coloumn and hence it goes to the right co ordinates
        // eg if we give the co ords 50,50, 50 * width(1300) = the first pixel in the 50th row i,e 65000th, pixel on the screen
        // and when weadd 50 to it it'll reach the 50,50 co ordinate
    }

    bool screan::bgcolort(int r1,int g1,int b1)
    {
        Uint8 alpha = 0x00;
        int colour = 0;
        
        colour +=alpha;
        colour <<=8;
        colour +=b1;
        colour <<=8;
        colour +=g1;
        colour <<=8;
        colour +=r1;

        for(int i = 0; i<m_width*m_height; i++)
        {
            m_buffer[i] = colour;
        }
        return true;
    }


    bool screan::drawrect()
    {
        SDL_Rect rect;
            rect.x = 50;
            rect.y = 50;
            rect.w = 200;
            rect.h = 200;

        SDL_SetRenderDrawColor(m_renderwin, 200, 137, 255, 255);
        SDL_RenderFillRect(m_renderwin, &rect);
        SDL_RenderDrawRect(m_renderwin, &rect);
         SDL_RenderPresent(m_renderwin);

         return true;
    }

}