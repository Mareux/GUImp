/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 23:37:53 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/29 23:37:54 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	normalize(t_vec2f *vec)
{
	double	len;

	len = vec2len(vec);
	if (len != 0)
	{
		vec->x /= len;
		vec->y /= len;
	}
}

void	rotate(t_vec2f *vec, double rot)
{
	double	x;
	double	vcos;
	double	vsin;

	vcos = cos(rot);
	vsin = sin(rot);
	x = vec->x;
	vec->x = x * vcos + vec->y * vsin;
	vec->y = vec->y * vcos - x * vsin;
}

t_vec2	vec2(int x, int y)
{
	t_vec2	vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}

t_vec2f	vec2f(double x, double y)
{
	t_vec2f	vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}

double	vec2len(t_vec2f *vec)
{
	return (sqrt(vec->x * vec->x + vec->y * vec->y));
}
