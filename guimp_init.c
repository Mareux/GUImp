#include "guimp.h"

void	init_key_status(t_guimp *guimp)
{
	guimp->key_status.m1_pressed = 0;
}

void	init(t_guimp *guimp)
{
	guimp->current_tool = PENCIL;
	guimp->line_thickness = 1;
	guimp->color1 = rgba(255, 0, 0, 0);
	guimp->color2 = rgba(0, 0, 255, 0);
	guimp->libui = NULL;
	init_key_status(guimp);
}