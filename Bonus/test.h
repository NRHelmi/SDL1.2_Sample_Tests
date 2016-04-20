#include <SDL/SDL.h>

#ifndef _TEST_H_
#define _TEST_H_

SDL_Surface *init(int width, int heigth);
void 		 GetEvent(int *running,int *b);
void 		 MoveObjects(int *b,SDL_Rect *rect1, SDL_Rect *rect2);
void 		 SetChanges(SDL_Surface *window,SDL_Surface *wallpaper,SDL_Surface *gnu,SDL_Surface *tux,SDL_Rect *rect1,SDL_Rect *rect2);
int 		 collision(SDL_Rect * a,SDL_Rect * b);

#endif
