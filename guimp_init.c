#include "guimp.h"

void	init_canvas_data(t_guimp *guimp)
{
	guimp->canvas_data.offset = vec2(0, 0);
	guimp->canvas_data.topleft = vec2(0, 0);
	guimp->canvas_data.scale = 1;
}

void 	init_shape_data(t_guimp *guimp)
{
	guimp->shape_data.filled = 0;
	guimp->shape_data.radius = 40;
	guimp->shape_data.size = vec2(40, 40);
	guimp->shape_data.thickness = 3;
	guimp->shape_data.anchor_set = 0;
}

void	init(t_guimp *guimp)
{
	guimp->current_tool = PENCIL;
	guimp->color1 = rgba(255, 0, 0, 0);
	guimp->color2 = rgba(0, 0, 255, 0);
	guimp->libui = NULL;
	init_canvas_data(guimp);
	init_shape_data(guimp);
}