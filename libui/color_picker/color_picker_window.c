/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_picker_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:29:39 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/16 10:22:56 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libui.h"

void color_picker_window_create(t_libui *libui)
{
	t_window *window;

	new_window(libui, vec2(COLOR_PICKER_WINDOW_W, COLOR_PICKER_WINDOW_H), "Color picker");
	window = find_t_window(libui, "Color picker");
	SDL_SetSurfaceBlendMode(window->surface, SDL_BLENDMODE_BLEND);
}

void	draw_color_picker_window(t_libui *libui, t_hsv_color current_color)
{
	t_window *window;

	window = find_t_window(libui, "Color picker");
	fill_surface(window->surface, (t_color){0, 0, 0});
	draw_main_gradient(window->surface, current_color.h);
	draw_hue_gradient(window->surface);
	draw_sample_box(window->surface, rgb_color_to_sdl_color(hsv_to_rgb(current_color)));
	SDL_UpdateWindowSurface(window->window);
}
