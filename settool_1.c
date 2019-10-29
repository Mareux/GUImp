/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settool_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:21:47 by ibarabas          #+#    #+#             */
/*   Updated: 2019/10/29 21:21:48 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void settool(t_libui *libui, int tool)
{
	t_guimp	*guimp;

	guimp = (t_guimp *)libui->data;
	if (guimp->text_tool.active)
		return ;
	guimp->shape_data.anchor_set = 0;
	guimp->current_tool = tool;
	if (guimp->current_tool == TEXT_LINE)
	{
		free(guimp->text_tool.text);
		guimp->text_tool.text = ft_strdup("");
	}
}

void	settool_pencil(t_libui *libui)
{
	settool(libui, PENCIL);
}

void settool_brush(t_libui *libui)
{
	settool(libui, BRUSH);
}

void settool_eraser(t_libui *libui)
{
	settool(libui, ERASER);
}

void	settool_picture(t_libui *libui)
{
	settool(libui, PICTURE);
}
