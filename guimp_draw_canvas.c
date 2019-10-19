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
	dest.x = offset.x;//dst->w / 2 - src->w / 2 + offset.x;
	dest.y = offset.y;//dst->h / 2 - src->h / 2 + offset.y;

	SDL_BlitSurface(src, &sorc, dst, &dest);
}

/*
**  Calculates if the scaled image
**  will fit inside the window
*/

int     canvas_fits_in_window(t_guimp *guimp)
{
    t_vec2f  scaled_size;

    scaled_size.x = guimp->preview->w * guimp->canvas_data.scale;
    scaled_size.y = guimp->preview->h * guimp->canvas_data.scale;
    if (scaled_size.x <= guimp->libui->main_window->surface->w
        && scaled_size.y <= guimp->libui->main_window->surface->h)
        return (1);
    return (0);
}

/*
**  Finds the coordinates on screen
**  that correspond to (0, 0) coordinates on canvas
*/

void    calculate_canvas_origin(t_guimp *guimp)
{
    guimp->canvas_data.topleft.x = /* guimp->libui->main_window->surface->w / 2
            - guimp->libui->main_window->surface->w * guimp->canvas_data.scale / 2
            + */ guimp->canvas_data.offset.x;
    guimp->canvas_data.topleft.y = /*guimp->libui->main_window->surface->h / 2
            - guimp->libui->main_window->surface->h * guimp->canvas_data.scale / 2
            + */guimp->canvas_data.offset.y;
}

/*
**  Calculates the part of canvas
**  that will be visible on screen,
**  writes the image offset to *offset
*/

t_rect  calculate_visible_rect(t_guimp *guimp, t_vec2 *offset)
{
    t_vec2f  scaled_size;
    t_vec2f  window_size;
    t_rect  rect;

    scaled_size.x = guimp->preview->w * guimp->canvas_data.scale;
    scaled_size.y = guimp->preview->h * guimp->canvas_data.scale;
    window_size.x = guimp->libui->main_window->surface->w;
    window_size.y = guimp->libui->main_window->surface->h;

    scaled_size.x -= (scaled_size.x - window_size.x);
    scaled_size.y -= (scaled_size.y - window_size.y);

    scaled_size.x /= guimp->canvas_data.scale;
    scaled_size.y /= guimp->canvas_data.scale;

    if (scaled_size.x >= window_size.x || scaled_size.y >= window_size.y)
    {
        scaled_size.x = guimp->preview->w;
        scaled_size.y = guimp->preview->h;
    }
    else
    {
        scaled_size.x += 10;
        scaled_size.y += 10;
    }

    rect.topleft.x = -guimp->canvas_data.offset.x / guimp->canvas_data.scale;
    rect.topleft.y = -guimp->canvas_data.offset.y / guimp->canvas_data.scale;

    rect.bottomright.x = rect.topleft.x + scaled_size.x;
    rect.bottomright.y = rect.topleft.y + scaled_size.y;
    return (rect);
}

void	draw_canvas(t_guimp *guimp)
{
	SDL_Surface *scaled;
	t_rect  visible_rect;
	t_vec2  offset;

//	scaled = create_scaled_surface(guimp->preview, guimp->canvas_data.scale);
//	calculate_canvas_origin(guimp);
//	blit_with_offset(scaled, guimp->libui->main_window->surface, guimp->canvas_data.offset);
//	SDL_FreeSurface(scaled);

    offset.x = 0;
    offset.y = 0;
    calculate_canvas_origin(guimp);
	visible_rect = calculate_visible_rect(guimp, &offset);
	scaled = create_scaled_area(guimp->preview, guimp->canvas_data.scale,
	        vec2f_to_vec2(visible_rect.topleft),
	        vec2f_to_vec2(visible_rect.bottomright));
    blit_with_offset(scaled, guimp->libui->main_window->surface, offset);
	SDL_FreeSurface(scaled);
}