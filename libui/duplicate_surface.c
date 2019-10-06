#include "libui.h"

t_surface	*duplicate_surface(t_surface *src)
{
	t_surface	*new;

	new = SDL_DuplicateSurface(src);
	return (new);
}

