/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_system_cursor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 23:36:34 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/29 23:36:36 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	set_system_cursor(t_cursor *cursor, t_libui *libui, int id)
{
	SDL_Cursor *system_cursor;

	if (libui->active_window->id == libui->main_window->id)
	{
		while (cursor)
		{
			if (cursor->id == id)
			{
				SDL_SetCursor(cursor->cursor);
				return ;
			}
			cursor = cursor->next;
		}
	}
	system_cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
	SDL_SetCursor(system_cursor);
	SDL_FreeCursor(system_cursor);
}
