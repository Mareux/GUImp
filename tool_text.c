/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:23:54 by ibarabas          #+#    #+#             */
/*   Updated: 2019/10/29 21:23:55 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	reset_text_input_string(t_guimp *guimp)
{
	free(guimp->text_tool.text);
	guimp->text_tool.text = ft_strdup("");
}

void	toggle_text_input(t_guimp *guimp)
{
	if (guimp->libui->mouse.m1_pressed)
	{
		guimp->text_tool.active = 1;
		set_anchor_point(guimp);
	}
	else if (guimp->libui->mouse.m2_pressed)
	{
		push_to_buffer(guimp);
		use_text(guimp);
		guimp->text_tool.active = 0;
		guimp->shape_data.anchor_set = 0;
		reset_text_input_string(guimp);
	}
}

void	use_text_2(t_guimp *guimp, t_text *text)
{
	if (guimp->libui->mouse.m2_pressed)
		text->surface = guimp->canvas;
	text->position = guimp->shape_data.anchor;
	draw_text(text);
	free(text->text);
}

void	use_text(t_guimp *guimp)
{
	char	*tmp;
	t_text	text;

	if (!guimp->text_tool.active)
		return ;
	if (guimp->libui->textinput.active)
	{
		if (ft_isprint(*guimp->libui->textinput.text))
		{
			tmp = ft_strjoin(guimp->text_tool.text,
					guimp->libui->textinput.text);
			free(guimp->text_tool.text);
			guimp->text_tool.text = tmp;
		}
	}
	init_text(guimp->libui, &text);
	text.color = guimp->color1;
	if (guimp->libui->mouse.m2_pressed)
		text.text = ft_strdup(guimp->text_tool.text);
	else
		text.text = ft_strjoin(guimp->text_tool.text, "|");
	text.surface = guimp->preview;
	use_text_2(guimp, &text);
}
