/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 17:55:47 by ibarabas          #+#    #+#             */
/*   Updated: 2019/06/29 19:35:03 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	draw_map_and_sector(t_sdl_data *data)
{
	if (data->active_window->id == data->main_window->id)
	{
		draw_bg(data);
	}
}

void	eventloop_window_events(t_sdl_data *data, int *quit)
{
	if (data->event.type == SDL_WINDOWEVENT
	&& (int)data->event.window.windowID == data->active_window->id)
	{
		if (data->event.window.event == SDL_WINDOWEVENT_CLOSE)
		{
			if (data->active_window->id != data->main_window->id)
			{
				hide_active_window(&data->active_window,
						data->main_window, &data->windows);
			}
			*quit = TRUE;
		}
	}
}

void	eventloop_keydown(t_sdl_data *data, t_window *window, int *quit)
{
	if (data->event.type == SDL_KEYUP
	&& (int)data->event.window.windowID == window->id)
	{
		if (data->event.key.keysym.scancode
		== SDL_SCANCODE_ESCAPE)
		{
			if (window->id != data->main_window->id)
			{
				hide_active_window(&data->active_window,
						data->main_window, &data->windows);
			}
			*quit = TRUE;
		}
	}
}

void	eventloop_mousebuttondown_2(t_sdl_data *data, SDL_Point point)
{
	if (data->active_window->widgets->active_combobox
	&& data->active_window->widgets->active_combobox->active
	&& (data->active_window->widgets->active_combobox->field_data =
			active_field_clicked(
	data->active_window->widgets->active_combobox->menu_rect, point,
	data->active_window->widgets->active_combobox->content,
	data->active_window->widgets->active_combobox)))
		data->active_window->widgets->active_combobox->active = FALSE;
}

void	eventloop_mousebuttondown(t_sdl_data *data, SDL_Point point)
{
	if (data->event.type == SDL_MOUSEBUTTONDOWN &&
		(int)data->event.window.windowID == data->active_window->id)
	{
		if (SDL_BUTTON(SDL_BUTTON_LEFT)
		&& SDL_GetMouseState(&point.x, &point.y))
		{
			if (point_in_textfield(point, data->active_window->widgets))
				if (!SDL_IsTextInputActive())
					SDL_StartTextInput();
			if (button_clicked(point, data->active_window->widgets, data))
				if (SDL_IsTextInputActive())
					SDL_StopTextInput();
			if (combobox_clicked(point,
					data->active_window->widgets, data))
			{
				if (SDL_IsTextInputActive())
					SDL_StopTextInput();
			}
			eventloop_mousebuttondown_2(data, point);
		}
	}
}
