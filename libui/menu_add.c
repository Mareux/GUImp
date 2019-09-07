/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 12:46:42 by mnosko            #+#    #+#             */
/*   Updated: 2019/09/06 18:23:14 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	add_field(t_menu_field **begin, SDL_Rect field_rect, char *field_text,
		void (*click)(void *))
{
	t_menu_field *new;

	new = ft_memalloc(sizeof(t_menu_field));
	new->click = click;
	new->active_color = (t_color){340, 6, 100};
	new->color = (t_color){350, 25, 100};
	new->field_rect = field_rect;
	new->active = TRUE;
	new->next = *begin;
	new->prew = NULL;
	if (*begin != NULL)
		(*begin)->prew = new;
	*begin = new;
}

t_menu	create_menu(enum e_menu_type type, SDL_Rect menu_frame, int id)
{
	t_menu menu;

	menu.id = id;
	menu.type = type;
	menu.fields = NULL;
	menu.opened = FALSE;
	menu.menu_surface = SDL_CreateRGBSurface(0,
			menu_frame.w, menu_frame.h, 32, 0, 0, 0, 0);
	menu.menu_frame = menu_frame;
	return (menu);
}

void	add_menu_to_list(t_menu_list **begin, t_menu menu)
{
	t_menu_list *new;

	new = malloc(sizeof(t_menu_list));
	new->menu = menu;
	new->next = *begin;
	*begin = new;
}
