#include "guimp.h"

static void	draw_picture(t_guimp *guimp, t_vec2_pair pair, t_surface *dst)
{
	t_int_rect	src_rect;
	t_int_rect	dst_rect;

	src_rect.topleft.x = 0;
	src_rect.topleft.y = 0;
	src_rect.bottomright.x = guimp->imported_img->w;
	src_rect.bottomright.y = guimp->imported_img->h;
	dst_rect.topleft = guimp->shape_data.anchor;
	dst_rect.bottomright = guimp->libui->mouse.pos;
	blit_scaled(guimp->imported_img, src_rect, dst, dst_rect);
}

void    put_picture(t_guimp *guimp, t_vec2_pair pair)
{
	push_to_buffer(guimp);
	draw_picture(guimp, pair, guimp->canvas);
	copy_surface(guimp->canvas, guimp->preview);
	guimp->shape_data.anchor_set = 0;
}

void	use_picture(t_guimp *guimp)
{
	t_vec2f			tmp;
	t_vec2_pair		pair;

	set_anchor_point(guimp);
	tmp = find_canvas_coordinates(guimp,
			vec2f((double)guimp->libui->mouse.pos.x,
					(double)guimp->libui->mouse.pos.y));
	pair.vec_1 = vec2((int)tmp.x, (int)tmp.y);
	pair.vec_2 = guimp->shape_data.anchor;
	swap_coordinates(&pair);
	if (guimp->libui->mouse.m1_released || guimp->libui->mouse.m2_released)
		put_picture(guimp, pair);
	else
		draw_picture(guimp, pair, guimp->preview);
}



