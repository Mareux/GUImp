/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_editing_events.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 21:56:45 by mnosko            #+#    #+#             */
/*   Updated: 2019/06/29 20:09:38 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	text_input_event(char **output_text,
		const char *input_text)
{
	char *tmp;

	if (*output_text == NULL)
	{
		*output_text = malloc(sizeof(char)
				* ft_strlen(input_text) + 1);
		ft_strcpy(*output_text, input_text);
	}
	else
	{
		tmp = ft_strjoin(*output_text, input_text);
		free(*output_text);
		*output_text = tmp;
	}
}

void	backspace_event(char **output_text,
		const char *input_text)
{
	size_t		len;
	char		*tmp;
	char		*kostyl;

	kostyl = (char *)input_text;
	if (*output_text == NULL)
		return ;
	else
	{
		if ((len = ft_strlen(*output_text)) == 0)
			return ;
		tmp = malloc(sizeof(char) * len);
		ft_bzero(tmp, len);
		ft_strncpy(tmp, *output_text, len - 1);
		if (*output_text)
			free(*output_text);
		*output_text = tmp;
	}
}
