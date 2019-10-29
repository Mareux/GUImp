/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:41:35 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/20 18:39:35 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	set_cursor(t_cursor *cursor, t_libui *libui)
{
	t_guimp *guimp;

	guimp = libui->data;
	set_system_cursor(cursor, libui, guimp->current_tool);
}
