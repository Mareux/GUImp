/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_windows_forms.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 21:51:10 by mnosko            #+#    #+#             */
/*   Updated: 2019/06/25 21:51:10 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

t_window	*two_textfield_form(t_sdl_data *data)
{
	t_window *curr;

	add_window_to_list(&data->windows, 300, 200, TWO_TEXTFIELD_WINDOW);
	curr = &data->windows->window;
	add_textfield_to_list(&curr->widgets->textfield,
			create_textfield(create_text_surface(NULL, data->font),
			(SDL_Rect) {20, 20, 200, 20}), NULL);
	add_textfield_to_list(&curr->widgets->textfield,
			create_textfield(create_text_surface(NULL, data->font),
			(SDL_Rect) {20, 45, 200, 20}), NULL);
	add_button_to_list(&curr->widgets->button,
			create_button(create_text_surface("OK", data->font),
			(SDL_Rect) {135, 135, 100, 30},
			CLICK_BUTTON, "OK"), NULL);
	return (curr);
}

t_window	*combobox_form(t_sdl_data *data)
{
	t_window *curr;

	add_window_to_list(&data->windows, 300, 200, COMBOBOX_WINDOW);
	curr = &data->windows->window;
	create_label(NULL,
				 (SDL_Rect) {50, 0, 0, 0}, NULL);
	add_combobox_to_list(&curr->widgets->combobox,
	create_combobox(NULL, (SDL_Rect) {20, 30, 200, 20},
	(t_color) {0x00, 0xFF, 0x00, 0xFF}), (void*)combobox_clicked_event);
	add_button_to_list(&curr->widgets->button,
	create_button(create_text_surface("Ok", data->font),
	(SDL_Rect) {45, 110, 100, 30},
	CLICK_BUTTON, "OK"), (void*)NULL);
	return (curr);
}

t_window	*one_textfield_form(t_sdl_data *data)
{
	t_window *curr;

	add_window_to_list(&data->windows, 300, 200, TEXTFIELD_WINDOW);
	curr = &data->windows->window;
	create_label(NULL, (SDL_Rect) {10, 10, 0, 0}, NULL);
	add_textfield_to_list(&curr->widgets->textfield,
	create_textfield(NULL,
	(SDL_Rect) {20, 30, 200, 30}), NULL);
	add_button_to_list(&curr->widgets->button,
	create_button(create_text_surface("Ok", data->font),
	(SDL_Rect) {45, 110, 100, 30},
	CLICK_BUTTON, "OK"), NULL);
	return (curr);
}
