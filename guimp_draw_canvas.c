#include "guimp.h"

// Also move to libui
void	blit_with_offset(SDL_Surface *src, SDL_Surface *dst, t_vec2 offset)
{
	SDL_Rect	sorc;
	SDL_Rect	dest;
	sorc.x = 0;
	sorc.y = 0;
	sorc.w = src->w;
	sorc.h = src->h;
	dest.x = dst->w / 2 - src->w / 2 + offset.x;
	dest.y = dst->h / 2 - src->h / 2 + offset.y;

	SDL_BlitSurface(src, &sorc, dst, &dest);
}

void	draw_canvas(t_guimp *guimp)
{
	SDL_Surface *scaled;

	//fill_surface(guimp->libui->main_window->surface, rgb(0, 0, 0));
	scaled = create_scaled_surface(guimp->preview, guimp->canvas_data.scale);
	guimp->canvas_data.topleft.x = guimp->libui->main_window->surface->w / 2
								   - scaled->w / 2 + guimp->canvas_data.offset.x;
	guimp->canvas_data.topleft.y = guimp->libui->main_window->surface->h / 2
								   - scaled->h / 2 + guimp->canvas_data.offset.y;
	blit_with_offset(scaled, guimp->libui->main_window->surface, guimp->canvas_data.offset);
	SDL_FreeSurface(scaled);
}