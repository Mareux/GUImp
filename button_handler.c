/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:54:03 by mnosko            #+#    #+#             */
/*   Updated: 2019/06/25 19:54:03 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void		toggle_button_handler(t_sdl_data *data)
{
	t_buttons_list	*button;

	button = data->active_window->widgets->button;
	data->active_window->widgets->active_toggle->transparent = FALSE;
	while (button)
	{
		if (button->button.text_surface
		!= data->active_window->widgets->active_toggle->text_surface
		&& button->button.click
		== data->active_window->widgets->active_toggle->click)
			button->button.transparent = TRUE;
		button = button->next;
	}
}
