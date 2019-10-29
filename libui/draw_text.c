/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:49:23 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/29 21:49:25 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	init_text(t_libui *libui, t_text *text)
{
	text->font = libui->imported_font;
	text->surface = libui->main_window->surface;
	text->position = vec2(0, 0);
	text->text = NULL;
	text->color = rgb(0, 0, 0);
}

void	draw_text(t_text *text)
{
	SDL_Surface	*text_surface;
	SDL_Color	color;
	SDL_Rect	rect;

	if (!text->text)
		return ;
	color.r = text->color.r;
	color.g = text->color.g;
	color.b = text->color.b;
	color.a = text->color.a;
	rect.x = text->position.x;
	rect.y = text->position.y;
	text_surface = TTF_RenderText_Blended(text->font, text->text, color);
	SDL_BlitSurface(text_surface, NULL, text->surface, &rect);
	SDL_FreeSurface(text_surface);
}
