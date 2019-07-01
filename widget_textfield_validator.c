/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widget_textfield_validator.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 22:01:50 by mnosko            #+#    #+#             */
/*   Updated: 2019/06/29 20:30:11 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int	digits_check(char c)
{
	if (ft_isdigit(c) || c == '.' || c == '-')
		return (TRUE);
	return (FALSE);
}

int	textfield_type_check(char *text, int (f)(char))
{
	if (f == NULL)
		return (TRUE);
	if (text == NULL)
		return (TRUE);
	while (*text)
	{
		if (!f(*text))
			return (FALSE);
		text++;
	}
	return (TRUE);
}
