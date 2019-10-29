/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 20:34:28 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/29 21:03:33 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int		point_in_textfield(SDL_Point point, t_widget *widgets)
{
	t_textfield_list *tmp;

	if (!widgets)
		return (FALSE);
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

int		button_clicked(SDL_Point point, t_libui *data)
{
	t_buttons_list *tmp;

	if (!data->active_window->widgets)
		return (FALSE);
	tmp = data->active_window->widgets->button;
	while (tmp)
	{
		if (SDL_PointInRect(&point, &tmp->button.rect))
		{
			if (tmp->button.click)
			{
				tmp->button.click(data);
				tmp->button.color = (t_color){120, 80, 120, 0};
			}
			return (TRUE);
		}
		tmp = tmp->next;
	}
	return (FALSE);
}
