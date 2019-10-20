/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:36:05 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/20 20:00:42 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libui.h"

void draw_sample_box(SDL_Surface *surface, SDL_Color color)
{
	draw_filled_rect(surface, (t_vec2) {HUE_GRADIENT_W, MAIN_GRADIENT_SIZE},
					 (t_vec2) {HUE_GRADIENT_W + SAMPLE_BOX_SIZE,
							   MAIN_GRADIENT_SIZE + SAMPLE_BOX_SIZE},
					 (t_color) {color.r, color.g, color.b, color.a});
}

void draw_position_indicator(SDL_Surface *surface, t_hsv_color color)
{
	draw_filled_circle(surface, (t_vec2) {color.s * MAIN_GRADIENT_SIZE - 3,
										  (1.0 - color.v) * MAIN_GRADIENT_SIZE - 3}, 1,
					   (t_color) {255, 255, 255});
}

void draw_hue_slider(SDL_Surface *surface, double hue)
{
	int x;
	int y;

	x = ((hue / 360.0) * HUE_GRADIENT_W) - 0.5;
	y = MAIN_GRADIENT_SIZE;
	draw_filled_rect(surface, (t_vec2) {x, y},
					 (t_vec2) {x + 1, y + HUE_GRADIENT_H},
					 (t_color) {255, 255, 255});
}
