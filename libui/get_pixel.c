/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 11:47:07 by ibarabas          #+#    #+#             */
/*   Updated: 2019/03/08 11:47:07 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void		set_color(unsigned char *pixel, t_color *color)
{
	if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
	{
		color->r = pixel[0];
		color->g = pixel[1];
		color->b = pixel[2];
		color->a = pixel[3];
	}
	else
	{
		color->b = pixel[0];
		color->g = pixel[1];
		color->r = pixel[2];
		color->a = pixel[3];
	}
}

t_color			get_pixel(SDL_Surface *img, int x, int y)
{
	unsigned char	*pixel;
	t_color			color;

	if (x < 0 || x >= img->w || y < 0 || y >= img->h)
		color = rgba(0, 0, 0, 0);
	else
	{
		pixel = (unsigned char *)img->pixels
			+ y * img->pitch
			+ x * img->format->BytesPerPixel;
		set_color(pixel, &color);
	}
	return (color);
}
