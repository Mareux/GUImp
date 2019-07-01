/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 17:55:33 by ibarabas          #+#    #+#             */
/*   Updated: 2019/06/29 19:29:59 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static void		highlight_buttons(SDL_Point point, t_sdl_data *data)
{
	t_buttons_list *tmp;

	tmp = data->active_window->widgets->button;
	while (tmp)
	{
		if (SDL_PointInRect(&point, &tmp->button.rect))
			tmp->button.color = (t_color){100, 100, 100, 0};
		else
			tmp->button.color = (t_color){60, 70, 90, 0};
		tmp = tmp->next;
	}
}

void			eventloop_mousemotion(t_sdl_data *data, SDL_Point *point)
{
	if (data->event.type == SDL_MOUSEMOTION
	&& (int)data->event.window.windowID == data->active_window->id)
	{
		if (data->active_window->widgets->active_combobox)
			if (data->active_window->widgets->active_combobox->active)
			{
				active_field_select(
				data->active_window->widgets->active_combobox,
				(SDL_Point) {data->event.motion.x, data->event.motion.y});
				combobox_update(
				data->active_window->widgets->active_combobox,
				data->active_window->widgets->active_combobox->content);
			}
		SDL_GetMouseState(&(point->x), &(point->y));
		highlight_buttons(*point, data);
	}
}

void			eventloop_mousewheel(t_sdl_data *data)
{
	if (data->event.type == SDL_MOUSEWHEEL
	&& (int)data->event.window.windowID == data->active_window->id)
	{
		if (data->active_window->widgets->active_combobox)
		{
			if (data->event.wheel.y < 0)
			{
				scroll(
			(void*)&data->active_window->widgets->active_combobox->content, 1,
			&data->active_window->widgets->active_combobox->content_size, 5);
				combobox_update(data->active_window->widgets->active_combobox,
				data->active_window->widgets->active_combobox->content);
			}
			else
			{
				scroll(
			(void*)&data->active_window->widgets->active_combobox->content, -1,
			&data->active_window->widgets->active_combobox->content_size, 5);
				combobox_update(data->active_window->widgets->active_combobox,
				data->active_window->widgets->active_combobox->content);
			}
		}
	}
}

void			main_event_loop(t_window *window, t_sdl_data *data)
{
	int			quit;
	SDL_Point	point;

	quit = FALSE;
	while (!quit)
	{
		clear_surface(data->active_window->surface);
		draw_map_and_sector(data);
		draw_form(data->active_window->surface, data->active_window->widgets);
		SDL_UpdateWindowSurface(data->active_window->window);
		while (SDL_PollEvent(&data->event))
		{
			eventloop_window_events(data, &quit);
			eventloop_keydown(data, window, &quit);
			eventloop_mousebuttondown(data, point);
			eventloop_mousemotion(data, &point);
			eventloop_mousewheel(data);
			if (SDL_IsTextInputActive())
				render_text(data, data->event,
						data->active_window->widgets);
		}
	}
}
