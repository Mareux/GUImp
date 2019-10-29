#include "guimp.h"

void	use_magnifying_glass(t_guimp *guimp)
{
	if (guimp->libui->mouse.m1_pressed)
	{
		if (guimp->canvas_data.scale > 10)
			return ;
		guimp->canvas_data.scale *= 1.1;
	}
	else
	{
		if (guimp->canvas_data.scale < 0.1)
			return ;
		guimp->canvas_data.scale /= 1.1;
	}
	check_bounds(guimp);
}

void	zoom_in(t_guimp *guimp)
{
	if (guimp->canvas_data.scale > 10)
		return ;
	guimp->canvas_data.scale *= 1.1;
    check_bounds(guimp);
}

void	zoom_out(t_guimp *guimp)
{
	if (guimp->canvas_data.scale < 0.1)
		return ;
	guimp->canvas_data.scale *= 0.9;
    check_bounds(guimp);
}