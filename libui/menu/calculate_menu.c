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

void	calculate_max_field_size(t_menu_field *field, t_menu *menu, TTF_Font *font)
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
	menu->max_field_size = (SDL_Rect){0, 0, max_text_size, h};
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

void calculate_table_fields_position(SDL_Surface *surface, t_menu *menu, t_menu_field *field)
{
	SDL_Rect new_field_size;
	int i;
	int y;
	int x;

	new_field_size = calculate_table_elements_size(surface->clip_rect, menu->spacing_w);
	i = 0;
	y = 0;
	x = 0;
	while (field)
	{

		field = field->next;
	}
}

