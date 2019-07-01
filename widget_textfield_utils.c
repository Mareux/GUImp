/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widget_textfield_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 22:01:02 by mnosko            #+#    #+#             */
/*   Updated: 2019/06/29 20:29:31 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

char	*get_textfield_data_by_id(int id,
		t_textfield_list *textfield)
{
	t_textfield_list	*tmp;

	tmp = textfield;
	while (tmp)
	{
		if (tmp->textfield.id == id)
		{
			return (tmp->textfield.input_text);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

void	change_textfield_data_by_id(int id,
		t_textfield_list *textfield, char *text, TTF_Font *font)
{
	SDL_Surface	*text_surface;

	while (textfield)
	{
		if (textfield->textfield.id == id)
		{
			if (textfield->textfield.input_text)
				free(textfield->textfield.input_text);
			textfield->textfield.input_text = ft_strdup(text);
			text_surface = create_text_surface(text, font);
			if (textfield->textfield.text_surface)
				SDL_FreeSurface(textfield->textfield.text_surface);
			textfield->textfield.text_surface = text_surface;
		}
		textfield = textfield->next;
	}
}
