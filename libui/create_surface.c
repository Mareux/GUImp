#include "libui.h"

t_surface   *create_surface(void)
{
    return (SDL_CreateRGBSurface(0, 1024, 600, 32, 0, 0, 0, 0));
}