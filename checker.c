/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 20:34:28 by mnosko            #+#    #+#             */
/*   Updated: 2019/06/25 20:34:28 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int		point_in_textfield(SDL_Point point, t_widget *widgets)
{
	t_textfield_list *tmp;

	tmp = widgets->textfield;
	while (tmp)
	{
		if (SDL_PointInRect(&point, &tmp->textfield.rect))
		{
			if (widgets->active_textfield)
				widgets->active_textfield->active = FALSE;
			widgets->active_textfield = &tmp->textfield;
			widgets->active_textfield->active = TRUE;
			return (TRUE);
		}
		tmp = tmp->next;
	}
	return (FALSE);
}

int		button_clicked(SDL_Point point, t_widget *widgets, t_sdl_data *data)
{
	t_buttons_list *tmp;

	tmp = data->active_window->widgets->button;
	while (tmp)
	{
		if (SDL_PointInRect(&point, &tmp->button.rect))
		{
			if (tmp->button.click)
			{
				if (data->active_window->widgets->active_combobox
				&& data->active_window->widgets->active_combobox->active)
					return (FALSE);
				if (tmp->button.type == TOGGLE_BUTTON)
					widgets->active_toggle = &tmp->button;
				else
					widgets->active_button = &tmp->button;
				tmp->button.click(data);
				tmp->button.color = (t_color){120, 80, 120, 0};
			}
			return (TRUE);
		}
		tmp = tmp->next;
	}
	return (FALSE);
}

int		combobox_clicked(SDL_Point point,
		t_widget *widgets, t_sdl_data *data)
{
	t_combobox_list	*combobox;

	combobox = widgets->combobox;
	while (combobox)
	{
		if (SDL_PointInRect(&point, &combobox->combobox.field_rect))
		{
			if (widgets->active_combobox
			&& widgets->active_combobox->active)
				return (0);
			widgets->active_combobox = &combobox->combobox;
			if (combobox->combobox.event)
				combobox->combobox.event(data);
		}
		combobox = combobox->next;
	}
	return (0);
}
