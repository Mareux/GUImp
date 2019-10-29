/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_pipette.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:23:37 by ibarabas          #+#    #+#             */
/*   Updated: 2019/10/29 21:23:38 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	use_pipette(t_guimp *guimp)
{
	t_vec2f	pos;

	if (guimp->libui->mouse.m1_released || guimp->libui->mouse.m2_released)
		return ;
	pos = find_canvas_coordinates(guimp,
			vec2f((double)guimp->libui->mouse.pos.x, (double)guimp->libui->mouse.pos.y));
	if (guimp->libui->mouse.m1_pressed)
		guimp->color1 = get_pixel(guimp->canvas, (int)pos.x, (int)pos.y);
	else if (guimp->libui->mouse.m2_pressed)
		guimp->color2 = get_pixel(guimp->canvas, (int)pos.x, (int)pos.y);
}
