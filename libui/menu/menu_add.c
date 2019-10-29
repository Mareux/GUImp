/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 12:46:42 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/27 00:24:14 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libui.h"

void add_field(t_menu_field **begin, void (*click)(void *), void *data, enum e_field_data_type type)
{
	t_menu_field *new;
	t_menu_field *last;

	new = ft_memalloc(sizeof(t_menu_field));
	last = *begin;
	new->click = click;
	new->type = type;
	new->field_color = (t_color){229, 231, 233};
	new->data = data;
	new->active = TRUE;
	new->next = NULL;
	if (*begin == NULL)
	{
		*begin = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

t_menu * create_menu(enum e_menu_type type, SDL_Rect menu_frame, int id, SDL_Window *menu_window)
{
	t_menu *menu;

	menu = malloc(sizeof(t_menu));
	menu->id = id;
	menu->type = type;
	menu->fields = NULL;
	menu->opened = FALSE;
	menu->spacing_w = 5;
	menu->spacing_h = 5;
	menu->menu_color = (t_color){229, 231, 233};
	menu->active_field_color = (t_color){84, 153, 199};
	menu->menu_window = menu_window;
	menu->menu_frame = menu_frame;
	return (menu);
}

void	add_menu_to_list(t_menu_list **begin, t_menu *menu)
{
	t_menu_list *new;

	new = malloc(sizeof(t_menu_list));
	new->menu = menu;
	new->next = *begin;
	*begin = new;
}
