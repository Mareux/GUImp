#include "guimp.h"

void	use_hand(t_guimp *guimp)
{
	guimp->canvas_data.offset.x +=
			(double)guimp->libui->mouse.pos.x -
					(double)guimp->libui->mouse.last_pos.x;
	guimp->canvas_data.offset.y +=
			(double)guimp->libui->mouse.pos.y -
			(double)guimp->libui->mouse.last_pos.y;
}

void	guimp_m3(t_libui *libui)
{
	t_guimp	*guimp;

	guimp = (t_guimp *)libui->data;
	guimp->canvas_data.offset.x +=
			(double)guimp->libui->mouse.pos.x -
			(double)guimp->libui->mouse.last_pos.x;
	guimp->canvas_data.offset.y +=
			(double)guimp->libui->mouse.pos.y -
			(double)guimp->libui->mouse.last_pos.y;
}