/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rect_to_square.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:20:01 by ibarabas          #+#    #+#             */
/*   Updated: 2019/10/29 21:20:06 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

/*
**	Calculates what needs to be added to src
**	to make it the same length as dst
*/

static int	length_diff(int src, int dst)
{
	int diff;

	diff = ft_abs(dst) - ft_abs(src);
	if (src > 0)
		return (diff);
	return (-diff);
}

t_vec2_pair	convert_rect_to_square(t_vec2_pair pair)
{
	t_vec2 diff;

	diff.x = pair.vec_1.x - pair.vec_2.x;
	diff.y = pair.vec_1.y - pair.vec_2.y;
	if (ft_abs(diff.x) < ft_abs(diff.y))
	{
		pair.vec_1.y += length_diff(diff.y, diff.x);
	}
	else
	{
		pair.vec_1.x += length_diff(diff.x, diff.y);
	}
	return (pair);
}

void		calculate_current_color(
		enum color_picker_ui_state ui_state, t_libui *libui)
{
	t_guimp *guimp;
	t_color color;

	guimp = libui->data;
	if (ui_state == UI_GRADIENT_CHANGE)
	{
		libui->current_color.s = ((double)clamp(0, MAIN_GRADIENT_SIZE,
			libui->mouse.pos.x) / MAIN_GRADIENT_SIZE);
		libui->current_color.v = 1.0 - ((double)clamp(0, MAIN_GRADIENT_SIZE,
			libui->mouse.pos.y) / MAIN_GRADIENT_SIZE);
	}
	else if (ui_state == UI_SLIDER_CHANGE)
	{
		libui->current_color.h = ((double)clamp(0, HUE_GRADIENT_W,
			libui->mouse.pos.x) / HUE_GRADIENT_W) * 360.0;
	}
	color = rgb_color_to_t_color(hsv_to_rgb(libui->current_color));
	if (libui->mouse.m1_pressed)
		guimp->color1 = (t_color) {color.r, color.g, color.b};
	else if (libui->mouse.m2_pressed)
		guimp->color2 = (t_color) {color.r, color.g, color.b};
}
