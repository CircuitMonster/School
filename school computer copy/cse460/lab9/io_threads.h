/*
  io_threads.h -- contains the mouse and key thread functions
*/
#ifndef IO_THREADS_H
#define IO_THREADS_H

#include "SDL/SDL.h"
#include "SDL/SDL_thread.h"
#include "point.h"

using namespace std;
int FilterEvents(const SDL_Event *event);
int mouse_thread ( void *unused );
int key_thread ( void *unused );
int game_thread ( void *unused );

#endif
