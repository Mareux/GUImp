/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_bar_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 00:31:25 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/30 00:31:28 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	load_font(t_libui *libui)
{
	t_return_data	*data;
	int				i;
	TTF_Font		*font;

	i = 0;
	data = libui->closed_window_return_data;
	while (data)
	{
		if (i == 0)
		{
			font = TTF_OpenFont(data->next->data, ft_atoi(data->data));
			if (font)
				libui->imported_font = font;
		}
		data = data->next;
		i++;
	}
}
