/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_pencil.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:23:27 by ibarabas          #+#    #+#             */
/*   Updated: 2019/10/29 21:23:28 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

t_vec2f	find_canvas_coordinates(t_guimp *guimp, t_vec2f screen_coordinates)
{
	t_vec2	canvas_size;
	t_vec2f	point;
	t_vec2f	ndc;

	canvas_size = find_scaled_surface_size(guimp->canvas,
			guimp->canvas_data.scale);
	point.x = screen_coordinates.x - guimp->canvas_data.topleft.x;
	point.y = screen_coordinates.y - guimp->canvas_data.topleft.y;
	ndc.x = point.x / (double)canvas_size.x;
	ndc.y = point.y / (double)canvas_size.y;
	point.x = ndc.x * (double)guimp->canvas->w;
	point.y = ndc.y * (double)guimp->canvas->h;
	return (point);
}

void	use_pencil(t_guimp *guimp)
{
	t_color	color;
	t_vec2f	pos1;
	t_vec2f	pos2;

	color = (t_color){0, 0, 0};
	if (guimp->libui->mouse.m1_released || guimp->libui->mouse.m2_released)
		return ;
	if (guimp->libui->mouse.m1_just_pressed ||
	guimp->libui->mouse.m2_just_pressed)
		push_to_buffer(guimp);
	pos1 = find_canvas_coordinates(guimp,
			vec2f((double)guimp->libui->mouse.last_pos.x,
					(double)guimp->libui->mouse.last_pos.y));
	pos2 = find_canvas_coordinates(guimp,
			vec2f((double)guimp->libui->mouse.pos.x,
					(double)guimp->libui->mouse.pos.y));
	if (guimp->libui->mouse.m1_pressed)
		color = guimp->color1;
	else if (guimp->libui->mouse.m2_pressed)
		color = guimp->color2;
	draw_line(guimp->canvas,
			pos1,
			pos2,
			color);
}
