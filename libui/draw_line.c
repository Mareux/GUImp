/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 21:59:26 by mnosko            #+#    #+#             */
/*   Updated: 2019/06/29 20:13:25 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void		draw_y(t_vec2 *start, t_vec2 *end,
		t_line *line, SDL_Surface *surface)
{
	while (line->ydiff >= 1 && start->y != end->y)
	{
		start->y += (int)ft_fsign(line->dy);
		line->ydiff -= 1;
		if (line->ydiff >= 1)
			put_pixel(surface, start->x, start->y, line->color);
	}
}

void			draw(t_vec2 *start, t_vec2 *end,
		t_line *line, SDL_Surface *surface)
{
	put_pixel(surface, start->x, start->y, line->color);
	while (line->i++ <= (int)fabs(line->dx))
	{
		line->ydiff += line->coeff;
		draw_y(start, end, line, surface);
		put_pixel(surface, start->x, start->y, line->color);
		start->x += line->direction_x;
	}
}

void			draw_line(SDL_Surface *surface, t_vec2f start,
		t_vec2f end, t_color color)
{
	t_line		line;
	t_vec2_pair	pair;

	line.color = color;
	line.dx = end.x - start.x;
	line.dy = end.y - start.y;
	line.ydiff = 0;
	line.coeff = line.dy;
	if (start.x > end.x)
		line.direction_x = -1;
	else
		line.direction_x = 1;
	if (line.dx != 0)
		line.coeff = fabs(line.dy / line.dx);
	if (line.coeff < 0)
		line.coeff = -line.coeff;
	if (start.x > end.x)
		line.direction_x = -1;
	line.i = 0;
	pair.vec_1 = vec2f_to_vec2(start);
	pair.vec_2 = vec2f_to_vec2(end);
	draw(&pair.vec_1, &pair.vec_2, &line, surface);
}
