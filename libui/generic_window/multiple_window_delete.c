/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_window_delete.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 21:50:30 by mnosko            #+#    #+#             */
/*   Updated: 2019/06/25 21:50:30 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libui.h"

void	delete_window(t_window_list **window, int id)
{
	t_window_list *curr;
	t_window_list *next;

	if (!*window)
		return ;
	curr = *window;
	if ((*window)->window.id == id)
	{
		*window = curr->next;
		SDL_DestroyWindow(curr->window.window);
		delete_widgets(&curr->window.widgets);
		free(curr);
		return ;
	}
	while (curr->next->window.id != id)
	{
		if (!curr->next)
			return ;
		curr = curr->next;
	}
	next = curr->next->next;
	free(curr->next);
	delete_widgets(&curr->next->window.widgets);
	SDL_DestroyWindow(curr->next->window.window);
	curr->next = next;
}
