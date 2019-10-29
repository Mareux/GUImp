/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guimp_draw_canvas.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:20:36 by ibarabas          #+#    #+#             */
/*   Updated: 2019/10/29 21:20:37 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

/*
**  Finds the coordinates on screen
**  that correspond to (0, 0) coordinates on canvas
*/

void    calculate_canvas_origin(t_guimp *guimp)
{
    guimp->canvas_data.topleft.x = guimp->canvas_data.offset.x;
    guimp->canvas_data.topleft.y = guimp->canvas_data.offset.y;
}

/*
**  Calculates the part of canvas
**  that will be visible on screen,
**  writes the image offset to *offset
*/

t_rect calculate_visible_rect(t_guimp *guimp)
{
    t_vec2f  scaled_size;
    t_vec2f  window_size;
    t_rect  rect;

    window_size.x = guimp->libui->main_window->surface->w;
    window_size.y = guimp->libui->main_window->surface->h;
    scaled_size.x = window_size.x / guimp->canvas_data.scale;
    scaled_size.y = window_size.y / guimp->canvas_data.scale;
    if (scaled_size.x >= window_size.x || scaled_size.y >= window_size.y)
    {
        scaled_size.x = guimp->preview->w;
        scaled_size.y = guimp->preview->h;
    }
    else
    {
        scaled_size.x += 10;
        scaled_size.y += 10;
    }
    rect.topleft.x = -guimp->canvas_data.offset.x / guimp->canvas_data.scale;
    rect.topleft.y = -guimp->canvas_data.offset.y / guimp->canvas_data.scale;
    rect.bottomright.x = rect.topleft.x + scaled_size.x;
    rect.bottomright.y = rect.topleft.y + scaled_size.y;
    return (rect);
}

void	draw_canvas(t_guimp *guimp)
{
	t_surface *scaled;
	t_rect  visible_rect;
	t_vec2  offset;

    offset.x = 0;
    offset.y = 0;
    calculate_canvas_origin(guimp);
	visible_rect = calculate_visible_rect(guimp);
	scaled = create_scaled_area(guimp->preview, guimp->canvas_data.scale,
	        vec2f_to_vec2(visible_rect.topleft),
	        vec2f_to_vec2(visible_rect.bottomright));
    blit_with_offset(scaled, guimp->libui->main_window->surface, offset);
	free_surface(scaled);
}
