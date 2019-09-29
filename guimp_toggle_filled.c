#include "guimp.h"

void	toggle_filled(t_libui *libui)
{
	t_guimp	*guimp;

	set_cursor(libui->cursor, -1);
	guimp = (t_guimp *)libui->data;
	if (guimp->shape_data.filled)
		guimp->shape_data.filled = 0;
	else
		guimp->shape_data.filled = 1;
}
