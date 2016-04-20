#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

int main()
{
    SDL_Surface *window;
    Uint32 start;
    int running=1,fps=60;

    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);
    SDL_FillRect(window,&window->clip_rect,SDL_MapRGB(window->format,255,255,255));


    TTF_Init();
    TTF_Font * font = TTF_OpenFont("journal.ttf",200);


    while(running)
    {
        start=SDL_GetTicks();

        //put your code here
        GetEvent(&running);
        Print(window,font,"Hello world",0,0);

        if(1000/fps > SDL_GetTicks()-start)
            SDL_Delay(1000/fps - SDL_GetTicks() +start);

        SDL_Flip(window);
    }

    SDL_FreeSurface(window);
    SDL_Quit();
    return 0;

}

//*********************************************
void GetEvent(int *running)
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
//*********************************************
void Print(SDL_Surface *window,TTF_Font *font,char *w,int x,int y)
{
    SDL_Color color;
    color.r = 0;
    color.g = 0;
    color.b = 255;

//SDL_Surface *TTF_RenderText_Solid(TTF_Font *font, const char *text, SDL_Color fg)
    SDL_Surface* Text = TTF_RenderText_Solid(font, w, color);

    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = Text->w;
    rect.h = Text->h;

//int SDL_BlitSurface(SDL_Surface *src, SDL_Rect *srcrect, SDL_Surface *dst, SDL_Rect *dstrect);
    SDL_BlitSurface(Text, NULL, window, &rect);
}
