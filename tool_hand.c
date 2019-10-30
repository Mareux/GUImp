/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_hand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:23:05 by ibarabas          #+#    #+#             */
/*   Updated: 2019/10/29 21:23:06 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

/*
**  Makes sure that the image is within view
*/

void	check_bounds(t_guimp *guimp)
{
	t_vec2f scaled_size;

	scaled_size.x = guimp->preview->w * guimp->canvas_data.scale;
	scaled_size.y = guimp->preview->h * guimp->canvas_data.scale;
	scaled_size.x -= guimp->libui->main_window->surface->w;
	scaled_size.y -= guimp->libui->main_window->surface->h;
	if (guimp->canvas_data.offset.x > 0)
		guimp->canvas_data.offset.x = 0;
	if (guimp->canvas_data.offset.y > 0)
		guimp->canvas_data.offset.y = 0;
	if (guimp->canvas_data.offset.x < -guimp->canvas->w *
		guimp->canvas_data.scale)
		guimp->canvas_data.offset.x = (int)(-guimp->canvas->w *
				guimp->canvas_data.scale);
	if (guimp->canvas_data.offset.y < -guimp->canvas->h *
		guimp->canvas_data.scale)
		guimp->canvas_data.offset.y = (int)(-guimp->canvas->h *
				guimp->canvas_data.scale);
}

void	use_hand(t_guimp *guimp)
{
	guimp->canvas_data.offset.x += (int)(
			(double)guimp->libui->mouse.pos.x -
			(double)guimp->libui->mouse.last_pos.x);
	guimp->canvas_data.offset.y += (int)(
			(double)guimp->libui->mouse.pos.y -
			(double)guimp->libui->mouse.last_pos.y);
	check_bounds(guimp);
}

void	guimp_m3(t_libui *libui)
{
	t_guimp *guimp;

	guimp = (t_guimp *)libui->data;
	use_hand(guimp);
}
