/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:41:35 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/20 18:39:35 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void set_cursor(t_cursor *cursor, t_libui *libui)
{
	SDL_Cursor *system_cursor;
	t_guimp *guimp;

	guimp = libui->data;
	if (libui->active_window->id == libui->main_window->id)
	{
		while (cursor)
		{
			if (cursor->id == guimp->current_tool)
			{
				SDL_SetCursor(cursor->cursor);
				return;
			}
			cursor = cursor->next;
		}
	}
	system_cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
	SDL_SetCursor(system_cursor);
	SDL_FreeCursor(system_cursor);

}
