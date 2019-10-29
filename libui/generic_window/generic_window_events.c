/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_window_events.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:55:18 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/21 15:55:18 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libui.h"

void	cancel_event(t_libui *libui)
{
	libui->closed_window_return_data = NULL;
	hide_active_window(&libui->active_window, libui->main_window, &libui->windows);
}

void	ok_event(t_libui *libui)
{
	t_textfield_list *textfield;

	textfield = libui->active_window->widgets->textfield;
	if (libui->active_window
	&& libui->active_window->widgets
	&& textfield)
	{
		while (textfield)
		{
			add_return_data(&libui->closed_window_return_data, textfield->textfield.input_text);
			textfield = textfield->next;
		}
	}
	if (libui->active_window->callback_function)
		libui->active_window->callback_function(libui);
	hide_active_window(&libui->active_window, libui->main_window, &libui->windows);
	delete_return_data(&libui->closed_window_return_data);
}


