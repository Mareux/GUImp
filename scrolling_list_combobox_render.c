/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrolling_list_combobox_render.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 21:53:19 by mnosko            #+#    #+#             */
/*   Updated: 2019/06/29 20:08:15 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	combobox_update(t_combobox *combobox, t_scrolling_list *list)
{
	int					y;
	t_scrolling_list	*tmp;

	clear_surface(combobox->menu_surface);
	tmp = list;
	draw_filled_rect(combobox->menu_surface,
			combobox->menu_active_field_rect, combobox->color);
	y = 0;
	while (y < combobox->menu_surface->h)
	{
		if (!tmp)
			return ;
		if (tmp->field_text)
			SDL_BlitSurface(tmp->field_text, NULL,
					combobox->menu_surface, &(SDL_Rect){0, y, 0, 0});
		tmp = tmp->next;
		y += combobox->menu_active_field_rect.h;
	}
}

void	active_field_select(t_combobox *combobox, SDL_Point mouse_point)
{
	SDL_Rect	rect;
	int			h;

	h = combobox->menu_surface->h + combobox->menu_rect.y;
	rect = (SDL_Rect){combobox->menu_rect.x, combobox->menu_rect.y,
	combobox->menu_rect.w, 20};
	while (rect.y < h)
	{
		if (SDL_PointInRect(&mouse_point, &rect))
		{
			combobox->menu_active_field_rect =
					(SDL_Rect){rect.x - combobox->menu_rect.x,
				rect.y - combobox->menu_rect.y, rect.w, rect.h};
			return ;
		}
		rect.y += 20;
	}
}

void	*active_field_clicked(SDL_Rect menu_rect,
		SDL_Point mouse_point, t_scrolling_list *list,
		t_combobox *combobox)
{
	int					h;
	t_scrolling_list	*tmp;
	SDL_Rect			rect;

	if (!list)
		return (NULL);
	tmp = list;
	rect = (SDL_Rect){menu_rect.x, menu_rect.y, menu_rect.w, 20};
	h = menu_rect.h + menu_rect.y;
	while (rect.y < h)
	{
		if (!tmp)
			return (NULL);
		if (SDL_PointInRect(&mouse_point, &rect))
		{
			combobox->field_text = tmp->field_text;
			return (tmp->data);
		}
		tmp = tmp->next;
		rect.y += 20;
	}
	return (NULL);
}

void	scroll(t_scrolling_list **list, int step,
		int *content_size, int menu_content_size)
{
	if (!*list)
		return ;
	if (step == -1)
	{
		if (!(*list)->prew)
			return ;
		if ((*content_size - menu_content_size) < -1)
			return ;
		(*content_size)++;
		*list = (*list)->prew;
	}
	else
	{
		if (!(*list)->next)
			return ;
		if (*content_size < menu_content_size)
			return ;
		(*content_size)--;
		*list = (*list)->next;
	}
}
