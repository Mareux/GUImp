/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:15:39 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/18 22:29:02 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libui.h"

void create_menu_for_tools(t_libui *libui)
{
	t_cursor_surface *iter_cursor_surface;
	t_menu menu;

	iter_cursor_surface = libui->cursor_surface;
	menu = create_menu(TABLE, (SDL_Rect){0, 0, 150, 400} , 1);
	while (iter_cursor_surface)
	{
		add_field(&menu.fields,
				 NULL,  (void*)iter_cursor_surface->cursor_image, FIELD_IMAGE);
		iter_cursor_surface = iter_cursor_surface->next;
	}

	add_menu_to_list(&libui->menu_list, menu);
}
