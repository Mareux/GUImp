/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 17:56:43 by ibarabas          #+#    #+#             */
/*   Updated: 2019/06/29 20:02:59 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

t_label				*find_label(t_label *label, int id)
{
	while (label)
	{
		if (label->id == id)
			return (label);
		label = label->next;
	}
	return (NULL);
}

static void			draw_form_inner_func(SDL_Surface *surface,
		t_widget *widgets)
{
	t_textfield_list	*textfield;
	t_buttons_list		*button;
	t_label				*label;

	label = widgets->label;
	while (label)
	{
		draw_label(surface, label);
		label = label->next;
	}
	button = widgets->button;
	while (button)
	{
		draw_button(surface, &button->button);
		button = button->next;
	}
	textfield = widgets->textfield;
	while (textfield)
	{
		draw_textfield(surface, &textfield->textfield);
		textfield = textfield->next;
	}
}

void				draw_form(SDL_Surface *surface,
		t_widget *widgets)
{
	t_combobox_list		*combobox;
	t_image			*drawbox;

	draw_form_inner_func(surface, widgets);
	combobox = widgets->combobox;
	while (combobox)
	{
		draw_combobox(surface, &combobox->combobox);
		combobox = combobox->next;
	}
	drawbox = widgets->drawbox;
	while (drawbox)
	{
		draw_drawbox(surface, drawbox);
		drawbox = drawbox->next;
	}
}
