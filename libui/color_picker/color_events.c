/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 22:12:55 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/16 09:32:34 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libui.h"

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

t_hsv_color calculate_current_color(enum color_picker_ui_state ui_state, SDL_Point mouse,
		t_libui *libui)
{
	if (ui_state == UI_GRADIENT_CHANGE)
	{
		libui->current_color.s = ((double) clamp(0, MAIN_GRADIENT_SIZE, mouse.x) / MAIN_GRADIENT_SIZE);
		libui->current_color.v = 1.0 - ((double) clamp(0, MAIN_GRADIENT_SIZE, mouse.y) / MAIN_GRADIENT_SIZE);
	}
	else if (ui_state == UI_SLIDER_CHANGE)
	{
		libui->current_color.h = ((double) clamp(0, HUE_GRADIENT_W, mouse.x) / HUE_GRADIENT_W) * 360.0;
	}
	return (libui->current_color);
}
