/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 17:55:47 by ibarabas          #+#    #+#             */
/*   Updated: 2019/07/09 17:54:21 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../guimp.h"

//void	eventloop_window_events(t_libui *data, int *quit)
//{
//	if (data->event.type == SDL_WINDOWEVENT
//	&& (int)data->event.window.windowID == data->active_window->id)
//	{
//		if (data->event.window.event == SDL_WINDOWEVENT_CLOSE)
//		{
//			if (data->active_window->id != data->main_window->id)
//			{
//				hide_active_window(&data->active_window,
//						data->main_window, &data->windows);
//			}
//			*quit = TRUE;
//		}
//	}
//}

void	eventloop_keydown(t_libui *data, int *quit)
{
	t_keybind	*keybind;

	if (data->event.type == SDL_KEYUP
	&& (int)data->event.window.windowID == data->main_window->id)
	{
		if (data->event.key.keysym.scancode
			== SDL_SCANCODE_ESCAPE)
		{
//			if (window->id != data->main_window->id)
//			{
//				hide_active_window(&data->active_window,
//						data->main_window, &data->windows);
//			}
			*quit = TRUE;
		}
		if (data->event.key.keysym.scancode
			== SDL_SCANCODE_S && (SDL_GetModState() & KMOD_CTRL))
		{
			t_guimp *guimp;

			guimp = data->data;
			save_img(guimp->canvas, "test.jpg");
		}
		keybind = data->hooks.keybinds;
		while (keybind)
		{
			// Currently supports only one key at a time
			// Need to change this code to allow key combinations
			if (keybind->keys)
			{
				if (data->event.key.keysym.scancode == keybind->keys->scancode)
					keybind->func(data);
			}
			keybind = keybind->next;
		}
	}
}

//void	eventloop_mousebuttondown_2(t_libui *data, SDL_Point point)
//{
//	if (data->active_window->widgets->active_combobox
//	&& data->active_window->widgets->active_combobox->active
//	&& (data->active_window->widgets->active_combobox->field_data =
//			active_field_clicked(
//	data->active_window->widgets->active_combobox->menu_rect, point,
//	data->active_window->widgets->active_combobox->content,
//	data->active_window->widgets->active_combobox)))
//		data->active_window->widgets->active_combobox->active = FALSE;
//}

void	eventloop_mousebuttondown(t_libui *data, SDL_Point point)
{
	if (data->event.type == SDL_MOUSEBUTTONDOWN &&
		(int)data->event.window.windowID == data->active_window->id)
	{
		if (data->event.button.button == SDL_BUTTON_LEFT)
		{
			data->mouse.m1_pressed = 1;
			if (data->hooks.mouse1_down)
				data->hooks.mouse1_down(data);
//			if (point_in_textfield(point, data->active_window->widgets))
//				if (!SDL_IsTextInputActive())
//					SDL_StartTextInput();
//			if (button_clicked(point, data->active_window->widgets, data))
//				if (SDL_IsTextInputActive())
//					SDL_StopTextInput();
//			if (combobox_clicked(point,
//					data->active_window->widgets, data))
//			{
//				if (SDL_IsTextInputActive())
//					SDL_StopTextInput();
//			}
//			eventloop_mousebuttondown_2(data, point);
		}
		else if (data->event.button.button == SDL_BUTTON_RIGHT)
		{
			data->mouse.m2_pressed = 1;
			if (data->hooks.mouse2_down)
				data->hooks.mouse2_down(data);
		}
		else if (data->event.button.button == SDL_BUTTON_MIDDLE)
		{
			data->mouse.m3_pressed = 1;
			if (data->hooks.mouse3_down)
				data->hooks.mouse3_down(data);
		}
	}
	else if (data->event.type == SDL_MOUSEBUTTONUP)
	{
		if (data->event.button.button == SDL_BUTTON_LEFT)
		{
			data->mouse.m1_pressed = 0;
			data->mouse.m1_released = 1;
		}
		if (data->event.button.button == SDL_BUTTON_RIGHT)
		{
			data->mouse.m2_pressed = 0;
			data->mouse.m2_released = 1;
		}
		if (data->event.button.button == SDL_BUTTON_MIDDLE)
		{
			data->mouse.m3_pressed = 0;
			data->mouse.m3_released = 1;
		}
	}
}
