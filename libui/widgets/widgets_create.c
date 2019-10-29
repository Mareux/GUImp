/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widgets_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 19:18:59 by mnosko            #+#    #+#             */
/*   Updated: 2019/07/08 14:09:05 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libui.h"

t_textfield		create_textfield(SDL_Surface *text_surface,
		SDL_Rect rect)
{
	t_textfield	textfield;

	textfield.id = 0;
	textfield.text_surface = text_surface;
	textfield.input_text = ft_strdup("\0");
	textfield.rect = rect;
	textfield.type = TEXT;
	textfield.color = (t_color){60, 70, 90, 0xFF};
	textfield.active_color = (t_color){250, 128, 114, 0xFF};
	textfield.visible = TRUE;
	textfield.type_check = NULL;
	textfield.active = FALSE;
	return (textfield);
}

t_label create_label(char *text, t_vec2	pos, t_font *font)
{
	t_label	label;
	SDL_Rect rect;

	label.id = 0;
	rect.x = pos.x;
	rect.y = pos.y;
	label.text_surface = create_text_surface(text, font);
	label.text = text;
	label.font = font;
	label.pos = pos;
	label.rect = rect;
	label.visible = TRUE;
	return (label);
}

t_button		create_button(SDL_Surface *text_surface,
		SDL_Rect rect, int type, char *name)
{
	t_button	button;

	button.id = 0;
	button.text_surface = text_surface;
	button.rect = rect;
	button.color = (t_color) {60, 70, 90, 0xFF};
	button.visible = TRUE;
	button.transparent = FALSE;
	if (type == TOGGLE_BUTTON)
		button.transparent = TRUE;
	button.type = type;
	button.click = NULL;
	button.text = name;
	return (button);
}

