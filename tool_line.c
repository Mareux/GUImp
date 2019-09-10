#include "guimp.h"

t_vec2f	vec2_to_vec2f(t_vec2 vec)
{
	t_vec2f	result;

	result.x = (double)vec.x;
	result.y = (double)vec.y;
	return (result);
}

t_vec2	vec2f_to_vec2(t_vec2f vec)
{
	t_vec2	result;

	result.x = (int)vec.x;
	result.y = (int)vec.y;
	return (result);
}

void 	set_anchor_point(t_guimp *guimp)
{
	t_vec2f	tmp;

	if (!guimp->shape_data.anchor_set)
	{
		tmp = find_canvas_coordinates(
				guimp,
				vec2_to_vec2f(guimp->libui->mouse.pos));
		guimp->shape_data.anchor = vec2f_to_vec2(tmp);
		guimp->shape_data.anchor_set = 1;
	}
}

#include <stdio.h>

void	use_line(t_guimp *guimp) {
	t_vec2f_pair	pair;

	set_anchor_point(guimp);
	pair.vec_1 = find_canvas_coordinates(guimp,
			vec2f((double) guimp->libui->mouse.pos.x,
					(double) guimp->libui->mouse.pos.y));
	pair.vec_2 = vec2_to_vec2f(guimp->shape_data.anchor);
	if (guimp->libui->mouse.m1_released)
	{
		draw_thick_line(guimp->canvas,
				pair, guimp->color1, guimp->shape_data.thickness);
		guimp->shape_data.anchor_set = 0;
	}
	else if (guimp->libui->mouse.m1_pressed)
			draw_thick_line(guimp->preview,
					  pair, guimp->color1, guimp->shape_data.thickness);
	else if (guimp->libui->mouse.m2_released)
	{
		draw_thick_line(guimp->canvas,
						pair, guimp->color2, guimp->shape_data.thickness);
		guimp->shape_data.anchor_set = 0;
	}
	else if (guimp->libui->mouse.m2_pressed)
		draw_thick_line(guimp->preview,
				pair, guimp->color2, guimp->shape_data.thickness);
}
