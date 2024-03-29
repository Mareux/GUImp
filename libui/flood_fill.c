/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 23:23:36 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/29 23:24:16 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void		check_left(t_surface *surface, t_queue *queue)
{
	t_color	color;
	t_queue	*new;

	if (queue->pos.x < 1)
		return ;
	color = get_pixel(surface, queue->pos.x - 1, queue->pos.y);
	if (same_color(color, queue->target_color))
		return ;
	if (in_queue(queue, vec2(queue->pos.x - 1, queue->pos.y)))
		return ;
	if (same_color(color, queue->affected_color))
	{
		new = init_queue(queue->pos, queue->affected_color,
			queue->target_color);
		while (queue->next)
			queue = queue->next;
		queue->next = new;
		new->pos.x -= 1;
	}
}

static void		check_right(t_surface *surface, t_queue *queue)
{
	t_color	color;
	t_queue	*new;

	if (queue->pos.x >= surface->w - 1)
		return ;
	color = get_pixel(surface, queue->pos.x + 1, queue->pos.y);
	if (same_color(color, queue->target_color))
		return ;
	if (in_queue(queue, vec2(queue->pos.x + 1, queue->pos.y)))
		return ;
	if (same_color(color, queue->affected_color))
	{
		new = init_queue(queue->pos, queue->affected_color,
			queue->target_color);
		while (queue->next)
			queue = queue->next;
		queue->next = new;
		new->pos.x += 1;
	}
}

static void		check_up(t_surface *surface, t_queue *queue)
{
	t_color	color;
	t_queue	*new;

	if (queue->pos.y < 1)
		return ;
	color = get_pixel(surface, queue->pos.x, queue->pos.y - 1);
	if (same_color(color, queue->target_color))
		return ;
	if (in_queue(queue, vec2(queue->pos.x, queue->pos.y - 1)))
		return ;
	if (same_color(color, queue->affected_color))
	{
		new = init_queue(queue->pos, queue->affected_color,
			queue->target_color);
		while (queue->next)
			queue = queue->next;
		queue->next = new;
		new->pos.y -= 1;
	}
}

static void		check_down(t_surface *surface, t_queue *queue)
{
	t_color	color;
	t_queue	*new;

	if (queue->pos.y >= surface->h - 1)
		return ;
	color = get_pixel(surface, queue->pos.x, queue->pos.y + 1);
	if (same_color(color, queue->target_color))
		return ;
	if (in_queue(queue, vec2(queue->pos.x, queue->pos.y + 1)))
		return ;
	if (same_color(color, queue->affected_color))
	{
		new = init_queue(queue->pos, queue->affected_color,
			queue->target_color);
		while (queue->next)
			queue = queue->next;
		queue->next = new;
		new->pos.y += 1;
	}
}

void			flood_fill(t_surface *surface, t_vec2 pos,
	t_color affected_color, t_color target_color)
{
	t_queue	*queue;

	queue = init_queue(pos, affected_color, target_color);
	while (queue)
	{
		put_pixel(surface, queue->pos.x, queue->pos.y, target_color);
		check_left(surface, queue);
		check_right(surface, queue);
		check_up(surface, queue);
		check_down(surface, queue);
		remove_from_queue(&queue);
	}
}
