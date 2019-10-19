#include "guimp.h"

/*
**  Makes sure that the image is within view
*/

void    check_bounds(t_guimp *guimp)
{
    t_vec2f scaled_size;

    scaled_size.x = guimp->preview->w * guimp->canvas_data.scale;
    scaled_size.y = guimp->preview->h * guimp->canvas_data.scale;
    scaled_size.x -= guimp->libui->main_window->surface->w;
    scaled_size.y -= guimp->libui->main_window->surface->h;
    if (guimp->canvas_data.offset.x > 0)
        guimp->canvas_data.offset.x = 0;
    if (guimp->canvas_data.offset.y > 0)
        guimp->canvas_data.offset.y = 0;
//    if (guimp->canvas_data.offset.x < -scaled_size.x)
//        guimp->canvas_data.offset.x = -scaled_size.x;
//    if (guimp->canvas_data.offset.y < -scaled_size.y)
//        guimp->canvas_data.offset.y = -scaled_size.y;
}

void	use_hand(t_guimp *guimp)
{
	guimp->canvas_data.offset.x +=
			(double)guimp->libui->mouse.pos.x -
					(double)guimp->libui->mouse.last_pos.x;
	guimp->canvas_data.offset.y +=
			(double)guimp->libui->mouse.pos.y -
			(double)guimp->libui->mouse.last_pos.y;
	check_bounds(guimp);
}

void	guimp_m3(t_libui *libui)
{
	t_guimp	*guimp;

	guimp = (t_guimp *)libui->data;
	use_hand(guimp);
}