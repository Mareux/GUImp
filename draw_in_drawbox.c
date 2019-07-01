/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_in_drawbox.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 21:29:12 by mnosko            #+#    #+#             */
/*   Updated: 2019/06/28 12:23:14 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void		drawbox_add_text(t_drawbox *drawbox, SDL_Surface *text)
{
	SDL_Surface	*tmp;
	int			h;

	if (!text)
		return ;
	h = text->h;
	tmp = SDL_CreateRGBSurface(0, drawbox->full_drawbox->w + text->w,
			drawbox->full_drawbox->h + text->h, 32, 0, 0, 0, 0);
	SDL_BlitSurface(drawbox->full_drawbox, NULL, tmp, NULL);
	SDL_BlitSurface(text, NULL,
	tmp, &(SDL_Rect){0, drawbox->full_drawbox->h, text->w, text->h});
	SDL_FreeSurface(drawbox->full_drawbox);
	drawbox->full_drawbox = tmp;
	if ((drawbox->full_drawbox->h) > drawbox->menu->h)
		drawbox->active_rect.y += h;
}

void		draw_drawbox_menu(SDL_Surface *menu,
		SDL_Surface *full_menu, SDL_Rect zone)
{
	clear_surface(menu);
	SDL_BlitSurface(full_menu, &zone, menu, NULL);
}

SDL_Rect	scroll_drawbox_menu(SDL_Rect active_rect,
		SDL_Rect full_menu, int step)
{
	if (step > 0)
	{
		if ((active_rect.y + step) >= full_menu.h)
			return (active_rect);
	}
	else
	{
		if ((active_rect.y + step) <= 0)
			return (active_rect);
	}
	active_rect.y += step;
	return (active_rect);
}
