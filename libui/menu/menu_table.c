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
#include "../../guimp.h"

void create_menu_for_tools(t_libui *libui)
{
	t_cursor_surface *iter_cursor_surface;
	t_menu menu;
	t_guimp *guimp;

	iter_cursor_surface = libui->cursor_surface;
	menu = create_menu(TABLE, (SDL_Rect) {0, 0, 150, 400}, 1, get_window_surface(libui, "Tools"));
	while (iter_cursor_surface)
	{
		add_field(&menu.fields,
				 NULL,  (void*)iter_cursor_surface->cursor_image, FIELD_IMAGE);
		iter_cursor_surface = iter_cursor_surface->next;
	}
	guimp = libui->data;
	add_field(&menu.fields, (void*)color_picker_window_create, &guimp->color1, FIELD_COLOR_PICKER);
	add_field(&menu.fields, (void*)color_picker_window_create, &guimp->color2, FIELD_COLOR_PICKER);
	add_field(&menu.fields, NULL, ft_itoa(guimp->shape_data.thickness), FIELD_TEXT);
	calculate_table_fields_position(menu.menu_surface, &menu, menu.fields);
	add_menu_to_list(&libui->menu_list, menu);
}
