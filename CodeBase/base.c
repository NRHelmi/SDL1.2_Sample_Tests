#include <SDL/SDL.h>

int main()
{
    SDL_Surface *window;
    Uint32 start;
    int running=1,fps=60;

    SDL_Init(SDL_INIT_EVERYTHING);
//SDL_Surface *SDL_SetVideoMode(int width, int height, int bpp, Uint32 flags);
    window = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);

    while(running)
    {
        start=SDL_GetTicks();

        //put your code here

        if(1000/fps > SDL_GetTicks()-start)
            SDL_Delay(1000/fps - SDL_GetTicks() +start);

        SDL_Flip(window);
    }

    SDL_FreeSurface(window);
    SDL_Quit();
    return 0;

}
