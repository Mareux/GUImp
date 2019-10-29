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

void	use_magnifying_glass(t_guimp *guimp)
{
	if (guimp->libui->mouse.m1_pressed)
	{
		if (guimp->canvas_data.scale > 10)
			return ;
        guimp->canvas_data.offset.x -= (int)(find_canvas_coordinates(guimp,
                vec2_to_vec2f(guimp->libui->mouse.pos)).x *
                guimp->canvas_data.scale * 1.1 -
                find_canvas_coordinates(guimp, vec2_to_vec2f(guimp->libui->mouse.pos)).x
                * guimp->canvas_data.scale);
        guimp->canvas_data.offset.y -= (int)(find_canvas_coordinates(guimp,
               vec2_to_vec2f(guimp->libui->mouse.pos)).y *
               guimp->canvas_data.scale * 1.1 -
               find_canvas_coordinates(guimp, vec2_to_vec2f(guimp->libui->mouse.pos)).y
               * guimp->canvas_data.scale);
		guimp->canvas_data.scale *= 1.1;
	}
	else
	{
		if (guimp->canvas_data.scale < 0.1)
			return ;
        guimp->canvas_data.offset.x -= (int)(find_canvas_coordinates(guimp,
              vec2_to_vec2f(guimp->libui->mouse.pos)).x
              * guimp->canvas_data.scale / 1.1 -
              find_canvas_coordinates(guimp, vec2_to_vec2f(guimp->libui->mouse.pos)).x
              * guimp->canvas_data.scale);
        guimp->canvas_data.offset.y -= (int)(find_canvas_coordinates(guimp,
             vec2_to_vec2f(guimp->libui->mouse.pos)).y
             * guimp->canvas_data.scale / 1.1 -
             find_canvas_coordinates(guimp, vec2_to_vec2f(guimp->libui->mouse.pos)).y
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
    guimp->canvas_data.offset.x -= (int)(find_canvas_coordinates(guimp,
            vec2_to_vec2f(guimp->libui->mouse.pos)).x *
            guimp->canvas_data.scale * 1.05 -
            find_canvas_coordinates(guimp, vec2_to_vec2f(guimp->libui->mouse.pos)).x
            * guimp->canvas_data.scale);
    guimp->canvas_data.offset.y -= (int)(find_canvas_coordinates(guimp,
            vec2_to_vec2f(guimp->libui->mouse.pos)).y *
            guimp->canvas_data.scale * 1.05 -
            find_canvas_coordinates(guimp, vec2_to_vec2f(guimp->libui->mouse.pos)).y
            * guimp->canvas_data.scale);
	guimp->canvas_data.scale *= 1.05;
    check_bounds(guimp);
}

void	zoom_out(t_guimp *guimp)
{
	if (guimp->canvas_data.scale < 0.1)
		return ;
	guimp->canvas_data.scale *= 0.95;
    guimp->canvas_data.offset.x -= (int)(find_canvas_coordinates(guimp,
            vec2_to_vec2f(guimp->libui->mouse.pos)).x
            * guimp->canvas_data.scale * 0.95 -
            find_canvas_coordinates(guimp, vec2_to_vec2f(guimp->libui->mouse.pos)).x
            * guimp->canvas_data.scale);
    guimp->canvas_data.offset.y -= (int)(find_canvas_coordinates(guimp,
            vec2_to_vec2f(guimp->libui->mouse.pos)).y
            * guimp->canvas_data.scale * 0.95 -
            find_canvas_coordinates(guimp, vec2_to_vec2f(guimp->libui->mouse.pos)).y
            * guimp->canvas_data.scale);
    check_bounds(guimp);
}
