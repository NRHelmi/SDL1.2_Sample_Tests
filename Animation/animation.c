#include <SDL/SDL.h>
#include <SDL/SDL_image.h>






int main()
{
    SDL_Surface *window,*kakashi;
    Uint32 start;
    int running=1,fps=10;
    SDL_Rect rect;
    rect.x=rect.y=0; rect.h=200; rect.w=200;

    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);

    SDL_FillRect(window,&window->clip_rect,SDL_MapRGB(window->format,255,255,255));
//SDL_Surface *IMG_Load(const char *file)
//SDL_Surface *SDL_DisplayFormat(SDL_Surface *surface);
    kakashi = SDL_DisplayFormat(IMG_Load("kakashi.png"));

    while(running)
    {
        start=SDL_GetTicks();

        //put your code here
        GetEvent(&running);
        DrawK(window,kakashi,&rect);

        if(1000/fps > SDL_GetTicks()-start)
            SDL_Delay(1000/fps - SDL_GetTicks() +start);

        SDL_Flip(window);
    }

    SDL_FreeSurface(window);
    SDL_Quit();
    return 0;

}
//**********************************************************************
void DrawK(SDL_Surface *window,SDL_Surface *kakashi,SDL_Rect *srcRect)
{
    SDL_Rect dest;
     dest.x=dest.y=200;

    srcRect->x+=200;
    if(srcRect->x>=1200)
        srcRect->x=0;

    SDL_BlitSurface(kakashi,srcRect,window,&dest);
}
//***********************************************************************
void GetEvent(int *running,int *d,SDL_Rect *rect)
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT : *running=0; break;

        }
    }
}
//***********************************************************************
