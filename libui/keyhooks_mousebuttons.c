#include "libui.h"

void	libui_hook_m1_down(t_libui *libui, void (*func)(t_libui *))
{
	libui->hooks.mouse1_down = (void*)func;
}

void	libui_hook_m2_down(t_libui *libui, void (*func)(t_libui *))
{
	libui->hooks.mouse2_down = (void*)func;
}

void	libui_hook_m3_down(t_libui *libui, void (*func)(t_libui *))
{
	libui->hooks.mouse3_down = (void*)func;
}

void	libui_hook_mwheel_down(t_libui *libui, void (*func)(t_libui *))
{
	libui->hooks.mwheel_down = (void*)func;
}

void	libui_hook_mwheel_up(t_libui *libui, void (*func)(t_libui *))
{
	libui->hooks.mwheel_up = (void*)func;
}
