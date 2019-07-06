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

#include "../guimp.h"

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

int		init_libui(t_libui **data)
{
	int success;

	success = 1;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		success = 0;
	if (IMG_Init(IMG_INIT_JPG) < 0)
		success = 0;
	*data = malloc(sizeof(t_libui));
	(*data)->active_window = NULL;
	(*data)->active_window_return_data = NULL;
	if (TTF_Init() < 0)
		exit(124);
//	(*data)->font = TTF_OpenFont("Roboto-Regular.ttf", 18);
//	if (!(*data)->font)
//	{
//		ft_putendl_fd("Couldn't load font!", 2);
//		exit(123);
//	}
	return (success);
}

void			close_sdl(t_libui *data)
{
	while (data->windows)
	{
		SDL_DestroyWindow(data->windows->window.window);
		data->windows->window.window = NULL;
		data->windows = data->windows->next;
	}
	SDL_Quit();
}
