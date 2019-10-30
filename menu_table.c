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

#include "guimp.h"

void	change_thickness(t_libui *libui)
{
	t_guimp	*guimp;
	int		thickness;

	thickness = ft_atoi(libui->closed_window_return_data->data);
	if (thickness <= 0 || thickness > 40)
		return ;
	guimp = libui->data;
	guimp->shape_data.thickness = thickness;
}

void	on_thickness_clicked(t_libui *libui)
{
	t_window *window;

	if (!find_window(libui, "Thickness"))
	{
		window = create_window_with_textfield(libui,
				(void*)change_thickness, "Thickness");
		show_active_window(window);
	}
	else if ((window = find_t_window(libui, "Thickness")))
		show_active_window(window);
}

void	i_dont_even_care_anymore(t_libui *libui, t_menu *menu)
{
	t_guimp				*guimp;
	int					*th;

	guimp = libui->data;
	add_field(&menu->fields, (void*)color_picker_window_create,
			&guimp->color1, FIELD_COLOR_PICKER);
	add_field(&menu->fields, (void*)color_picker_window_create,
			&guimp->color2, FIELD_COLOR_PICKER);
	th = &guimp->shape_data.thickness;
	add_field(&menu->fields, (void*)on_thickness_clicked, th, FIELD_NUMBER);
	calculate_table_fields_position(get_window_surface(menu->menu_window),
			menu, menu->fields);
	add_menu_to_list(&libui->menu_list, menu);
}

void	create_menu_for_tools(t_libui *libui)
{
	t_cursor_surface	*iter_cursor_surface;
	t_menu				*menu;
	t_table_tools		*tool;

	iter_cursor_surface = libui->cursor_surface;
	menu = create_menu(TABLE, return_rect(0, 0, 150, 400),
			1, find_window(libui, "Tools"));
	menu->opened = TRUE;
	while (iter_cursor_surface)
	{
		if (iter_cursor_surface->id == -1)
		{
			iter_cursor_surface = iter_cursor_surface->next;
			continue;
		}
		tool = malloc(sizeof(t_table_tools));
		tool->image = iter_cursor_surface->cursor_image;
		tool->tool = iter_cursor_surface->id;
		add_field(&menu->fields,
			NULL, tool, FIELD_TOOL);
		iter_cursor_surface = iter_cursor_surface->next;
	}
	i_dont_even_care_anymore(libui, menu);
}
