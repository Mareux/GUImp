#include "guimp.h"

static void	use_regular_circle(t_guimp *guimp, t_vec2 int_pos, t_surface *dst, int radius)
{
	if (guimp->libui->mouse.m1_pressed || guimp->libui->mouse.m1_released)
		draw_circle(dst, int_pos,
			radius, guimp->color1);
	else
		draw_circle(dst, int_pos,
				radius, guimp->color2);
}

static void	use_filled_circle(t_guimp *guimp, t_vec2 int_pos, t_surface *dst, int radius)
{
	if (guimp->libui->mouse.m2_pressed || guimp->libui->mouse.m2_released)
	{
		draw_filled_circle(dst, int_pos,
				radius, guimp->color1);
		draw_circle(dst, int_pos,
				radius, guimp->color2);
	}
	else
	{
		draw_filled_circle(dst, int_pos,
				radius, guimp->color2);
		draw_circle(dst, int_pos,
				radius, guimp->color1);
	}
}

/*
**  Returns a point between two given points
*/

t_vec2		find_middle_point(t_vec2 vec1, t_vec2 vec2, double *radius)
{
	t_vec2	middle;
	t_vec2	vector;
	t_vec2f	tmp;

	vector.x = (vec2.x - vec1.x) / 2;
	vector.y = (vec2.y - vec1.y) / 2;
	tmp.x = vector.x;
	tmp.y = vector.y;
	*radius = vec2len(&tmp);
	middle.x = vec1.x + vector.x;
	middle.y = vec1.y + vector.y;
	return (middle);
}

void    put_circle(t_guimp *guimp, t_vec2 int_pos, double radius)
{
    push_to_buffer(guimp);
    if (guimp->shape_data.filled)
        use_regular_circle(guimp, int_pos, guimp->canvas, radius);
    else
        use_filled_circle(guimp, int_pos, guimp->canvas, radius);
    guimp->shape_data.anchor_set = 0;
	copy_surface(guimp->canvas, guimp->preview);
}

void	use_circle(t_guimp *guimp)
{
	t_vec2f			pos;
	t_vec2			int_pos;
	double 			radius;

	set_anchor_point(guimp);
	pos = find_canvas_coordinates(guimp,
			vec2f((double)guimp->libui->mouse.pos.x,
					(double)guimp->libui->mouse.pos.y));
	int_pos.x = (int)pos.x;
	int_pos.y = (int)pos.y;
	int_pos = find_middle_point(guimp->shape_data.anchor, int_pos, &radius);
	if (guimp->libui->mouse.m1_released || guimp->libui->mouse.m2_released)
        put_circle(guimp, int_pos, radius);
	else
	{
		if (guimp->shape_data.filled)
			use_regular_circle(guimp, int_pos, guimp->preview, radius);
		else
			use_filled_circle(guimp, int_pos, guimp->preview, radius);
	}
}

