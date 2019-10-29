#include "libui.h"

static void draw_q1(t_surface *surface, t_vec2 *top,
		t_vec2 center, t_color color)
{
    t_vec2f	pos;

    pos.x = top->x;
    while (pos.x >= 0)
    {
        pos.y = top->y;
        while (pos.y <= 0)
        {
            put_pixel(surface, pos.x + center.x,
            		pos.y + center.y, color);
            put_pixel(surface, pos.y + center.x,
            		pos.x + center.y, color);
            pos.y += 1;
        }
        pos.x -= 1;
    }
}

static void draw_q2(t_surface *surface, t_vec2 *top,
		t_vec2 center, t_color color)
{
    t_vec2f	pos;

    pos.x = -top->x;
    while (pos.x <= 0)
    {
        pos.y = top->y;
        while (pos.y <= 0)
        {
            put_pixel(surface, pos.x + center.x,
            		pos.y + center.y, color);
            put_pixel(surface, pos.y + center.x,
            		pos.x + center.y, color);
            pos.y += 1;
        }
        pos.x += 1;
    }
}

static void draw_q3(t_surface *surface, t_vec2 *top,
		t_vec2 center, t_color color)
{
    t_vec2f	pos;

    pos.x = top->x;
    while (pos.x >= 0)
    {
        pos.y = -top->y;
        while (pos.y >= 0)
        {

            put_pixel(surface, pos.x + center.x,
            		pos.y + center.y, color);
            put_pixel(surface, pos.y + center.x,
            		pos.x + center.y, color);
            pos.y -= 1;
        }
        pos.x -= 1;
    }
}

void	put_filled_circle_pixels(t_surface *surface,
		t_vec2 *top, t_vec2 center, t_color color)
{
    draw_q1(surface, top, center, color);
    draw_q2(surface, top, center, color);
    draw_q3(surface, top, center, color);
}