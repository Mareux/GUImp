/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_bg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 21:58:26 by mnosko            #+#    #+#             */
/*   Updated: 2019/06/25 21:58:26 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	load_bg(t_sdl_data *data)
{
	data->bg = SDL_LoadBMP("./img/bg.bmp");
	if (!data->bg)
	{
		ft_putendl("Error: editor ui background not found.");
		exit(420);
	}
}

void	draw_bg(t_sdl_data *data)
{
	SDL_Rect rect;

	rect.x = 0;
	rect.y = 0;
	rect.w = 1920;
	rect.h = 1080;
	SDL_BlitSurface(data->bg, &rect,
			data->active_window->surface, &rect);
}
