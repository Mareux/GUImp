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

void 		put_sticker(t_surface *img, t_surface *canvas, t_vec2 pos)
{
	t_int_rect	src;
	t_vec2	target;

	src.topleft = vec2(0, 0);
	src.bottomright = vec2(img->w, img->h);
	target.x = pos.x - img->w / 2;
	target.y = pos.y - img->h / 2;
	blit_surface(img, src, canvas, target);
}

static void	draw_y(t_vec2f *start, t_vec2f *end,
					  t_line *line, t_surface *sticker)
{
	while (line->ydiff >= 1 && start->y != end->y)
	{
		start->y += ft_fsign(line->dy);
		line->ydiff -= 1;
		if (line->ydiff >= 1)
			put_sticker(sticker, line->target_surface, vec2f_to_vec2(*start));
	}
}

static void	draw(t_vec2f *start, t_vec2f *end,
			 t_line *line, t_surface *sticker)
{
	put_sticker(sticker, line->target_surface, vec2f_to_vec2(*start));
	while (line->i++ <= (int)fabs(line->dx))
	{
		line->ydiff += line->coeff;
		draw_y(start, end, line, sticker);
		put_sticker(sticker, line->target_surface, vec2f_to_vec2(*start));
		start->x += line->direction_x;
	}
}

void		draw_line_of_stickers(SDL_Surface *surface, t_vec2f start,
				  t_vec2f end, t_surface *sticker)
{
	t_line	line;

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
	line.target_surface = surface;
	draw(&start, &end, &line, sticker);
}
