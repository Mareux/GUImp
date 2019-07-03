/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_windows_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 21:52:44 by mnosko            #+#    #+#             */
/*   Updated: 2019/06/25 21:52:44 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	hide_active_window(t_window **active_window,
		t_window *main_window, t_window_list **window)
{
	SDL_HideWindow((*active_window)->window);
	delete_window(window, (*active_window)->id);
	*active_window = main_window;
	SDL_RaiseWindow(main_window->window);
}

void	show_active_window(t_window *active_window, t_sdl_data *data)
{
	SDL_ShowWindow(active_window->window);
	SDL_RaiseWindow(active_window->window);
	main_event_loop(active_window, data);
}

void	exit_event(SDL_Event *event)
{
	event->type = SDL_KEYUP;
	event->key.keysym.scancode = SDL_SCANCODE_ESCAPE;
	SDL_PushEvent(event);
}
