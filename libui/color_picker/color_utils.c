/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:03:49 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/15 22:05:18 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libui.h"

void			set_pixel(SDL_Surface *surface, SDL_Color color, int x, int y)
{
	((char *)surface->pixels)[(x + y * surface->w) * 4] = color.r;
	((char *)surface->pixels)[(x + y * surface->w) * 4 + 1] = color.g;
	((char *)surface->pixels)[(x + y * surface->w) * 4 + 2] = color.b;
	((char *)surface->pixels)[(x + y * surface->w) * 4 + 3] = color.a;
}

SDL_Color		rgb_color_to_sdl_color(t_rgb_color rgb_color)
{
	return (SDL_Color) {
					rgb_color.r * 255,
					rgb_color.g * 255,
					rgb_color.b * 255,
					0xff
			};
}

t_color rgb_color_to_t_color(t_rgb_color rgb_color)
{
	return (t_color)
	{
		rgb_color.r * 255,
		rgb_color.g * 255,
		rgb_color.b * 255,
		0xff
	};
}

t_rgb_color sdl_color_color_to_rgb(t_color color)
{
	return (t_rgb_color) {color.r / 255,
					color.g / 255,
					color.b / 255
	};
}

int				clamp(int lower, int higher, int num)
{
	if (num < lower)
	{
		return (lower);
	}
	else if (num > higher)
	{
		return (higher);
	}
	else
	{
		return (num);
	}
}
