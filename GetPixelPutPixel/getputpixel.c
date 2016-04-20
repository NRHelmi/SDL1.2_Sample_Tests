#include <SDL/SDL.h>


int main()
{
    Uint32 start;
    SDL_Surface *window;
    int running=1,fps=15;

    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);



    //myFillRect(window,window->clip_rect,SDL_MapRGB(window->format,255,255,255));

    putpixel32bpp(window,100,100,SDL_MapRGB(window->format,255,255,255));

    while(running)
    {
        start=SDL_GetTicks();

        //put your code here
        GetEvent(&running);

        if(1000/fps > SDL_GetTicks()-start)
            SDL_Delay(1000/fps - SDL_GetTicks() +start);

        SDL_Flip(window);
    }

    SDL_FreeSurface(window);
    SDL_Quit();
    return 0;

}
//**********************************************************************
void GetEvent(int *running,int *d,SDL_Rect *rect)
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT : *running=0; break;
            default: break;
        }
    }
}
//**********************************************************************
void putpixel8bpp(SDL_Surface *window,int x, int y)
{
    Uint8* pixels=(Uint8*)window->pixels;
    Uint8* pixel=pixels+y*window->pitch+x;
    *pixel=SDL_MapRGB(window->format,0xff,0xff,0xff);
}

//**********************************************************************
void putpixel32bpp(SDL_Surface *window,int x, int y,Uint32 color)
{
    Uint32* pixels=(Uint32*)window->pixels;
    Uint32* pixel=pixels+y*window->pitch/4+x;
    *pixel=color;
}
//**********************************************************************
void myFillRect(SDL_Surface* window,SDL_Rect rect,Uint32 color)
{
    int i,j;
    for(i=rect.x;i<rect.w;i++)
        for(j=rect.y;j<rect.h;j++)
            putpixel32bpp(window,i,j,color);
}
//**********************************************************************
