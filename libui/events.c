/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 17:55:33 by ibarabas          #+#    #+#             */
/*   Updated: 2019/10/20 19:15:31 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../guimp.h"

//static void		highlight_buttons(SDL_Point point, t_sdl_data *data)
//{
//	t_buttons_list *tmp;
//
//	tmp = data->active_window->widgets->button;
//	while (tmp)
//	{
//		if (SDL_PointInRect(&point, &tmp->button.rect))
//			tmp->button.color = (t_color){100, 100, 100, 0};
//		else
//			tmp->button.color = (t_color){60, 70, 90, 0};
//		tmp = tmp->next;
//	}
//}
//
//void			eventloop_mousemotion(t_sdl_data *data, SDL_Point *point)
//{
//	if (data->event.type == SDL_MOUSEMOTION
//	&& (int)data->event.window.windowID == data->active_window->id)
//	{
//		if (data->active_window->widgets->active_combobox)
//			if (data->active_window->widgets->active_combobox->active)
//			{
//				active_field_select(
//				data->active_window->widgets->active_combobox,
//				(SDL_Point) {data->event.motion.x, data->event.motion.y});
//				combobox_update(
//				data->active_window->widgets->active_combobox,
//				data->active_window->widgets->active_combobox->content);
//			}
//		SDL_GetMouseState(&(point->x), &(point->y));
//		highlight_buttons(*point, data);
//	}
//}

void			eventloop_mousewheel(t_libui *data)
{
	if (data->event.type == SDL_MOUSEWHEEL
	&& (int)data->event.window.windowID == data->active_window->id)
	{
		if (data->event.wheel.y > 0)
		{
			if (data->hooks.mwheel_up)
				data->hooks.mwheel_up(data);
		}
		else
			{
			if (data->hooks.mwheel_down)
				data->hooks.mwheel_down(data);
		}
//		if (data->active_window->widgets->active_combobox)
//		{
//			if (data->event.wheel.y < 0)
//			{
//				scroll(
//			(void*)&data->active_window->widgets->active_combobox->content, 1,
//			&data->active_window->widgets->active_combobox->content_size, 5);
//				combobox_update(data->active_window->widgets->active_combobox,
//				data->active_window->widgets->active_combobox->content);
//			}
//			else
//			{
//				scroll(
//			(void*)&data->active_window->widgets->active_combobox->content, -1,
//			&data->active_window->widgets->active_combobox->content_size, 5);
//				combobox_update(data->active_window->widgets->active_combobox,
//				data->active_window->widgets->active_combobox->content);
//			}
//		}
	}
}

t_window    *find_window_by_id(t_libui *unicorn, Uint32 id)
{
    t_window_list   *konservirovannie_shproti;

    konservirovannie_shproti = unicorn->windows;
    while (konservirovannie_shproti)
    {
        if (konservirovannie_shproti->window.id == id)
            return(&konservirovannie_shproti->window);
        konservirovannie_shproti = konservirovannie_shproti->next;
    }
    return (NULL);
}

void			eventloop_window(t_libui *unicorn)
{
    t_window    *window;

	if (unicorn->event.type == SDL_WINDOWEVENT)
	{
		if (unicorn->event.window.event == SDL_WINDOWEVENT_RESIZED)
		{
			change_window_surface(unicorn, "GUImp");
		}
        if (unicorn->event.window.event == SDL_WINDOWEVENT_FOCUS_GAINED)
        {
            window = find_window_by_id(unicorn, unicorn->event.window.windowID);
            if (window)
                unicorn->active_window = window;
        }
	}
}

void			eventloop_textinput(t_libui *libui)
{
	libui->textinput.active = 1;
	if (libui->textinput.text)
		free(libui->textinput.text);
	libui->textinput.text = ft_strdup(libui->event.text.text);
}

void			libui_loop(t_libui *unicorn)
{
	int			quit;
	SDL_Point	point;

	quit = FALSE;
	while (!quit)
	{
		unicorn->mouse.m1_released = 0;
		unicorn->mouse.m2_released = 0;
		unicorn->mouse.m3_released = 0;
		unicorn->mouse.m1_just_pressed = 0;
		unicorn->mouse.m2_just_pressed = 0;
		unicorn->mouse.last_pos.x = unicorn->mouse.pos.x;
		unicorn->mouse.last_pos.y = unicorn->mouse.pos.y;
		unicorn->textinput.active = 0;
		SDL_GetMouseState(&(unicorn->mouse.pos.x), &(unicorn->mouse.pos.y));
		set_cursor(unicorn->cursor, unicorn);
		while (SDL_PollEvent(&(unicorn->event)))
		{
			eventloop_window_events(unicorn, &quit);
			eventloop_window(unicorn);
			eventloop_keydown(unicorn, &quit);
			eventloop_mousebuttondown(unicorn, point);
//			eventloop_mousemotion(unicorn, &point);
			eventloop_mousewheel(unicorn);
			color_change_loop(unicorn);
			menu_events(unicorn, unicorn->menu_list);
			if (SDL_IsTextInputActive())
				eventloop_textinput(unicorn);
//				render_text(unicorn, unicorn->event,
//						unicorn->active_window->widgets);
		}
		if (unicorn->custom_loop)
			unicorn->custom_loop(unicorn);
		draw_all_menus(unicorn->menu_list, unicorn->font);
		if (find_window(unicorn, "Color picker"))
			draw_color_picker_window(unicorn);
		SDL_UpdateWindowSurface(find_window(unicorn, "Tools"));
		SDL_UpdateWindowSurface(unicorn->main_window->window);
	}
}
