/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 11:48:20 by ibarabas          #+#    #+#             */
/*   Updated: 2019/03/08 11:48:21 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../guimp.h"

int 		pixel_inside_surface(t_surface *img, int x, int y)
{
	if (x < 0 || y < 0 || x >= img->w || y >= img->h)
		return (0);
	return (1);
}

void		put_pixel(SDL_Surface *img, int x, int y, t_color color)
{
	unsigned char	*pixel;

	if (!img)
		return ;
	if (x < 0 || y < 0 || x >= img->w || y >= img->h
		|| img->format->BytesPerPixel < 3)
		return ;
	pixel = (unsigned char *)img->pixels
		+ y * img->pitch
		+ x * img->format->BytesPerPixel;
	if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
	{
		pixel[0] = color.r;
		pixel[1] = color.g;
		pixel[2] = color.b;
	}
	else
	{
		pixel[0] = color.b;
		pixel[1] = color.g;
		pixel[2] = color.r;
	}
}

/*
**	Вспомогательная функция для add_to_pixel(),
**	упрощенный вариант функции get_pixel()
*/

static void	get_color(unsigned char *pixel, t_color *new)
{
	if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
	{
		new->r = pixel[0];
		new->g = pixel[1];
		new->b = pixel[2];
	}
	else
	{
		new->b = pixel[0];
		new->g = pixel[1];
		new->r = pixel[2];
	}
}

/*
**	Еще одна функция для add_to_pixel(),
**	прибавляющая цвет src к цвету dest
*/

static void	add_color(t_color *src, t_color *dest, double alpha)
{
	dest->r = (dest->r * (1 - alpha)) + (src->r * alpha);
	dest->g = (dest->g * (1 - alpha)) + (src->g * alpha);
	dest->b = (dest->b * (1 - alpha)) + (src->b * alpha);
	if (dest->r > 255)
		dest->r = 255;
	if (dest->g > 255)
		dest->g = 255;
	if (dest->b > 255)
		dest->b = 255;
}

void		add_to_pixel(
	SDL_Surface *img, t_vec2 pos, t_color color, double alpha)
{
	unsigned char	*pixel;
	t_color			new;

	if (!img)
		return ;
	if (pos.x < 0 || pos.y < 0 || pos.x >= img->w || pos.y >= img->h
		|| img->format->BytesPerPixel < 3)
		return ;
	pixel = (unsigned char *)img->pixels
		+ pos.y * img->pitch
		+ pos.x * img->format->BytesPerPixel;
	get_color(pixel, &new);
	add_color(&color, &new, 1.0 - alpha);
	if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
	{
		pixel[0] = new.r;
		pixel[1] = new.g;
		pixel[2] = new.b;
	}
	else
	{
		pixel[0] = new.b;
		pixel[1] = new.g;
		pixel[2] = new.r;
	}
}
