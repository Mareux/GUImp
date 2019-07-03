/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_windows_create.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 21:50:59 by mnosko            #+#    #+#             */
/*   Updated: 2019/06/25 21:50:59 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

static t_window		create_window(int weight, int height, int type)
{
	t_window window;

	window.window = SDL_CreateWindow("",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			weight, height, SDL_WINDOW_HIDDEN);
	window.id = SDL_GetWindowID(window.window);
	window.surface = SDL_GetWindowSurface(window.window);
	init_widgets(&window.widgets);
	window.active = FALSE;
	window.type = type;
	return (window);
}

void				add_window_to_list(t_window_list **begin,
		int weight, int height, int type)
{
	t_window_list *new;

	if (!(new = malloc((sizeof(t_window_list)))))
		exit(1);
	new->window = create_window(weight, height, type);
	new->next = *begin;
	*begin = new;
}
