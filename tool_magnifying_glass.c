#include "guimp.h"

void	use_magnifying_glass(t_guimp *guimp)
{
	double change = ((double)guimp->libui->mouse.pos.x -
					(double)guimp->libui->mouse.last_pos.x) / 1000.0;
	guimp->canvas_data.scale += change;
}