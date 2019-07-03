/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 21:50:06 by mnosko            #+#    #+#             */
/*   Updated: 2019/06/29 20:05:38 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

SDL_Surface		*create_text_surface(char *text, TTF_Font *font)
{
	SDL_Surface		*surface;
	SDL_Color		text_color;

	text_color = (SDL_Color){255, 255, 255, 0};
	surface = TTF_RenderUTF8_Blended(font, text, text_color);
	return (surface);
}

void			close_sdl(t_sdl_data *data)
{
	while (data->windows)
	{
		SDL_DestroyWindow(data->windows->window.window);
		data->windows->window.window = NULL;
		data->windows = data->windows->next;
	}
	SDL_Quit();
}

void			render_text(t_sdl_data *data, SDL_Event e, t_widget *widgets)
{
	if (e.type == SDL_TEXTINPUT)
	{
		render_text_in_textfield(widgets->active_textfield,
				data, e.text.text, text_input_event);
	}
	else if (e.type == SDL_KEYDOWN)
	{
		if (e.key.keysym.sym == SDLK_BACKSPACE)
		{
			render_text_in_textfield(widgets->active_textfield,
					data, NULL, backspace_event);
		}
		if (e.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL)
		{
			render_text_in_textfield(widgets->active_textfield,
					data, SDL_GetClipboardText(), text_input_event);
		}
	}
}

int				main(void)
{
	t_sdl_data	*data;

	init_sdl_data(&data);
	if (!init_sdl(data))
		ft_putendl_fd("Failed to initialize", 2);
	else
	{
		main_event_loop(data->active_window, data);
	}
	close_sdl(data);
	return (0);
}
