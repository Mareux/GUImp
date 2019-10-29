/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaled_surfaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 23:35:10 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/29 23:35:12 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_vec2		find_scaled_surface_size(t_surface *surface, double scale)
{
	t_vec2 scaled_size;

	scaled_size.x = (double)surface->w * scale;
	scaled_size.y = (double)surface->h * scale;
	return (scaled_size);
}

t_surface	*create_scaled_surface(t_surface *surface, double scale)
{
	t_surface *scaled_surface;

	scaled_surface = SDL_CreateRGBSurface(0,
	(double)surface->w * scale, (double)surface->h * scale,
	32, 0, 0, 0, 0);
	SDL_BlitScaled(surface, NULL, scaled_surface, NULL);
	return (scaled_surface);
}

/*
**  Takes an area between "topleft" and "bottomright",
**  and creates a scaled surface out of it
*/

t_surface	*create_scaled_area(t_surface *surface, double scale,
		t_vec2 topleft, t_vec2 bottomright)
{
	t_surface	*scaled_surface;
	SDL_Rect	pineapple_pizza;

	scaled_surface = SDL_CreateRGBSurface(0,
	(bottomright.x - topleft.x) * scale, (bottomright.y - topleft.y) * scale,
		32, 0, 0, 0, 0);
	pineapple_pizza.x = topleft.x;
	pineapple_pizza.y = topleft.y;
	pineapple_pizza.w = (bottomright.x - topleft.x);
	pineapple_pizza.h = (bottomright.y - topleft.y);
	SDL_BlitScaled(surface, &pineapple_pizza, scaled_surface, NULL);
	return (scaled_surface);
}
