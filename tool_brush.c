#include "guimp.h"

void	use_brush(t_guimp *guimp)
{
	t_color			color;
	t_vec2f_pair	pair;

	if (guimp->libui->mouse.m1_released || guimp->libui->mouse.m2_released)
		return ;
	pair.vec_1 = find_canvas_coordinates(guimp,
			vec2f((double)guimp->libui->mouse.last_pos.x,
					(double)guimp->libui->mouse.last_pos.y));
	pair.vec_2 = find_canvas_coordinates(guimp,
			vec2f((double)guimp->libui->mouse.pos.x,
					(double)guimp->libui->mouse.pos.y));
	if (guimp->libui->mouse.m1_pressed)
		color = guimp->color1;
	else if (guimp->libui->mouse.m2_pressed)
		color = guimp->color2;
	draw_thick_line(guimp->canvas, pair,
			  color, guimp->shape_data.thickness);
}
