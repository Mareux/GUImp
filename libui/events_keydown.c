/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 17:55:47 by ibarabas          #+#    #+#             */
/*   Updated: 2019/10/21 15:53:32 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	eventloop_window_events(t_libui *data, int *quit)
{
	if (data->event.type == SDL_WINDOWEVENT
		&& (int)data->event.window.windowID == data->active_window->id)
	{
		if (data->event.window.event == SDL_WINDOWEVENT_CLOSE)
		{
			if (data->active_window->id != data->main_window->id)
			{
				hide_active_window(&data->active_window,
					data->main_window);
				return ;
			}
			*quit = TRUE;
		}
	}
}

int		guimp_subject_is_bad(t_keylist *key)
{
	if (SDL_GetModState() & KMOD_ALT)
	{
		if (key->keymod == LIBUI_ALT)
			return (1);
		return (0);
	}
	if (SDL_GetModState() & KMOD_CTRL)
	{
		if (key->keymod == LIBUI_CTRL)
			return (1);
		return (0);
	}
	if (SDL_GetModState() & KMOD_SHIFT)
	{
		if (key->keymod == LIBUI_SHIFT)
			return (1);
		return (0);
	}
	if (key->keymod == LIBUI_NONE)
		return (1);
	return (0);
}

void	divinity_original_sin_2_is_a_good_game(t_libui *data,
		t_keybind *keybind)
{
	if (guimp_subject_is_bad(keybind->keys))
		keybind->func(data);
}

void	eventloop_keydown(t_libui *data, int *quit)
{
	t_keybind *keybind;

	if (data->event.type == SDL_KEYUP
		&& (int)data->event.window.windowID == data->main_window->id)
	{
		if (data->event.key.keysym.scancode
			== SDL_SCANCODE_ESCAPE)
		{
			*quit = TRUE;
		}
		keybind = data->hooks.keybinds;
		while (keybind)
		{
			if (keybind->keys)
			{
				if (data->event.key.keysym.scancode == keybind->keys->scancode)
					divinity_original_sin_2_is_a_good_game(data, keybind);
			}
			keybind = keybind->next;
		}
	}
}
