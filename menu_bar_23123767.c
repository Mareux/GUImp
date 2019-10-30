/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_bar_23123767.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 00:11:38 by ibarabas          #+#    #+#             */
/*   Updated: 2019/10/30 00:11:39 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	on_load_font(t_libui *libui)
{
	t_window *window;

	if (!find_window(libui, "Load Font"))
	{
		window = create_font_window(libui, (void*)load_font, "Load Font");
		show_active_window(window);
	}
	else if ((window = find_t_window(libui, "Load Font")))
		show_active_window(window);
}

t_menu	*create_file_context(t_window *window)
{
	t_menu *menu;

	menu = create_menu(CONTEXT, return_rect(0, 0, 0, 0), 3, window->window);
	add_field((void*)&menu->fields,
			(void*)on_image_save, "Save Image", FIELD_TEXT);
	add_field((void*)&menu->fields,
			(void*)on_load_jpeg, "Upload JPEG/PNG", FIELD_TEXT);
	add_field((void*)&menu->fields,
			(void*)on_load_font, "Upload Font", FIELD_TEXT);
	return (menu);
}

void	clear_canvas(t_libui *libui)
{
	t_guimp *guimp;

	guimp = libui->data;
	fill_surface(guimp->canvas, rgb(255, 255, 255));
}

void	create_bar(t_libui *libui)
{
	t_menu			*menu;
	t_menu_field	*fields;

	menu = create_menu(BAR,
		return_rect(0, 0, libui->main_window->surface->w, 30),
		2, libui->main_window->window);
	menu->opened = TRUE;
	add_field((void*)(&menu->fields), NULL, "File", FIELD_TEXT);
	fields = menu->fields;
	fields->menu = create_file_context(libui->main_window);
	add_field((void*)&menu->fields, (void*)clear_canvas,
			"Clear Screen", FIELD_TEXT);
	calculate_bar_fields_position(menu->fields, libui->font);
	calculate_context_fields_position(fields->menu->fields,
			libui->font, fields->menu->menu_frame);
	add_menu_to_list(&libui->menu_list, menu);
	add_menu_to_list(&libui->menu_list, fields->menu);
}
