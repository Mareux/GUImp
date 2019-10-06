#include "libui.h"

t_surface	*free_surface(t_surface *surface)
{
	SDL_FreeSurface(surface);
	return (NULL);
}