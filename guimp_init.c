#include "guimp.h"

void	init_canvas_data(t_guimp *guimp)
{
	guimp->canvas_data.offset = vec2(0, 0);
	guimp->canvas_data.topleft = vec2(0, 0);
	guimp->canvas_data.scale = 1;
}

void	init(t_guimp *guimp)
{
	guimp->current_tool = PENCIL;
	guimp->line_thickness = 1;
	guimp->color1 = rgba(255, 0, 0, 0);
	guimp->color2 = rgba(0, 0, 255, 0);
	guimp->libui = NULL;
	init_canvas_data(guimp);
}