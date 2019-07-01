/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 21:49:23 by mnosko            #+#    #+#             */
/*   Updated: 2019/06/25 21:49:23 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	init_widgets(t_widget **widgets)
{
	*widgets = malloc(sizeof(t_widget));
	(*widgets)->textfield = NULL;
	(*widgets)->label = NULL;
	(*widgets)->button = NULL;
	(*widgets)->image = NULL;
	(*widgets)->combobox = NULL;
	(*widgets)->active_toggle = NULL;
	(*widgets)->active_combobox = NULL;
	(*widgets)->active_textfield = NULL;
}

void	init_sdl_data(t_sdl_data **data)
{
	*data = malloc(sizeof(t_sdl_data));
	(*data)->active_window = NULL;
	(*data)->active_window_return_data = NULL;
	(*data)->file = NULL;
	if (TTF_Init() < 0)
		exit(124);
	(*data)->font = TTF_OpenFont("Roboto-Regular.ttf", 18);
	if (!(*data)->font)
	{
		ft_putendl_fd("Couldn't load font!", 2);
		exit(123);
	}
	load_bg(*data);
}

void	init_window(t_sdl_data *data)
{
	data->windows = malloc(sizeof(t_window_list));
	data->windows->next = NULL;
	data->main_window = &data->windows->window;
	data->main_window->window = SDL_CreateWindow("Editor",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
	WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN);
}

int		init_sdl(t_sdl_data *data)
{
	int success;

	success = TRUE;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		success = FALSE;
	if (IMG_Init(IMG_INIT_JPG) < 0)
		success = FALSE;
	else
	{
		init_window(data);
		if (data->main_window->window == NULL)
			success = FALSE;
		else
		{
			data->main_window->surface =
					SDL_GetWindowSurface(data->windows->window.window);
			data->main_window->id =
					SDL_GetWindowID(data->windows->window.window);
			data->main_window->active = TRUE;
			data->main_window->type = MAIN_WINDOW;
			init_widgets(&data->main_window->widgets);
			data->active_window = data->main_window;
		}
	}
	return (success);
}
