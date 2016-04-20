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

        GetEvent(&running,window,surface1,surface2,&opacity);


        if(1000/fps > SDL_GetTicks()-start)
            SDL_Delay(1000/fps - SDL_GetTicks() +start);

        SDL_Flip(window);
    }

    SDL_FreeSurface(window);
    SDL_Quit();
    return 0;

}
//**********************************************************************
void AlphaBlendv2(SDL_Surface *window,SDL_Surface *alpha,int *opacity)
{
    SDL_SetAlpha(alpha,SDL_SRCALPHA,*opacity);
    SDL_BlitSurface(alpha,NULL,window,NULL);
}
//***********************************************************************
void GetEvent(int *running,SDL_Surface *window,SDL_Surface *surface,SDL_Surface *alpha,int *opacity)
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
                                        AlphaBlendv2(window,alpha,opacity);
                                    break;
                                case SDLK_DOWN:
                                        *opacity-=10;
                                        SDL_BlitSurface(surface,NULL,window,&window->clip_rect);
                                        AlphaBlendv2(window,alpha,opacity);
                                    break;
                                case SDLK_s: SDL_SaveBMP(window,"Alpha2.bmp"); break;
                                default : break;
                            }
                            break;
            default: break;
        }
    }
}
//***********************************************************************
