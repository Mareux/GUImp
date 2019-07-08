#include "guimp.h"

void	use_pencil(t_guimp *guimp)
{
	t_color	color;

	if (guimp->libui->mouse.m1_pressed)
		color = guimp->color1;
	else if (guimp->libui->mouse.m2_pressed)
		color = guimp->color2;
	draw_line(guimp->canvas,
			vec2f((double)guimp->libui->mouse.last_pos.x, (double)guimp->libui->mouse.last_pos.y),
			vec2f((double)guimp->libui->mouse.pos.x, (double)guimp->libui->mouse.pos.y),
			color);
}