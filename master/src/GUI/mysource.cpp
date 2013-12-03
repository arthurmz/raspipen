#include "SDL/SDL.h"

int main( int argc, char* args[] )
{

    //The images
    SDL_Surface* background = NULL;

    SDL_Surface* screen = NULL;

    //Start SDL
    SDL_Init( SDL_INIT_EVERYTHING );

    screen = SDL_SetVideoMode( 640, 480, 32, SDL_SWSURFACE );

    background = SDL_LoadBMP( "hello.bmp" );

    //Apply image to screen
    SDL_BlitSurface( background, NULL, screen, NULL );

    //Update Screen
    SDL_Flip( screen );

    //Pause
    SDL_Delay( 20000 );

    //Free the loaded image
    SDL_FreeSurface( background );

    //Quit SDL
    SDL_Quit();

    return 0;
}
