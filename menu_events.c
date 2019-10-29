/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:21:30 by ibarabas          #+#    #+#             */
/*   Updated: 2019/10/29 21:21:31 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui/libui.h"
#include "guimp.h"

void	bar_on_click(t_menu_field *field)
{
	if (field->menu)
	{
		if (!field->menu->opened)
		{
			field->menu->opened = TRUE;
		}
		else
		{
			field->menu->opened = FALSE;
		}
	}
}

void	set_table_tool(t_libui *libui, t_table_tools *tool)
{
	settool(libui, tool->tool);
}

void	please_save_me_from_this_hell(t_libui *libui, t_menu_list *list,
		t_menu_field *field, SDL_Point *point)
{
	if (libui->mouse.m1_released && SDL_PointInRect(point, &field->field_rect)
		&& list->menu->opened == TRUE &&
		libui->active_window->window == SDL_GetMouseFocus())
	{
		if (field->click)
			field->click(libui);
		if (list->menu->type == BAR)
		{
			bar_on_click(field);
		}
		if (field->type == FIELD_TOOL)
		{
			set_table_tool(libui, field->data);
		}
	}
	if (SDL_PointInRect(point, &field->field_rect))
		field->field_color = list->menu->active_field_color;
	else
		field->field_color = list->menu->menu_color;
}

void	menu_events(t_libui *libui, t_menu_list *list)
{
	t_menu_field	*field;
	SDL_Point		point;

	point = (SDL_Point){libui->mouse.pos.x, libui->mouse.pos.y};
	while (list)
	{
		field = list->menu->fields;
		while (field)
		{
			if (libui->active_window->window == list->menu->menu_window)
				please_save_me_from_this_hell(libui, list, field, &point);
			field = field->next;
		}
		list = list->next;
	}
}
