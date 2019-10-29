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

#include "libui.h"

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

t_surface		*load_image_as_surface(const char *file)
{
	return (IMG_Load(file));
}

t_surface		*create_text_surface(char *text, t_font *font)
{
	t_surface		*surface;
	SDL_Color		text_color;

	text_color = (SDL_Color){0, 0, 0, 0};
	surface = TTF_RenderUTF8_Blended(font, text, text_color);
	return (surface);
}

void			render_text(t_libui *libui, SDL_Event e, t_widget *widgets)
{
	if (!widgets->textfield)
		return ;
	if (e.type == SDL_TEXTINPUT)
	{
		render_text_in_textfield(widgets->active_textfield,
		libui, e.text.text, text_input_event);
	}
	else if (e.type == SDL_KEYDOWN)
	{
		if (e.key.keysym.sym == SDLK_BACKSPACE)
		{
			render_text_in_textfield(widgets->active_textfield,
			libui, NULL, backspace_event);
		}
		if (e.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL)
		{
			render_text_in_textfield(widgets->active_textfield,
			libui, SDL_GetClipboardText(), text_input_event);
		}
	}
}
