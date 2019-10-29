/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 23:27:06 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/29 23:27:08 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void		remove_from_queue(t_queue **queue)
{
	t_queue *tmp;

	tmp = (*queue)->next;
	free(*queue);
	*queue = tmp;
}

t_queue		*init_queue(t_vec2 pos,
					t_color affected_color, t_color target_color)
{
	t_queue *queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	queue->pos = pos;
	queue->next = NULL;
	queue->affected_color = affected_color;
	queue->target_color = target_color;
	return (queue);
}

int			in_queue(t_queue *queue, t_vec2 pos)
{
	while (queue)
	{
		if (queue->pos.x == pos.x &&
			queue->pos.y == pos.y)
			return (1);
		queue = queue->next;
	}
	return (0);
}
