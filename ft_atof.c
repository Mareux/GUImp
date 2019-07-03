/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 21:47:25 by mnosko            #+#    #+#             */
/*   Updated: 2019/06/29 20:03:39 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void		help_atof(const char **p, double *sign)
{
	while (WHITE_SPACES(**p))
		*p += 1;
	*sign = 1.0;
	if (**p == '-')
	{
		*sign = -1.0;
		*p += 1;
	}
	else if (**p == '+')
		*p += 1;
}

double		ft_atof(const char *p)
{
	double	sign;
	double	value;
	double	pow10;

	help_atof(&p, &sign);
	value = 0.0;
	while (VALID_DIGIT(*p))
	{
		value = value * 10.0 + (*p - '0');
		p += 1;
	}
	if (*p == '.')
	{
		pow10 = 10.0;
		p += 1;
		while (VALID_DIGIT(*p))
		{
			value += (*p - '0') / pow10;
			pow10 *= 10.0;
			p += 1;
		}
	}
	return (sign * value);
}
