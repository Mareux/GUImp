/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 20:33:31 by mnosko            #+#    #+#             */
/*   Updated: 2019/06/29 20:27:26 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../guimp.h"

void			fill_surface(SDL_Surface *surface, t_color color)
{
	int x;
	int y;

	x = 0;
	while (x < surface->w)
	{
		y = 0;
		while (y < surface->h)
		{
			put_pixel(surface, x, y, color);
			y++;
		}
		x++;
	}
}
