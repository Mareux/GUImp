/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guimp_toggle_filled.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:43:05 by ibarabas          #+#    #+#             */
/*   Updated: 2019/10/29 21:43:06 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	toggle_filled(t_libui *libui)
{
	t_guimp	*guimp;

	guimp = (t_guimp *)libui->data;
	if (guimp->shape_data.filled)
		guimp->shape_data.filled = 0;
	else
		guimp->shape_data.filled = 1;
}
