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

void cancel_event(t_libui *libui)
{
	libui->closed_window_return_data = NULL;
	exit_event(&libui->event);
}

void	ok_event(t_libui *libui)
{
	if (libui->active_window
	&& libui->active_window->widgets
	&& libui->active_window->widgets->textfield)
	{
		libui->closed_window_return_data =
				libui->active_window->widgets->textfield->textfield.input_text;
	}
	exit_event(&libui->event);
	if (libui->callback_function)
		libui->callback_function(libui);
	libui->callback_function = NULL;
}


