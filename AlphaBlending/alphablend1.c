#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


int main()
{
    SDL_Surface *window,*surface1,*surface2;
    Uint32 start;
    int running=1,fps=15,opacity=0;

    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);


    surface1 = SDL_DisplayFormat(IMG_Load("android.bmp"));
    surface2 = SDL_DisplayFormat(IMG_Load("android1.bmp"));

    SDL_BlitSurface(surface1,NULL,window,&window->clip_rect);

    while(running)
    {
        start=SDL_GetTicks();
        //put your code here

        GetEvent(&running,window,surface1,&opacity);


        if(1000/fps > SDL_GetTicks()-start)
            SDL_Delay(1000/fps - SDL_GetTicks() +start);

        SDL_Flip(window);
    }

    SDL_FreeSurface(window);
    SDL_Quit();
    return 0;

}
//**********************************************************************
void AlphaBlendv1(SDL_Surface *window,SDL_Surface *surface,int *opacity)
{
//SDL_Surface *SDL_CreateRGBSurface(Uint32 flags, int width, int height, int depth, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask);
    SDL_Surface *alpha = SDL_CreateRGBSurface(0,window->w,window->h,32,window->format->Rmask,window->format->Gmask,
                            window->format->Bmask,window->format->Amask);

    SDL_FillRect(alpha,&window->clip_rect,SDL_MapRGB(window->format,0,0,0));

//int SDL_SetAlpha(SDL_Surface *surface, Uint32 flag, Uint8 alpha);
    SDL_SetAlpha(alpha,SDL_SRCALPHA,*opacity);
    SDL_BlitSurface(alpha,NULL,window,NULL);
}
//***********************************************************************
void GetEvent(int *running,SDL_Surface *window,SDL_Surface *surface,int *opacity)
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
                                case SDLK_UP:
                                        *opacity+=10;
                                        SDL_BlitSurface(surface,NULL,window,&window->clip_rect);
                                        AlphaBlendv1(window,surface,opacity);
                                    break;
                                case SDLK_DOWN:
                                        *opacity-=10;
                                        SDL_BlitSurface(surface,NULL,window,&window->clip_rect);
                                        AlphaBlendv1(window,surface,opacity);
                                    break;
                                case SDLK_s: SDL_SaveBMP(window,"Alpha1.bmp"); break;
                                default : break;
                            }
                            break;
            default: break;
        }
    }
}
//***********************************************************************
