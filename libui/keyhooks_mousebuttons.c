#include "libui.h"

void	libui_hook_m1_down(t_libui *libui, void (*func)(t_libui *))
{
	libui->hooks.mouse1_down = (void*)func;
}