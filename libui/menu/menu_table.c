/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:15:39 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/28 10:34:57 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libui.h"
#include "../../guimp.h"

void create_menu_for_tools(t_libui *libui)
{
	t_cursor_surface *iter_cursor_surface;
	t_menu *menu;
	t_guimp *guimp;
	t_table_tools *tool;

	iter_cursor_surface = libui->cursor_surface;
	menu = create_menu(TABLE, (SDL_Rect) {0, 0, 150, 400}, 1, find_window(libui, "Tools"));
	while (iter_cursor_surface)
	{
		tool = malloc(sizeof(t_table_tools));
		tool->image = iter_cursor_surface->cursor_image;
		tool->tool = iter_cursor_surface->id;
		add_field(&menu->fields,
				 NULL,  tool, FIELD_TOOL);
		iter_cursor_surface = iter_cursor_surface->next;
	}
	guimp = libui->data;
	add_field(&menu->fields, (void*)color_picker_window_create, &guimp->color1, FIELD_COLOR_PICKER);
	add_field(&menu->fields, (void*)color_picker_window_create, &guimp->color2, FIELD_COLOR_PICKER);
	add_field(&menu->fields, NULL, ft_itoa(guimp->shape_data.thickness), FIELD_TEXT);
	calculate_table_fields_position(SDL_GetWindowSurface(menu->menu_window), menu, menu->fields);
	add_menu_to_list(&libui->menu_list, menu);
}
