#include "libui.h"

int	fits_equation(t_vec2 point, int radius)
{
	int eq;

	eq = point.x * point.x + point.y * point.y - radius * radius;
	if (eq >= 0)
		return (1);
	return (0);
}

void	put_circle_pixels(t_surface *surface, t_vec2 top,
		t_vec2 center, t_color color)
{
	put_pixel(surface, top.x + center.x, top.y + center.y, color);
	put_pixel(surface, -top.x + center.x, top.y + center.y, color);
	put_pixel(surface, top.x + center.x, -top.y + center.y, color);
	put_pixel(surface, -top.x + center.x, -top.y + center.y, color);
	put_pixel(surface, top.y + center.x, top.x + center.y, color);
	put_pixel(surface, -top.y + center.x, top.x + center.y, color);
	put_pixel(surface, top.y + center.x, -top.x + center.y, color);
	put_pixel(surface, -top.y + center.x, -top.x + center.y, color);
}

void draw_circle(t_surface *surface, t_vec2 center,
		int	radius, t_color color)
{
	t_vec2	top;

	top = vec2(0, -radius);
	while (top.y <= 0)
	{
		while (!fits_equation(top, radius))
		{
			top.x += 1;
			if (top.x > radius)
				break ;
		}
		put_circle_pixels(surface, top, center, color);
		top.y += 1;
	}
}


void draw_filled_circle(t_surface *surface, t_vec2 center,
		int radius, t_color color)
{
	t_vec2	top;

	top = vec2(0, -radius);
	while (top.y <= 0)
	{
		while (!fits_equation(top, radius))
		{
			top.x += 1;
			if (top.x > radius)
				break ;
		}
		if (top.y < top.x)
			put_filled_circle_pixels(surface, &top, center, color);
		top.y += 1;
	}
}
