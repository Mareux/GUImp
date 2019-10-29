/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widgets_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 19:19:29 by mnosko            #+#    #+#             */
/*   Updated: 2019/06/29 19:19:29 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libui.h"

void	delete_textfield(t_textfield_list **textfield)
{
	t_textfield_list *tmp;

	tmp = *textfield;
	while (*textfield)
	{
		(*textfield) = (*textfield)->next;
		if (tmp->textfield.text_surface)
			SDL_FreeSurface(tmp->textfield.text_surface);
		if (tmp->textfield.input_text)
			free(tmp->textfield.input_text);
		free(tmp);
		tmp = *(textfield);
	}
}

void	delete_label(t_label_list **label)
{
	t_label_list *tmp;

	tmp = *label;
	while (*label)
	{
		(*label) = (*label)->next;
		if (tmp->label.text_surface)
			SDL_FreeSurface((tmp->label.text_surface));
		free(tmp);
		tmp = *label;
	}
}

void	delete_combobox(t_combobox_list **combobox)
{
	t_combobox_list *tmp;

	tmp = *combobox;
	while (*combobox)
	{
		(*combobox) = (*combobox)->next;
		if (tmp->combobox.menu_surface)
			SDL_FreeSurface(tmp->combobox.menu_surface);
//		delete_scrolling_list(&tmp->combobox.content);
		free(tmp);
		tmp = *combobox;
	}
}

void	delete_button(t_buttons_list **button)
{
	t_buttons_list *tmp;

	while (*button)
	{
		tmp = *button;
		(*button) = (*button)->next;
		if (tmp->button.text_surface)
			SDL_FreeSurface(tmp->button.text_surface);
		free(tmp);
	}
}

void	delete_widgets(t_widget **widget)
{
	if (!*widget)
		return ;
	if ((*widget)->textfield)
		delete_textfield(&(*widget)->textfield);
	if ((*widget)->button)
		delete_button(&(*widget)->button);
	if ((*widget)->label)
		delete_label(&(*widget)->label);
	if ((*widget)->combobox)
		delete_combobox(&(*widget)->combobox);
	free(*widget);
}
