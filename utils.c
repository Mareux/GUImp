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

#include "editor.h"

void			clear_surface(SDL_Surface *surface)
{
	int x;
	int y;

	x = 0;
	while (x < surface->w)
	{
		y = 0;
		while (y < surface->h)
		{
			put_pixel(surface, x, y, (t_color){0, 0, 0, 0});
			y++;
		}
		x++;
	}
}

SDL_Surface		*return_coord_surface(char *x, char *y,
		TTF_Font *font)
{
	char		*tmp;
	char		*tmp2;
	SDL_Surface	*text;

	tmp = ft_strjoin(x, ", ");
	tmp2 = ft_strjoin(tmp, y);
	free(tmp);
	text = create_text_surface(tmp2, font);
	free(tmp2);
	return (text);
}

void			console(t_sdl_data *data, char *text)
{
	SDL_Surface	*surface;

	surface = create_text_surface(text, data->font);
	drawbox_add_text(data->main_window->widgets->drawbox, surface);
	SDL_FreeSurface(surface);
}
