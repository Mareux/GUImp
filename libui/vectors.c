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
