/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guimp_mousewheel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:20:55 by ibarabas          #+#    #+#             */
/*   Updated: 2019/10/29 21:20:57 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void 	guimp_mwheel_up(t_libui *libui)
{
	t_guimp	*guimp;

	if (libui->active_window != libui->main_window)
		return ;
	guimp = (t_guimp *)libui->data;
	zoom_in(guimp);
}

void 	guimp_mwheel_down(t_libui *libui)
{
	t_guimp	*guimp;

	if (libui->active_window != libui->main_window)
		return ;
	guimp = (t_guimp *)libui->data;
	zoom_out(guimp);
}
