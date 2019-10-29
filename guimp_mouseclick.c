/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guimp_mouseclick.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:20:49 by ibarabas          #+#    #+#             */
/*   Updated: 2019/10/29 21:20:50 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void 	guimp_mouseclick(t_libui *libui)
{
	t_guimp	*guimp;

	guimp = (t_guimp *)libui->data;
	if (libui->active_window != libui->main_window)
		return ;
	if (guimp->current_tool == BUCKET)
		use_bucket(guimp);
	else if (guimp->current_tool == MAGNIFYING_GLASS)
		use_magnifying_glass(guimp);
}
