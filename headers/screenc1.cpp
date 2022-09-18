#include<screen.h>
#include<iomanip>

namespace create
{
    screan::screan()
    {
        cout<<"constructor created"<<"\n";
    }
    bool screan::createscreen() //initializing video and creating a window
    {  
         if(SDL_Init(SDL_INIT_VIDEO) < 0)   {
            cout<<"video initialization didn't work"<<"\n";
                return false;
         }

            m_window = SDL_CreateWindow("anime name", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 
            m_width, m_height, SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);

            if(m_window < 0)
            {
                return false;
            }

            cout<<SDL_GetError()<<"\n";


         return true;
    }


    bool screan::create_rend_texture() //creating renderer and creating texture
    {
        m_renderwin = SDL_CreateRenderer(m_window,-1, SDL_RENDERER_ACCELERATED);
        m_texturewin = SDL_CreateTexture(m_renderwin, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STATIC, m_width,m_height);

        if(m_texturewin < 0 || m_renderwin < 0)
        {
            return false;
        }

         cout<<SDL_GetError()<<"\n";

        return true;
    }
     
    void screan::close() //closing and destroying the buffer 
    {
        delete []m_buffer;
        delete []m_buffer2;
        SDL_DestroyTexture(m_texturewin);
        SDL_DestroyRenderer(m_renderwin);
        SDL_DestroyWindow(m_window);
         cout<<SDL_GetError()<<"\n";

        SDL_Quit();

    }

    void screan::clear()
    {
        memset (m_buffer, 0 , m_width*m_height * sizeof(Uint32));
    }

   void screan::boxblur()
   {

        Uint32 *temp = m_buffer;
	m_buffer = m_buffer2;
	m_buffer2 = temp;

	for(int y=0; y<m_height; y++) {
		for(int x=0; x<m_width; x++) {

			/*
			 * 0 0 0
			 * 0 1 0
			 * 0 0 0
			 */

			int redTotal=0;
			int greenTotal=0;
			int blueTotal=0;

			for(int row=-1; row<=1; row++) {
				for(int col=-1; col<=1; col++) {
					int currentX = x + col;
					int currentY = y + row;

					if(currentX >= 0 && currentX < m_width && currentY >= 0 && currentY < m_height) {
						Uint32 color = m_buffer2[currentY*m_width + currentX];

						Uint8 blue = color >> 24;
						Uint8 green = color >> 16;
						Uint8 red = color >> 8;

						redTotal += red;
						greenTotal += green;
						blueTotal += blue;
					}
				}
			}

			Uint8 red = redTotal/9;
			Uint8 green = greenTotal/9;
			Uint8 blue = blueTotal/9;

			setbufferfg(red, green, blue,x, y);
		}
	}
       
   }
}