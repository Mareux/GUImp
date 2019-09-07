#include "guimp.h"

void 	guimp_mouseclick(t_libui *libui)
{
	t_guimp	*guimp;

	guimp = (t_guimp *)libui->data;
	if (guimp->current_tool == BUCKET)
		use_bucket(guimp);
	else if (guimp->current_tool == MAGNIFYING_GLASS)
		use_magnifying_glass(guimp);
}