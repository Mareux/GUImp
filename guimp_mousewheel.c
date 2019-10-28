#include "guimp.h"

void 	guimp_mwheel_up(t_libui *libui)
{
	t_guimp	*guimp;

	if (libui->active_window != libui->main_window)
		return ;
	guimp = (t_guimp *)libui->data;
	zoom_in(guimp);
}

void 	guimp_mwheel_down(t_libui *libui)
{
	t_guimp	*guimp;

	if (libui->active_window != libui->main_window)
		return ;
	guimp = (t_guimp *)libui->data;
	zoom_out(guimp);
}