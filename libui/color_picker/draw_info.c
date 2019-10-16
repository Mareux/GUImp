/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:36:05 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/15 22:04:02 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libui.h"

void	draw_sample_box(SDL_Surface *surface, SDL_Color color)
{
	draw_filled_rect(surface, (t_vec2){HUE_GRADIENT_W, MAIN_GRADIENT_SIZE},
			(t_vec2){HUE_GRADIENT_W + SAMPLE_BOX_SIZE,
								MAIN_GRADIENT_SIZE + SAMPLE_BOX_SIZE},
			(t_color){color.r, color.g, color.b, color.a});
}
