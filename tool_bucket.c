/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_bucket.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:22:50 by ibarabas          #+#    #+#             */
/*   Updated: 2019/10/29 21:22:51 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	use_bucket(t_guimp *guimp)
{
	t_color			color;
	t_vec2f			pos;
	t_vec2			int_pos;

	color = (t_color){0, 0, 0};
	pos = find_canvas_coordinates(guimp,
			vec2f((double)guimp->libui->mouse.pos.x,
					(double)guimp->libui->mouse.pos.y));
	if (!pixel_inside_surface(guimp->canvas, (int)pos.x, (int)pos.y))
		return ;
	int_pos.x = (int)pos.x;
	int_pos.y = (int)pos.y;
	if (guimp->libui->mouse.m1_pressed)
		color = guimp->color1;
	else if (guimp->libui->mouse.m2_pressed)
		color = guimp->color2;
	push_to_buffer(guimp);
	flood_fill(guimp->canvas, int_pos, get_pixel(guimp->canvas,
			int_pos.x, int_pos.y), color);
}
