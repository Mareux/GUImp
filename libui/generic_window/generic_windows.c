/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_windows.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 10:25:32 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/21 15:45:39 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libui.h"

t_window *create_window_with_textfield(t_libui *libui, void (*callback_function)(void*))
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
			CLICK_BUTTON, "OK"), (void*)ok_event);
	add_button_to_list(&curr->widgets->button,
			create_button(create_text_surface("CANCEL", libui->font),
			(SDL_Rect) {130, 135, 100, 30},
			CLICK_BUTTON, "CANCEL"), (void*)cancel_event);
	curr->callback_function = callback_function;
	return (curr);
}

t_window	*create_window_with_label(t_libui *libui, void (*callback_function)(void*))
{
	t_window *curr;

	new_window(libui, (t_vec2){300, 200}, "String_window");
	curr = find_t_window(libui, "String_window");
//	add_label_to_list(&curr->widgets->label,
//						  create_label(create_text_surface(NULL, libui->font));
	add_button_to_list(&curr->widgets->button,
					   create_button(create_text_surface("OK", libui->font),
									 (SDL_Rect) {20, 135, 100, 30},
									 CLICK_BUTTON, "OK"), (void*)ok_event);
	add_button_to_list(&curr->widgets->button,
					   create_button(create_text_surface("CANCEL", libui->font),
									 (SDL_Rect) {130, 135, 100, 30},
									 CLICK_BUTTON, "CANCEL"), (void*)cancel_event);
	curr->callback_function = libui->callback_function;
	libui->callback_function = NULL;
	return (curr);
}
