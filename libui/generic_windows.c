/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_windows.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 10:25:32 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/06 19:50:51 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_window	*create_window_with_textfield(t_libui *libui)
{
	t_window *curr;

	new_window(libui, (t_vec2){300, 200}, "String_window");
	curr = find_t_window(libui, "String_window");
	add_textfield_to_list(&curr->widgets->textfield,
			create_textfield(create_text_surface(NULL, libui->font),
			(SDL_Rect) {20, 20, 20, 20}), NULL);
	add_button_to_list(&curr->widgets->button,
			create_button(create_text_surface("OK", libui->font),
			(SDL_Rect) {20, 135, 100, 30},
			CLICK_BUTTON, "OK"), NULL);
	add_button_to_list(&curr->widgets->button,
			create_button(create_text_surface("CANCEL", libui->font),
			(SDL_Rect) {130, 135, 100, 30},
			CLICK_BUTTON, "CANCEL"), NULL);
	return (curr);
}

