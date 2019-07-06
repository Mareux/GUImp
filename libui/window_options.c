#include "libui.h"

void	set_active_window_resizable(t_libui *libui, int resizable)
{
	if (!libui)
		return ;
	if (!libui->active_window)
		return ;
	if (!libui->active_window->window)
		return ;
	if (resizable)
		SDL_SetWindowResizable(libui->active_window->window, SDL_TRUE);
	else
		SDL_SetWindowResizable(libui->active_window->window, SDL_FALSE);
}