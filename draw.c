/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 21:28:45 by mnosko            #+#    #+#             */
/*   Updated: 2019/06/25 21:28:45 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	draw_rect(SDL_Surface *surface, SDL_Rect rect, t_color color)
{
	draw_line(surface, (t_vec2f){rect.x, rect.y},
			(t_vec2f){rect.w + rect.x, rect.y}, color);
	draw_line(surface, (t_vec2f){rect.x, rect.y},
			(t_vec2f){rect.x, rect.h + rect.y}, color);
	draw_line(surface, (t_vec2f){rect.x, rect.h + rect.y},
			(t_vec2f){rect.w + rect.x, rect.h + rect.y}, color);
	draw_line(surface, (t_vec2f){rect.w + rect.x, rect.y},
			(t_vec2f){rect.w + rect.x, rect.h + rect.y}, color);
}

void	draw_filled_rect(SDL_Surface *surface, SDL_Rect rect, t_color color)
{
	int x;
	int w;

	x = rect.x;
	w = rect.w + rect.x;
	if (rect.x > (rect.w + rect.x))
	{
		w = rect.x;
		x = rect.w + rect.x;
	}
	while (x < w)
	{
		draw_line(surface, (t_vec2f){x, rect.y},
				(t_vec2f){x, rect.h + rect.y}, color);
		x++;
	}
}
