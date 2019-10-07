#include "libui.h"

t_vec2		find_scaled_surface_size(t_surface *surface, double scale)
{
	t_vec2	scaled_size;

	scaled_size.x = (double)surface->w * scale;
	scaled_size.y = (double)surface->h * scale;
	return (scaled_size);
}

t_surface	*create_scaled_surface(t_surface *surface, double scale)
{
	t_surface	*scaled_surface;

	scaled_surface = SDL_CreateRGBSurface(0,
		  (double)surface->w * scale, (double)surface->h * scale,
		  32, 0, 0, 0, 0);
	SDL_BlitScaled(surface, NULL, scaled_surface, NULL);
	return (scaled_surface);
}