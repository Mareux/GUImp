/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 22:12:55 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/29 21:08:01 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

enum e_color_picker_ui_state	get_state(SDL_Point mouse)
{
	SDL_Rect	main_gradient;
	SDL_Rect	hue_gradient;

	main_gradient = (SDL_Rect) {0, 0, MAIN_GRADIENT_SIZE, MAIN_GRADIENT_SIZE};
	hue_gradient = (SDL_Rect) {0, MAIN_GRADIENT_SIZE,
							HUE_GRADIENT_W, HUE_GRADIENT_H};
	if (SDL_PointInRect(&mouse, &main_gradient))
		return (UI_GRADIENT_CHANGE);
	else if (SDL_PointInRect(&mouse, &hue_gradient))
		return (UI_SLIDER_CHANGE);
	return (UI_NONE);
}

void							color_change_loop(t_libui *libui)
{
	t_window *window;

	window = find_t_window(libui, "Color picker");
	if (libui->active_window && window &&
		libui->active_window->id == window->id)
	{
		if (libui->mouse.m1_pressed || libui->mouse.m2_pressed)
			calculate_current_color(get_state((SDL_Point) {libui->mouse.pos.x,
			libui->mouse.pos.y}), libui);
	}
}
