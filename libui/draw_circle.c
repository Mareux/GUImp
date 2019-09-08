#include "libui.h"

typedef struct s_circle_draw
{
	int 		r_squared;
	t_vec2		top;
}				t_circle_draw;

t_circle_draw	new_circle(t_vec2 center, int radius)
{
	t_circle_draw	new;

	new.r_squared = radius * radius;
	return (new);
}

int	fits_equation(t_vec2 point, radius)
{
	int eq;

	eq = point.x * point.x + point.y * point.y - radius * radius;

	if (eq >= 0)
		return (1);
	return (0);
}

void	put_circle_pixels(t_surface *surface, t_circle_draw *circle, t_vec2 center, t_color color)
{
	put_pixel(surface, circle->top.x + center.x, circle->top.y + center.y, color);
	put_pixel(surface, -circle->top.x + center.x, circle->top.y + center.y, color);
	put_pixel(surface, circle->top.x + center.x, -circle->top.y + center.y, color);
	put_pixel(surface, -circle->top.x + center.x, -circle->top.y + center.y, color);
	put_pixel(surface, circle->top.y + center.x, circle->top.x + center.y, color);
	put_pixel(surface, -circle->top.y + center.x, circle->top.x + center.y, color);
	put_pixel(surface, circle->top.y + center.x, -circle->top.x + center.y, color);
	put_pixel(surface, -circle->top.y + center.x, -circle->top.x + center.y, color);
}

void draw_circle(t_surface *surface, t_vec2 center, int	radius, t_color color)
{
	t_circle_draw	circle;

	circle = new_circle(center, radius);
	circle.top = vec2(0, -radius);
	while (circle.top.y <= 0)
	{
		while (!fits_equation(circle.top, radius))
		{
			circle.top.x += 1;
			if (circle.top.x > radius)
				break ;
		}
//		if (-circle.top.y < circle.top.x)
//		{
			put_circle_pixels(surface, &circle, center, color);
//		}
		circle.top.y += 1;
	}
}

void	put_filled_circle_pixels(t_surface *surface, t_circle_draw *circle, t_vec2 center, t_color color)
{
	t_vec2f	pos;

	pos.x = circle->top.x;
	while (pos.x >= 0)
	{
		pos.y = circle->top.y;
		while (pos.y <= 0)
		{
			put_pixel(surface, pos.x + center.x, pos.y + center.y, color);
			put_pixel(surface, pos.y + center.x, pos.x + center.y, color);
			pos.y += 1;
		}
		pos.x -= 1;
	}

	pos.x = -circle->top.x;
	while (pos.x <= 0)
	{
		pos.y = circle->top.y;
		while (pos.y <= 0)
		{
			put_pixel(surface, pos.x + center.x, pos.y + center.y, color);
			put_pixel(surface, pos.y + center.x, pos.x + center.y, color);
			pos.y += 1;
		}
		pos.x += 1;
	}

	pos.x = circle->top.x;
	while (pos.x >= 0)
	{
		pos.y = -circle->top.y;
		while (pos.y >= 0)
		{

			put_pixel(surface, pos.x + center.x, pos.y + center.y, color);
			put_pixel(surface, pos.y + center.x, pos.x + center.y, color);
			pos.y -= 1;
		}
		pos.x -= 1;
	}

	pos.x = -circle->top.x;
	while (pos.x <= 0)
	{
		pos.y = -circle->top.y;
		while (pos.y >= 0)
		{

			put_pixel(surface, pos.x + center.x, pos.y + center.y, color);
			put_pixel(surface, pos.y + center.x, pos.x + center.y, color);
			pos.y -= 1;
		}
		pos.x += 1;
	}
}

void draw_filled_circle(t_surface *surface, t_vec2 center, int radius, t_color color)
{
	t_circle_draw	circle;

	circle = new_circle(center, radius);
	circle.top = vec2(0, -radius);
	while (circle.top.y <= 0)
	{
		while (!fits_equation(circle.top, radius))
		{
			circle.top.x += 1;
			if (circle.top.x > radius)
				break ;
		}
		if (-circle.top.y < circle.top.x)
		{
			put_filled_circle_pixels(surface, &circle, center, color);
		}
		circle.top.y += 1;
	}
}

void draw_disk(t_surface *surface, t_vec2 center, int radius, t_color color)
{
	while (radius >= 1)
	{
		draw_circle(surface, center, radius, color);
		radius -= 1;
	}
	put_pixel(surface, center.x, center.y, color);
}

void draw_rhombus(t_surface *surface, t_vec2 center, int radius, t_color color)
{
	t_circle_draw	circle;

	circle = new_circle(center, radius);
	circle.top = vec2(0, -radius);
	while (circle.top.y <= 0)
	{
		put_pixel(surface, circle.top.x + center.x, circle.top.y + center.y, color);
		put_pixel(surface, -circle.top.x + center.x, circle.top.y + center.y, color);
		put_pixel(surface, circle.top.x + center.x, -circle.top.y + center.y, color);
		put_pixel(surface, -circle.top.x + center.x, -circle.top.y + center.y, color);
		circle.top.y += 1;
		circle.top.x += 1;
	}
}
