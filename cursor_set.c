/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:41:35 by mnosko            #+#    #+#             */
/*   Updated: 2019/09/29 15:55:37 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui/libui.h"

void 	set_cursor(t_cursor *cursor, int id)
{
	SDL_Cursor *system_cursor;

		while (cursor)
		{
			if (cursor->id == id)
			{
				SDL_SetCursor(cursor->cursor);
				return ;
			}
			cursor = cursor->next;
		}
	system_cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
	SDL_SetCursor(system_cursor);
	SDL_FreeCursor(system_cursor);

}
