#include "guimp.h"

void	use_sticker_brush(t_guimp *guimp)
{
	t_color			color;
	t_vec2f_pair	pair;

    if (guimp->libui->mouse.m1_released || guimp->libui->mouse.m2_released)
        return;
    if (guimp->libui->mouse.m1_just_pressed || guimp->libui->mouse.m2_just_pressed)
        push_to_buffer(guimp);
	pair.vec_1 = find_canvas_coordinates(guimp,
										 vec2f((double)guimp->libui->mouse.last_pos.x,
											   (double)guimp->libui->mouse.last_pos.y));
	pair.vec_2 = find_canvas_coordinates(guimp,
										 vec2f((double)guimp->libui->mouse.pos.x,
											   (double)guimp->libui->mouse.pos.y));
	if (guimp->libui->mouse.m1_pressed)
		draw_line_of_stickers(guimp->canvas, pair.vec_1, pair.vec_2, guimp->imported_img);
	else
		put_sticker(guimp->imported_img, guimp->canvas, vec2f_to_vec2(pair.vec_2));
}

