/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_thick_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:49:49 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/29 21:49:51 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void		draw_y(
		t_vec2_pair *v,
		t_line *line,
		SDL_Surface *surface,
		int thickness)
{
	while (line->ydiff >= 1 && v->vec_1.y != v->vec_2.y)
	{
		v->vec_1.y += ft_fsign(line->dy);
		line->ydiff -= 1;
		if (line->ydiff >= 1)
			draw_filled_circle(surface,
					vec2((int)(v->vec_1.x), (int)(v->vec_1.y)),
					thickness, line->color);
	}
}

static void		draw(
		t_vec2_pair *v,
		t_line *line,
		SDL_Surface *surface,
		int thickness)
{
	draw_filled_circle(surface, vec2((int)(v->vec_1.x),
			(int)(v->vec_1.y)), thickness, line->color);
	while (line->i++ <= (int)fabs(line->dx))
	{
		line->ydiff += line->coeff;
		draw_y(v, line, surface, thickness);
		draw_filled_circle(surface, vec2((int)(v->vec_1.x),
				(int)(v->vec_1.y)), thickness, line->color);
		v->vec_1.x += line->direction_x;
	}
}

void			draw_thick_line(
		SDL_Surface *surface,
		t_vec2f_pair v,
		t_color color,
		int thickness)
{
	t_line		line;
	t_vec2_pair	pair;

	line.color = color;
	line.dx = v.vec_2.x - v.vec_1.x;
	line.dy = v.vec_2.y - v.vec_1.y;
	line.ydiff = 0;
	line.coeff = line.dy;
	if (v.vec_1.x > v.vec_2.x)
		line.direction_x = -1;
	else
		line.direction_x = 1;
	if (line.dx != 0)
		line.coeff = fabs(line.dy / line.dx);
	if (line.coeff < 0)
		line.coeff = -line.coeff;
	if (v.vec_1.x > v.vec_2.x)
		line.direction_x = -1;
	line.i = 0;
	pair.vec_1 = vec2f_to_vec2(v.vec_1);
	pair.vec_2 = vec2f_to_vec2(v.vec_2);
	draw(&pair, &line, surface, thickness);
}
