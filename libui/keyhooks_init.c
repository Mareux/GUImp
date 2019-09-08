#include "libui.h"

void 	init_keyhooks(t_libui *libui)
{
	libui->hooks.mouse1_down = NULL;
	libui->hooks.mouse2_down = NULL;
	libui->hooks.mouse3_down = NULL;
	libui->hooks.mwheel_down = NULL;
	libui->hooks.mwheel_up = NULL;
	libui->hooks.keybinds = NULL;
}