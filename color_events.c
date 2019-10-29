/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 22:12:55 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/20 19:43:04 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

enum color_picker_ui_state get_state(SDL_Point mouse)
{
	SDL_Rect main_gradient;
	SDL_Rect hue_gradient;

	main_gradient = (SDL_Rect) {0, 0, MAIN_GRADIENT_SIZE, MAIN_GRADIENT_SIZE};
	hue_gradient = (SDL_Rect) {0, MAIN_GRADIENT_SIZE, HUE_GRADIENT_W, HUE_GRADIENT_H};
	if (SDL_PointInRect(&mouse, &main_gradient))
		return UI_GRADIENT_CHANGE;
	else if (SDL_PointInRect(&mouse, &hue_gradient))
		return UI_SLIDER_CHANGE;
	return UI_NONE;
}

void calculate_current_color(enum color_picker_ui_state ui_state, t_libui *libui)
{
	t_guimp *guimp;
	SDL_Color color;

	guimp = libui->data;
	if (ui_state == UI_GRADIENT_CHANGE)
	{
		libui->current_color.s = ((double) clamp(0, MAIN_GRADIENT_SIZE, libui->mouse.pos.x) / MAIN_GRADIENT_SIZE);
		libui->current_color.v = 1.0 - ((double) clamp(0, MAIN_GRADIENT_SIZE, libui->mouse.pos.y) / MAIN_GRADIENT_SIZE);
	}
	else if (ui_state == UI_SLIDER_CHANGE)
	{
		libui->current_color.h = ((double) clamp(0, HUE_GRADIENT_W, libui->mouse.pos.x) / HUE_GRADIENT_W) * 360.0;
	}
	color = rgb_color_to_sdl_color(hsv_to_rgb(libui->current_color));
	if (libui->mouse.m1_pressed)
		guimp->color1 = (t_color){color.r, color.g, color.b};
	else if (libui->mouse.m2_pressed)
		guimp->color2 = (t_color){color.r, color.g, color.b};
}

void color_change_loop(t_libui *libui)
{
	t_window *window;

	window = find_t_window(libui, "Color picker");
	if (libui->active_window && window && libui->active_window->id == window->id)
	{
		if (libui->mouse.m1_pressed || libui->mouse.m2_pressed)
			calculate_current_color(get_state((SDL_Point){libui->mouse.pos.x, libui->mouse.pos.y}), libui);
	}
}
