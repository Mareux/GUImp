#include "guimp.h"

void	toggle_filled(t_libui *libui)
{
	t_guimp	*guimp;

	guimp = (t_guimp *)libui->data;
	if (guimp->shape_data.filled)
		guimp->shape_data.filled = 0;
	else
		guimp->shape_data.filled = 1;
}
