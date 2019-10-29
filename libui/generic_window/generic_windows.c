/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_windows.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 10:25:32 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/28 11:50:44 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libui.h"

t_window	*create_window_with_textfield(t_libui *libui,
		void (*callback_function)(void *), const char *name)
{
	t_window *curr;

	new_window(libui, (t_vec2){300, 200}, name);
	curr = find_t_window(libui, name);
	curr->background_color = (t_color){255, 255, 255};
	add_textfield_to_list(&curr->widgets->textfield,
			create_textfield(create_text_surface(NULL, libui->font),
			(SDL_Rect) {20, 50, 200, 30}), NULL);
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

t_window	*create_font_window(t_libui *libui,
		void (*callback_function)(void *), const char *name)
{
	t_window		*curr;
	t_textfield		textfield;

	new_window(libui, (t_vec2){300, 200}, name);
	curr = find_t_window(libui, name);
	textfield = create_textfield(create_text_surface(
			"Font file:", libui->font), (SDL_Rect){20, 20, 200, 30});
	add_textfield_to_list(&curr->widgets->textfield, textfield, NULL);
	textfield = create_textfield(create_text_surface(
			"Font size:", libui->font), (SDL_Rect){20, 55, 200, 30});
	add_textfield_to_list(&curr->widgets->textfield, textfield, NULL);
	curr->background_color = (t_color){255, 255, 255};
	add_button_to_list(&curr->widgets->button,
	create_button(create_text_surface("OK", libui->font),
	(SDL_Rect) {20, 135, 100, 30}, CLICK_BUTTON, "OK"), (void*)ok_event);
	add_button_to_list(&curr->widgets->button,
	create_button(create_text_surface("CANCEL", libui->font),
	(SDL_Rect) {130, 135, 100, 30}, CLICK_BUTTON, "CANCEL"),
	(void*)cancel_event);
	curr->callback_function = callback_function;
	return (curr);
}
