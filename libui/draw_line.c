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

#include "../guimp.h"

void	draw_y(t_vec2f *start, t_vec2f *end,
		t_line *line, SDL_Surface *surface)
{
	while (line->ydiff >= 1 && start->y != end->y)
	{
		start->y += ft_fsign(line->dy);
		line->ydiff -= 1;
		if (line->ydiff >= 1)
			put_pixel(surface, (int)start->x, (int)start->y, line->color);
	}
}

void	draw(t_vec2f *start, t_vec2f *end,
		t_line *line, SDL_Surface *surface)
{
	put_pixel(surface, (int)start->x, (int)start->y, line->color);
	while (line->i++ <= (int)fabs(line->dx))
	{
		line->ydiff += line->coeff;
		draw_y(start, end, line, surface);
		put_pixel(surface, (int)start->x, (int)start->y, line->color);
		start->x += line->direction_x;
	}
}

void	line(SDL_Surface *surface, t_vec2f start,
		t_vec2f end, t_color color)
{
	t_line	line;

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
	draw(&start, &end, &line, surface);
}

void	draw_line(SDL_Surface *surface, t_vec2f start,
		t_vec2f end, t_color color)
{
	t_line	line;

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
	draw(&start, &end, &line, surface);
}
