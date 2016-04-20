#include <SDL/SDL.h>

int main()
{
    SDL_Surface *window;
    Uint32 start;
    SDL_Rect rect; rect.h=rect.w=30; rect.x=rect.y=0;
    int running=1,fps=60,d[4]={0,0,0,0};


    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);

    Uint32 cBlue=SDL_MapRGB(window->format,0,0,0xff),
           cRed =SDL_MapRGB(window->format,255,0,0);

    SDL_ShowCursor(0);
    while(running)
    {
        start=SDL_GetTicks();
        //put your code here
        GetEvent(&running,d,&rect);
        DrawBG(window);
        DrawRect(window,&rect,cBlue);
        MoveRect(d,&rect);

        if(1000/fps > SDL_GetTicks()-start)
            SDL_Delay(1000/fps - SDL_GetTicks() +start);

        SDL_Flip(window);
    }

    SDL_FreeSurface(window);
    SDL_Quit();
    return 0;

}

//**********************************************
void GetEvent(int *running,int *d,SDL_Rect *rect)
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT : *running=0; break;
            //keyboard events
            case SDL_KEYDOWN:
                            switch(event.key.keysym.sym)
                            {
                                case SDLK_UP:    d[0]=1;  break;
                                case SDLK_DOWN:  d[1]=1;  break;
                                case SDLK_LEFT:  d[2]=1;  break;
                                case SDLK_RIGHT: d[3]=1;  break;
                                default : break;
                            }
                            break;
            case SDL_KEYUP:
                            switch(event.key.keysym.sym)
                            {
                                case SDLK_UP:     d[0]=0;  break;
                                case SDLK_DOWN:   d[1]=0;  break;
                                case SDLK_LEFT:   d[2]=0;  break;
                                case SDLK_RIGHT:  d[3]=0;  break;
                                default : break;
                            }
                            break;

            //mouse events
            case SDL_MOUSEMOTION: rect->x = event.motion.x;
                                  rect->y = event.motion.y;
                                  break;
            case SDL_MOUSEBUTTONDOWN:/*do action*/ break;
            case SDL_MOUSEBUTTONUP:/*do action*/  break;
            default: break;
        }
    }
}

//**********************************************
void DrawBG(SDL_Surface *window)
{
//Uint32 SDL_MapRGB(const SDL_PixelFormat* format,Uint8 r, Uint8 g, Uint8 b)
    Uint32 color = SDL_MapRGB(window->format,255,255,0xff);
//int SDL_FillRect(SDL_Surface *dst, SDL_Rect *dstrect, Uint32 color);
    SDL_FillRect(window,&window->clip_rect,color);
}

//***********************************************
void DrawRect(SDL_Surface *window,SDL_Rect *rect,Uint32 color)
{
    SDL_FillRect(window,rect,color);
}
//************************************************
void MoveRect(int *d,SDL_Rect *rect)
{
    if(d[0])
        rect->y-=10;
    if(d[1])
        rect->y+=10;
    if(d[2])
        rect->x-=10;
    if(d[3])
        rect->x+=10;
}
