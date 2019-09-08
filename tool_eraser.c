#include "guimp.h"

void	use_eraser(t_guimp *guimp)
{
	t_vec2f_pair	pair;
	t_color			color;

	pair.vec_1 = find_canvas_coordinates(guimp,
			vec2f((double)guimp->libui->mouse.last_pos.x,
					(double)guimp->libui->mouse.last_pos.y));
	pair.vec_2 = find_canvas_coordinates(guimp,
			vec2f((double)guimp->libui->mouse.pos.x,
					(double)guimp->libui->mouse.pos.y));
	color = rgba(255, 255, 255, 1);
	draw_thick_line(guimp->canvas, pair,
			color, guimp->shape_data.thickness);
}
