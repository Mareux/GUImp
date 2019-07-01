/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widgets_add_to_lists.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 22:02:05 by mnosko            #+#    #+#             */
/*   Updated: 2019/06/25 22:02:05 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	add_button_to_list(t_buttons_list **buttons,
		t_button button, void (*click)(void *))
{
	t_buttons_list *new;

	if (!(new = malloc(sizeof(t_buttons_list))))
		exit(1);
	new->button = button;
	new->button.click = click;
	new->next = *buttons;
	*buttons = new;
}

void	add_textfield_to_list(t_textfield_list **textfield_list,
		t_textfield textfield, void (*type_check)(char))
{
	t_textfield_list *new;

	if (!(new = malloc(sizeof(t_textfield_list))))
		exit(1);
	new->textfield = textfield;
	if (!*textfield_list)
		new->textfield.id = 0;
	else
		new->textfield.id = (*textfield_list)->textfield.id + 1;
	new->textfield.type_check = type_check;
	new->next = *textfield_list;
	*textfield_list = new;
}

void	add_combobox_to_list(t_combobox_list **combobox_list,
		t_combobox combobox, void (*event)(void *))
{
	t_combobox_list *new;

	if (!(new = malloc(sizeof(t_combobox_list))))
		exit(1);
	new->combobox = combobox;
	if (!*combobox_list)
		new->combobox.id = 0;
	else
		new->combobox.id++;
	new->combobox.event = event;
	new->next = *combobox_list;
	*combobox_list = new;
}
