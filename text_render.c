/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 21:57:26 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/28 12:00:55 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	endless_textfield(t_textfield *textfield, TTF_Font *font)
{
	t_surface		*tmp;
	int				offset;
	char			*text;

	tmp = create_text_surface(textfield->input_text, font);
	if (!tmp)
	{
		textfield->text_surface = NULL;
		return ;
	}
	offset = tmp->w - textfield->rect.w;
	if (offset <= 0)
	{
		textfield->text_surface = tmp;
	}
	else
	{
		free_surface(tmp);
		offset /= 10 - 1;
		text = textfield->input_text;
		text = (text + offset);
		textfield->text_surface = create_text_surface(text, font);
	}
}

void	render_text_in_textfield(t_textfield *textfield,
		t_libui *libui, char *text,
		void (event)(char **, const char *))
{
	if (!textfield)
		return ;
	event(&textfield->input_text, text);
	if (textfield->text_surface)
		free_surface(textfield->text_surface);
	endless_textfield(textfield, libui->font);
}
