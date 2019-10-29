/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_menu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:54:45 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/18 23:41:18 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libui.h"

SDL_Rect	calculate_max_field_size(t_menu_field *field, TTF_Font *font)
{
	int max_text_size;
	int w;
	int h;

	max_text_size = 0;
	w = 0;
	h = 0;
	while (field)
	{
		if (field->type == FIELD_TEXT)
		{
			TTF_SizeText(font, (char*)field->data, &w, &h);
			if (w > max_text_size)
				max_text_size = w;
		}
		field = field->next;
	}
	return ((SDL_Rect){0, 0, max_text_size, h});
}

void	calculate_bar_fields_position(t_menu_field *field, TTF_Font *font)
{
	int x;
	int w;
	int h;

	x = 0;
	w = 0;
	h = 0;
	while (field)
	{
		TTF_SizeText(font, (char*)field->data, &w, &h);
		field->field_rect = (SDL_Rect){x, 0, w + 5, h + 5};
		if (field->menu)
			field->menu->menu_frame = (SDL_Rect){x, h + 5, 0, 0};
		x = w + 10;
		field = field->next;
	}
}

void	calculate_context_fields_position(t_menu_field *field,
		TTF_Font *font, SDL_Rect menu_rect)
{
	int			y;
	SDL_Rect	max_field_size;

	y = menu_rect.y;

	max_field_size = calculate_max_field_size(field, font);
	while (field)
	{
		field->field_rect = (SDL_Rect){menu_rect.x, y,
								 max_field_size.w, max_field_size.h};
		if (field->menu)
			field->menu->menu_frame = (SDL_Rect)
					{menu_rect.x + max_field_size.w, y, 0, 0};
		y += max_field_size.h;
		field = field->next;
	}
}

static SDL_Rect calculate_table_elements_size(SDL_Rect surface_size,
		int spacing)
{
	return ((SDL_Rect){
		0,
		0,
		surface_size.w / ELEMENTS_IN_TABLE - spacing,
		surface_size.w / ELEMENTS_IN_TABLE - spacing
	});
}

void calculate_table_fields_position(SDL_Surface *surface,
		t_menu *menu, t_menu_field *field)
{
	SDL_Rect	new_field_size;
	int			i;
	int			y;
	int			x;

	new_field_size = calculate_table_elements_size(
			surface->clip_rect, menu->spacing_w);
	i = 0;
	y = 0;
	x = 0;
	while (field)
	{
		if (i == ELEMENTS_IN_TABLE)
		{
			x = 0;
			i = 0;
			y += new_field_size.h + menu->spacing_h;
		}
		field->field_rect = (SDL_Rect){x, y,
								 new_field_size.w, new_field_size.h};
		x += new_field_size.w + menu->spacing_w;
		i++;
		field = field->next;
	}
}

