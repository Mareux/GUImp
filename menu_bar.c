/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_bar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:12:02 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/27 23:12:34 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	on_image_save(t_libui *libui)
{
	t_window *window;

	if (!find_window(libui,"Save image"))
	{
		window = create_window_with_textfield(libui, (void *)save_img, "Save image");//refactor
		show_active_window(window);
	}
	else if ((window = find_t_window(libui, "Save image")))
		show_active_window(window);
}

void	load_image(t_libui *libui)
{
	t_guimp		*guimp;
	t_surface	*surface;

	guimp = libui->data;
	surface = load_image_as_surface(libui->closed_window_return_data->data);
	if (surface)
		guimp->imported_img = surface;
}

void	on_load_jpeg(t_libui *libui)
{
	t_window *window;

	if (!find_window(libui, "Load JPEG/PNG"))
	{
		window = create_window_with_textfield(libui, (void*)load_image, "Load JPEG/PNG");
		show_active_window(window);
	}
	else if ((window = find_t_window(libui, "Load JPEG/PNG")))
		show_active_window(window);

}
