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

#include "libui.h"

void	draw_rect(t_surface *surface, t_vec2 topleft,
		t_vec2 bottomright, t_color color)
{
	int x;
	int	y;

	x = topleft.x;
	y = topleft.y;
	while (x < bottomright.x)
	{
		put_pixel(surface, x, y, color);
		x++;
	}
	while (y < bottomright.y)
	{
		put_pixel(surface, x, y, color);
		y++;
	}
	while (x > topleft.x)
	{
		put_pixel(surface, x, y, color);
		x--;
	}
	while (y > topleft.y)
	{
		put_pixel(surface, x, y, color);
		y--;
	}
}

void	draw_filled_rect(t_surface *surface, t_vec2 topleft,
						 t_vec2 bottomright, t_color color)
{
	int x;
	int	y;

	x = topleft.x;
	while (x <= bottomright.x)
	{
		y = topleft.y;
		while (y <= bottomright.y)
		{
			put_pixel(surface, x, y, color);
			y++;
		}
		x++;
	}
}
