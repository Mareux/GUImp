/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_combobox.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 17:55:51 by ibarabas          #+#    #+#             */
/*   Updated: 2019/06/29 19:36:15 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	combobox_clicked_event(t_sdl_data *data)
{
	if (!data->active_window->widgets->active_combobox->content)
		return ;
	data->active_window->widgets->active_combobox->active =
	data->active_window->widgets->active_combobox->active == TRUE
	? FALSE : TRUE;
	widgets_get_content_size(
			data->active_window->widgets->active_combobox->content,
			&data->active_window->widgets->active_combobox->content_size);
	combobox_update(data->active_window->widgets->active_combobox,
					data->active_window->widgets->active_combobox->content);
}
