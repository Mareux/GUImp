/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 17:42:44 by mnosko            #+#    #+#             */
/*   Updated: 2019/07/09 17:55:58 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"


void save_img(t_libui *libui)
{
	t_guimp *guimp;

	guimp = libui->data;
	save_jpg(guimp->canvas,
			libui->closed_window_return_data->data,
			100);
}
