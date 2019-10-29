/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:24:30 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/29 21:24:33 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libui.h"

void	add_return_data(t_return_data **begin, void *data)
{
	t_return_data *new;
	t_return_data *last;

	new = ft_memalloc(sizeof(t_return_data));
	last = *begin;
	new->data = data;
	new->next = NULL;
	if (!*begin)
	{
		*begin = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

void	delete_return_data(t_return_data **begin)
{
	t_return_data *iter;
	t_return_data *tmp;

	iter = *begin;
	while (iter)
	{
		tmp = iter;
		iter = iter->next;
		free(tmp);
	}
	*begin = NULL;
}
