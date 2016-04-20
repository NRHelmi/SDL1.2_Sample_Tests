#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

int main()
{
    SDL_Surface *window;
    Uint32 start;
    int running=1,fps=60;
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);

//int Mix_OpenAudio(int frequency, Uint16 format, int channels, int chunksize)
    Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
    Mix_Music *mario = Mix_LoadMUS("music/SuperMario.mp3");
    Mix_Chunk *jump  = Mix_LoadWAV("music/MarioJump.wav");
    Mix_Chunk *powerup = Mix_LoadWAV("music/powerup.wav");
    Mix_PlayMusic(mario,-1);


    while(running)
    {
        start=SDL_GetTicks();
        //put your code here
        GetEvent(&running,jump,powerup);


        if(1000/fps > SDL_GetTicks()-start)
            SDL_Delay(1000/fps - SDL_GetTicks() +start);

        SDL_Flip(window);
    }

    SDL_FreeSurface(window);
    SDL_Quit();
    return 0;

}

//*******************************************************
void GetEvent(int *running,Mix_Chunk* jump,Mix_Chunk* powerup)
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT : *running=0; break;
            case SDL_KEYDOWN:
                            switch(event.key.keysym.sym)
                            {
//int Mix_PlayChannel (int channel, Mix_Chunk *chunk, int loops);

                                case SDLK_UP:   Mix_PlayChannel(-1,jump,0); break;
                                case SDLK_DOWN: Mix_PlayChannel(-1,powerup,0); break;
                            }
                            break;
            default: break;
        }
    }
}
