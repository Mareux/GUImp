/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:15:39 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/06 20:16:06 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	calculate_table_field(t_menu_field *begin)
{
	int iterator;
	SDL_Surface *bigger_image;
	SDL_Rect rect;

	iterator = 0;
	rect = (SDL_Rect){0, 0, 0, 0};
	while (begin)
	{
		bigger_image = create_scaled_surface(begin->image, 2);
		SDL_FreeSurface(begin->image);
		begin->image = bigger_image;
		iterator++;
		begin->field_rect = rect;
		rect.x += begin->image->w;
		if (iterator == 4){
			iterator = 0;
			rect.x = 0;
			rect.y += begin->image->h;
		}
		begin = begin->next;
	}
}

void create_menu_for_tools(t_libui *libui)
{
	t_cursor_surface *iter_cursor_surface;
	t_menu menu;

	iter_cursor_surface = libui->cursor_surface;
	menu = create_menu(TABLE, (SDL_Rect){0, 0, 150, 400} , 1);
	while (iter_cursor_surface)
	{
		add_image_field(&menu.fields,
					   iter_cursor_surface->cursor_image, NULL, NULL);
		iter_cursor_surface = iter_cursor_surface->next;
	}
	calculate_table_field(menu.fields);
	add_menu_to_list(&libui->menu_list, menu);
}






