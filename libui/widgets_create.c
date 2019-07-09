/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widgets_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 19:18:59 by mnosko            #+#    #+#             */
/*   Updated: 2019/07/08 14:09:05 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_textfield		create_textfield(SDL_Surface *text_surface,
		SDL_Rect rect)
{
	t_textfield	textfield;

	textfield.id = 0;
	textfield.text_surface = text_surface;
	textfield.input_text = ft_strdup("\0");
	textfield.rect = rect;
	textfield.type = TEXT;
	textfield.color = (t_color){60, 70, 90, 0xFF};
	textfield.active_color = (t_color){250, 128, 114, 0xFF};
	textfield.visible = TRUE;
	textfield.type_check = NULL;
	textfield.active = FALSE;
	return (textfield);
}

t_combobox		create_combobox(void *data,
		SDL_Rect field_rect, t_color color)
{
	t_combobox	combobox;

	combobox.id = 0;
	combobox.field_text = NULL;
	combobox.content = data;
	combobox.content_size = 0;
	combobox.field_data = NULL;
	combobox.active = FALSE;
	combobox.color = color;
	combobox.field_rect = field_rect;
	combobox.menu_rect = (SDL_Rect){field_rect.x,
	field_rect.y + field_rect.h, field_rect.w, 80};
	combobox.menu_surface = SDL_CreateRGBSurface(0,
			combobox.menu_rect.w,
			combobox.menu_rect.h, 32, 0, 0, 0, 0);
	combobox.menu_active_field_rect = (SDL_Rect){0, 0,
	field_rect.w, field_rect.h};
	combobox.event = NULL;
	return (combobox);
}

t_label create_label(char *text, SDL_Rect rect, TTF_Font *font)
{
	t_label	label;

	label.id = 0;
//	label.text_surface = create_text_surface(text, font);
	label.text = text;
	label.font = font;
	label.rect = rect;
	label.visible = TRUE;
	return (label);
}

t_button		create_button(SDL_Surface *text_surface,
		SDL_Rect rect, int type, char *name)
{
	t_button	button;

	button.id = 0;
	button.text_surface = text_surface;
	button.rect = rect;
	button.color = (t_color) {60, 70, 90, 0xFF};
	button.visible = TRUE;
	button.transparent = FALSE;
	if (type == TOGGLE_BUTTON)
		button.transparent = TRUE;
	button.type = type;
	button.click = NULL;
	button.text = name;
	return (button);
}

t_image create_image(SDL_Rect rect, char *file)
{
	t_image	image;

	image.id = 0;
	image.rect = rect;
	image.visible = TRUE;
	image.image = IMG_Load(file);
	return (image);
}

t_menu	create_menu(enum e_menu_type type,
					int field_count,
					int column_count,
					SDL_Rect field_size)
{
	t_menu	menu;

	menu.id = 0;
	menu.menu_surface = NULL;
	menu.fields = NULL;
	menu.type = type;
	menu.field_count = field_count;
	menu.colums = column_count;
	menu.field_size = field_size;
	return (menu);
}
