#include "guimp.h"

void	use_magnifying_glass(t_guimp *guimp)
{
	if (guimp->libui->mouse.m1_pressed)
		guimp->canvas_data.scale *= 2;
	else
		guimp->canvas_data.scale /= 2;
}

void	zoom_in(t_guimp *guimp)
{
	guimp->canvas_data.scale *= 1.1;
}

void	zoom_out(t_guimp *guimp)
{
	guimp->canvas_data.scale *= 0.9;
}