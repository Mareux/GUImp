/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_bar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:12:02 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/27 23:12:34 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libui.h"
#include "../../guimp.h"

void	on_image_save(t_libui *libui)
{
	t_window *window;

	if (!find_window(libui,"Save image"))
	{
		window = create_window_with_textfield(libui, (void *) save_img, "Save image");//refactor
		show_active_window(window);
	}
}

t_menu* create_file_context(SDL_Window *window)
{
	t_menu *menu;

	menu = create_menu(CONTEXT, (SDL_Rect){0, 0, 0, 0}, 3, window);
	add_field(&menu->fields, (void*)on_image_save, "Save Image", FIELD_TEXT);

	return (menu);
}

void create_bar(t_libui *libui)
{
	t_menu *menu;
	t_menu_field *fields;

	menu = create_menu(BAR,
			(SDL_Rect){0, 0, 30, libui->main_window->surface->w},
			2, libui->main_window->window);
	add_field(&menu->fields, NULL, "File", FIELD_TEXT);
	fields = menu->fields;
	// noozhno zaschitit' malloc
	fields->menu = create_file_context(libui->main_window->window);
	calculate_bar_fields_position(menu->fields, libui->font);
	calculate_context_fields_position(fields->menu->fields, libui->font, fields->menu->menu_frame);
	add_menu_to_list(&libui->menu_list, menu);
	add_menu_to_list(&libui->menu_list, fields->menu);
}
