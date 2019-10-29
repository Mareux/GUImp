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

#include "guimp.h"

void	on_image_save(t_libui *libui)
{
	t_window *window;

	if (!find_window(libui,"Save image"))
	{
		window = create_window_with_textfield(libui, (void *) save_img, "Save image");//refactor
		show_active_window(window);
	}
}

void	free_array(char **array)
{
	int i;
	char *tmp;

	i = 0;
	while (array[i])
	{
		tmp = array[i];
		free(tmp);
		i++;
	}
	free(array);
}

int check_image_type(char *name)
{
	char **split;
	int length;

	length = 0;
	split = ft_strsplit(name, '.');
	while (split[length])
		length++;
	if (ft_strcmp(split[length - 1], "jpg")
	&& ft_strcmp(split[length - 1], "png")
	&& ft_strcmp(split[length - 1], "jpeg"))
	{
		free_array(split);
		return (FALSE);
	}
	free_array(split);
	return (TRUE);
}

void	load_image(t_libui *libui)
{
	t_guimp *guimp;
	SDL_Surface *surface;

	guimp = libui->data;
	if (!check_image_type(libui->closed_window_return_data->data))
		return;
	surface = IMG_Load(libui->closed_window_return_data->data);
	if (surface)
		guimp->imported_img = surface;
}

void	on_load_jpeg(t_libui *libui)
{
	t_window *window;

	if (!find_window(libui, "Load JPEG/PNG"))
	{
		window = create_window_with_textfield(libui, (void*)load_image, "Load JPEG");
		show_active_window(window);
	}
}

void	load_font(t_libui *libui)
{
	t_return_data	*data;
	int				i;
	TTF_Font		*font;

	i = 0;
	data = libui->closed_window_return_data;
	while (data)
	{
		if (i == 0)
		{
			font = TTF_OpenFont(data->next->data, ft_atoi(data->data));
			if (font)
				libui->imported_font = font;
		}
		data = data->next;
		i++;
	}
}

void	on_load_font(t_libui *libui)
{
	t_window *window;

	if (!find_window(libui, "Load Font"))
	{
		window = create_font_window(libui, (void*)load_font, "Load Font");
		show_active_window(window);
	}
}

t_menu* create_file_context(SDL_Window *window)
{
	t_menu *menu;

	menu = create_menu(CONTEXT, (SDL_Rect){0, 0, 0, 0}, 3, window);
	add_field(&menu->fields, (void*)on_image_save, "Save Image", FIELD_TEXT);
	add_field(&menu->fields, (void*)on_load_jpeg, "Upload JPEG/PNG", FIELD_TEXT);
	add_field(&menu->fields, (void*)on_load_font, "Upload Font", FIELD_TEXT);
	return (menu);
}

void	clear_canvas(t_libui *libui)
{
	t_guimp *guimp;

	guimp = libui->data;
	fill_surface(guimp->canvas, rgb(255, 255, 255));
}

void create_bar(t_libui *libui)
{
	t_menu *menu;
	t_menu_field *fields;

	menu = create_menu(BAR,
			(SDL_Rect){0, 0, libui->main_window->surface->w, 30},
			2, libui->main_window->window);
	menu->opened = TRUE;
	add_field(&menu->fields, NULL, "File", FIELD_TEXT);
	fields = menu->fields;
	fields->menu = create_file_context(libui->main_window->window);
	add_field(&menu->fields, (void*)clear_canvas, "Clear Screen", FIELD_TEXT);
	calculate_bar_fields_position(menu->fields, libui->font);
	calculate_context_fields_position(fields->menu->fields, libui->font, fields->menu->menu_frame);
	add_menu_to_list(&libui->menu_list, menu);
	add_menu_to_list(&libui->menu_list, fields->menu);
}
