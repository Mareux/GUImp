/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gradients.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:43:00 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/16 10:21:32 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libui.h"

void	draw_main_gradient(SDL_Surface *surface, double hue)
{
	SDL_Surface		*gradient;
	int				x;
	int				y;

	gradient = SDL_CreateRGBSurface(0,
			MAIN_GRADIENT_SIZE, MAIN_GRADIENT_SIZE, 32,
	0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000);
	y = 0;
	while (y < gradient->h)
	{
		x = 0;
		while (x < gradient->w)
		{
			set_pixel(gradient,
		rgb_color_to_sdl_color(hsv_to_rgb((t_hsv_color){
		hue, (double)x / surface->w,
		1.0 - ((double)y / surface->h)})), x, y);
			x++;
		}
		y++;
	}
	SDL_BlitSurface(gradient, &gradient->clip_rect,
			surface, &gradient->clip_rect);
	SDL_FreeSurface(gradient);
}

void	draw_hue_gradient(SDL_Surface *surface)
{
	SDL_Surface		*gradient;
	int				x;
	int				y;

	gradient = SDL_CreateRGBSurface(0,
			HUE_GRADIENT_W, HUE_GRADIENT_H, 32,
	0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000);
	y = 0;
	while (y < gradient->h)
	{
		x = 0;
		while (x < gradient->w)
		{
			set_pixel(gradient, rgb_color_to_sdl_color(
					hsv_to_rgb((t_hsv_color){
				(double)x / gradient->w * 360, 1.0, 1.0})),
				x, y);
			x++;
		}
		y++;
	}
	SDL_BlitSurface(gradient, NULL, surface,
			&(SDL_Rect){0, MAIN_GRADIENT_SIZE, 0, 0});
	SDL_FreeSurface(gradient);
}
