/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:51:59 by mnosko            #+#    #+#             */
/*   Updated: 2019/07/08 11:59:32 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void 	change_cursor(SDL_SystemCursor id)
{
	SDL_Cursor *cursor;

	cursor = SDL_CreateSystemCursor(id);
	SDL_SetCursor(cursor);
	SDL_FreeCursor(cursor);
}
