/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guimp_redo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:21:02 by ibarabas          #+#    #+#             */
/*   Updated: 2019/10/29 21:21:03 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	pull_from_redo_buffer(t_guimp *guimp)
{
	t_undo *tmp;

	if (guimp->redo_buffer)
	{
		copy_surface(guimp->redo_buffer->surface, guimp->canvas);
		tmp = guimp->redo_buffer;
		guimp->redo_buffer = tmp->next;
		free_surface(tmp->surface);
		free(tmp);
	}
}

void	guimp_redo(t_libui *libui)
{
	t_guimp *guimp;

	guimp = (t_guimp *)libui->data;
	if (!guimp->redo_buffer)
		return ;
	push_to_buffer(guimp);
	pull_from_redo_buffer(guimp);
}

void	backup_buffer(t_guimp *guimp)
{
	t_undo *new;

	if (!guimp->undo_buffer)
		return ;
	new = new_buffer_item();
	new->surface = duplicate_surface(guimp->canvas);
	new->next = guimp->redo_buffer;
	guimp->redo_buffer = new;
	limit_buffer(guimp->redo_buffer);
}
