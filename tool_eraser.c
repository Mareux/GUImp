/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_eraser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:22:59 by ibarabas          #+#    #+#             */
/*   Updated: 2019/10/29 21:23:00 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	use_eraser(t_guimp *guimp)
{
	t_vec2f_pair	pair;
	t_color			color;

	if (guimp->libui->mouse.m1_released || guimp->libui->mouse.m2_released)
		return ;
	if (guimp->libui->mouse.m1_just_pressed ||
	guimp->libui->mouse.m2_just_pressed)
		push_to_buffer(guimp);
	pair.vec_1 = find_canvas_coordinates(guimp,
			vec2f((double)guimp->libui->mouse.last_pos.x,
			(double)guimp->libui->mouse.last_pos.y));
	pair.vec_2 = find_canvas_coordinates(guimp,
			vec2f((double)guimp->libui->mouse.pos.x,
			(double)guimp->libui->mouse.pos.y));
	color = rgba(255, 255, 255, 1);
	draw_thick_line(guimp->canvas, pair,
			color, guimp->shape_data.thickness);
}
