#include "test.h"

void main()
{
    SDL_Surface *window =init(800,600);
    int          running = 1;
    SDL_Rect     rect1,rect2;
    Uint32       deb;
    int          b[4]={0,0,0,0};
    int          fps=60;

    SDL_Surface *tux       = SDL_DisplayFormat(SDL_LoadBMP("img/tux.bmp"));
    SDL_Surface *gnu       = SDL_DisplayFormat(SDL_LoadBMP("img/gnu.bmp"));
    SDL_Surface *wallpaper = SDL_DisplayFormat(SDL_LoadBMP("img/linux.bmp"));

    SDL_SetColorKey(tux,SDL_SRCCOLORKEY,SDL_MapRGB(window->format,255,0,0));
    SDL_SetColorKey(gnu,SDL_SRCCOLORKEY,SDL_MapRGB(window->format,255,255,255));

    rect1.x=10;                         rect1.y=200;
    rect2.x=SDL_GetVideoSurface()->w/2; rect2.y=SDL_GetVideoSurface()->h/2;

    while(running)
    {
        deb=SDL_GetTicks();

        GetEvent(&running,b);
        MoveObjects(b,&rect1,&rect2);
        SetChanges(window,wallpaper,gnu,tux,&rect1,&rect2);

        if(1000/fps > SDL_GetTicks() - deb)
            SDL_Delay(1000/fps - SDL_GetTicks() + deb);

        SDL_Flip(window);

    }

    SDL_Quit();

}
