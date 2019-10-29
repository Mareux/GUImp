/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_magnifying_glass.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:23:23 by ibarabas          #+#    #+#             */
/*   Updated: 2019/10/29 21:23:24 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	spooky_scary_function(t_guimp *guimp, double nbr)
{
	guimp->canvas_data.offset.x -= (int)(find_canvas_coordinates(guimp,
		vec2_to_vec2f(guimp->libui->mouse.pos)).x *
		guimp->canvas_data.scale * nbr -
		find_canvas_coordinates(guimp, vec2_to_vec2f(guimp->libui->mouse.pos)).x
		* guimp->canvas_data.scale);
	guimp->canvas_data.offset.y -= (int)(find_canvas_coordinates(guimp,
		vec2_to_vec2f(guimp->libui->mouse.pos)).y *
		guimp->canvas_data.scale * nbr -
		find_canvas_coordinates(guimp, vec2_to_vec2f(guimp->libui->mouse.pos)).y
		* guimp->canvas_data.scale);
}

void	use_magnifying_glass(t_guimp *guimp)
{
	if (guimp->libui->mouse.m1_pressed)
	{
		if (guimp->canvas_data.scale > 10)
			return ;
		spooky_scary_function(guimp, 1.1);
		guimp->canvas_data.scale *= 1.1;
	}
	else
	{
		if (guimp->canvas_data.scale < 0.1)
			return ;
		guimp->canvas_data.offset.x -= (int)(find_canvas_coordinates(guimp,
			vec2_to_vec2f(guimp->libui->mouse.pos)).x * guimp->canvas_data.scale
			/ 1.1 - find_canvas_coordinates(guimp, vec2_to_vec2f(
			guimp->libui->mouse.pos)).x * guimp->canvas_data.scale);
		guimp->canvas_data.offset.y -= (int)(find_canvas_coordinates(guimp,
			vec2_to_vec2f(guimp->libui->mouse.pos)).y
			* guimp->canvas_data.scale / 1.1 -
			find_canvas_coordinates(guimp,
					vec2_to_vec2f(guimp->libui->mouse.pos)).y
			* guimp->canvas_data.scale);
		guimp->canvas_data.scale /= 1.1;
	}
	check_bounds(guimp);
}

void	zoom_in(t_guimp *guimp)
{
	if (guimp->canvas_data.scale > 10)
		return ;
	check_bounds(guimp);
	spooky_scary_function(guimp, 1.05);
	guimp->canvas_data.scale *= 1.05;
	check_bounds(guimp);
}

void	zoom_out(t_guimp *guimp)
{
	if (guimp->canvas_data.scale < 0.1)
		return ;
	spooky_scary_function(guimp, 0.95);
	guimp->canvas_data.scale *= 0.95;
	check_bounds(guimp);
}
