/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:15:48 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/15 11:16:02 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../libui.h"

t_hsv_color rgb_to_hsv(t_rgb_color in)
{
	t_hsv_color			out;
	double				min;
	double				max;
	double				delta;

	min = in.r < in.g ? in.r : in.g;
	min = min  < in.b ? min  : in.b;
	max = in.r > in.g ? in.r : in.g;
	max = max  > in.b ? max  : in.b;
	out.v = max;
	delta = max - min;
	if (delta < 0.00001)
	{
		out.s = 0;
		out.h = 0;
		return out;
	}
	if( max > 0.0 )
		out.s = (delta / max);
	else
	{
		out.s = 0.0;
		out.h = NAN;
		return out;
	}
	if (in.r >= max)
		out.h = ( in.g - in.b ) / delta;
	else if( in.g >= max )
		out.h = 2.0 + ( in.b - in.r ) / delta;
	else
		out.h = 4.0 + ( in.r - in.g ) / delta;
	out.h *= 60.0;
	if( out.h < 0.0 )
		out.h += 360.0;
	return out;
}


t_rgb_color return_out(double hh, t_hsv_color in, double t, double ff)
{
	t_rgb_color         out;
	double	q;

	q = in.v * (1.0 - (in.s * ff));
	if((long)hh == 0)
		out = (t_rgb_color){in.v, t, in.v * (1.0 - in.s)};
	if ((long)hh == 1)
		out = (t_rgb_color){q, in.v, in.v * (1.0 - in.s)};
	if ((long)hh == 2)
		out = (t_rgb_color){in.v * (1.0 - in.s), in.v, t};
	if ((long)hh == 3)
		out = (t_rgb_color){in.v * (1.0 - in.s), q, in.v};
	if ((long)hh == 4)
		out = (t_rgb_color){t, in.v * (1.0 - in.s), in.v};
	else if ((long)hh == 5)
		out = (t_rgb_color){in.v, in.v * (1.0 - in.s), q};
	return (out);
}


t_rgb_color hsv_to_rgb(t_hsv_color in)
{
	double	hh;
	double	t;
	double	ff;

	if(in.s <= 0.0)
		return (t_rgb_color){in.v, in.v, in.v};
	hh = in.h;
	if(hh >= 360.0)
		hh = 0.0;
	hh /= 60.0;
	ff = hh - (long)hh;
	t = in.v * (1.0 - (in.s * (1.0 - ff)));
	return (return_out(hh, in, t, ff));
}
