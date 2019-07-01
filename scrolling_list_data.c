/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrolling_list_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 21:55:14 by mnosko            #+#    #+#             */
/*   Updated: 2019/06/25 21:55:14 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	add_to_scrolling_list(t_scrolling_list **begin,
		SDL_Surface *field_text, void *data)
{
	t_scrolling_list *new;

	new = malloc(sizeof(t_scrolling_list));
	if (*begin)
		while ((*begin)->prew)
			(*begin) = (*begin)->prew;
	new->data = data;
	new->field_text = field_text;
	new->next = *begin;
	new->prew = NULL;
	if (*begin != NULL)
		(*begin)->prew = new;
	*begin = new;
}

void	delete_scrolling_list(t_scrolling_list **list)
{
	t_scrolling_list *tmp;

	if (!*list)
		return ;
	while ((*list)->prew)
		(*list) = (*list)->prew;
	tmp = *list;
	while (*list)
	{
		*list = (*list)->next;
		if (tmp->field_text)
		{
			SDL_FreeSurface(tmp->field_text);
			tmp->field_text = NULL;
		}
		free(tmp);
		tmp = *list;
	}
}
