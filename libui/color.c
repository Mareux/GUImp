/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 11:44:36 by ibarabas          #+#    #+#             */
/*   Updated: 2019/03/08 11:44:37 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

/*
**	Ensures that all color values
**	are within 0-255 range
*/

void	validate_color(t_color *color)
{
	if (color->r < 0)
		color->r = 0;
	if (color->g < 0)
		color->g = 0;
	if (color->b < 0)
		color->b = 0;
	if (color->r > 255)
		color->r = 255;
	if (color->g > 255)
		color->g = 255;
	if (color->b > 255)
		color->b = 255;
}

/*
**	Creates a t_color structure from r/g/b values,
**	ensuring that all values are in 0-255 range
*/

t_color	rgba(int r, int g, int b, int a)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	validate_color(&color);
	return (color);
}

t_color	rgb(int r, int g, int b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = 0;
	validate_color(&color);
	return (color);
}

int		same_color(t_color c1, t_color c2)
{
	if (c1.r == c2.r &&
		c1.g == c2.g &&
		c1.b == c2.b &&
		c1.a == c2.a)
		return (1);
	return (0);
}
