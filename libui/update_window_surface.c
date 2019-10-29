/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_window_surface.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:45:48 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/28 11:45:48 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	update_window_surface(t_window_list *list)
{
	while (list)
	{
		if (list->window.window)
			SDL_UpdateWindowSurface(list->window.window);
		list = list->next;
	}
}
