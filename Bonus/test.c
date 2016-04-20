#include "test.h"

int collision(SDL_Rect * a,SDL_Rect * b)
{
    if(a->x+a->w < b->x)
        return 0;
    if(a->x > b->x+b->w)
        return 0;
    if(a->y+a->h < b->y)
        return 0;
    if(a->y > b->y+b->h)
        return 0;
    return 1;
}

SDL_Surface *init(int width, int heigth)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    return SDL_SetVideoMode(width,heigth,32,SDL_HWSURFACE|SDL_ASYNCBLIT);
}

void GetEvent(int *running,int *b)
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT: *running = 0; break;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_UP: b[0]=1; break;
                        case SDLK_DOWN: b[1]=1; break;
                        case SDLK_LEFT: b[2]=1; break;
                        case SDLK_RIGHT: b[3]=1; break;

                    } break;
                case SDL_KEYUP:
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_UP: b[0]=0; break;
                        case SDLK_DOWN: b[1]=0; break;
                        case SDLK_LEFT: b[2]=0; break;
                        case SDLK_RIGHT: b[3]=0; break;

                    } break;
            }

        }
}
void MoveObjects(int *b,SDL_Rect *rect1, SDL_Rect *rect2)
{
    if(b[0])
    {
        rect1->y-=10;
        if(collision(rect1,rect2))
        {
            rect1->y+=10;
            rect2->y-=10;
        }
    }
    if(b[1])
    {
        rect1->y+=10;
        if(collision(rect1,rect2))
        {
            rect1->y-=10;
            rect2->y+=10;
        }
    }
    if(b[2])
    {
        rect1->x-=10;
        if(collision(rect1,rect2))
        {
            rect1->x+=10;
            rect2->x-=10;
        }
    }
    if(b[3])
    {
        rect1->x+=10;
        if(collision(rect1,rect2))
        {
            rect1->x-=10;
            rect2->x+=10;
        }
    }
}

void SetChanges(SDL_Surface *window,SDL_Surface *wallpaper,SDL_Surface *gnu,SDL_Surface *tux,SDL_Rect *rect1,SDL_Rect *rect2)
{
        SDL_BlitSurface(wallpaper,NULL,window,&window->clip_rect);
        SDL_BlitSurface(gnu,NULL,window,rect2);
        SDL_BlitSurface(tux,NULL,window,rect1);
}
