#include "guimp.h"

static void	use_regular_rect(t_guimp *guimp, t_vec2_pair pair, t_surface *dst)
{
	if (guimp->libui->mouse.m1_pressed || guimp->libui->mouse.m1_released)
		draw_rect(dst, pair.vec_1, pair.vec_2, guimp->color1);
	else
		draw_rect(dst, pair.vec_1, pair.vec_2, guimp->color2);
}

static void	use_filled_rect(t_guimp *guimp, t_vec2_pair pair, t_surface *dst)
{
	if (guimp->libui->mouse.m2_pressed || guimp->libui->mouse.m2_released)
	{
		draw_filled_rect(dst, pair.vec_1, pair.vec_2, guimp->color1);
		draw_rect(dst, pair.vec_1, pair.vec_2, guimp->color2);
	}
	else
	{
		draw_filled_rect(dst, pair.vec_1, pair.vec_2, guimp->color2);
		draw_rect(dst, pair.vec_1, pair.vec_2, guimp->color1);
	}
}

void	swap_coordinates(t_vec2_pair *pair)
{
	int	tmp;

	if (pair->vec_1.x > pair->vec_2.x)
	{
		tmp = pair->vec_1.x;
		pair->vec_1.x = pair->vec_2.x;
		pair->vec_2.x = tmp;
	}
	if (pair->vec_1.y > pair->vec_2.y)
	{
		tmp = pair->vec_1.y;
		pair->vec_1.y = pair->vec_2.y;
		pair->vec_2.y = tmp;
	}
}

void    put_rect(t_guimp *guimp, t_vec2_pair pair)
{
    push_to_buffer(guimp);
    if (guimp->shape_data.filled)
        use_regular_rect(guimp, pair, guimp->canvas);
    else
        use_filled_rect(guimp, pair, guimp->canvas);
    guimp->shape_data.anchor_set = 0;
	copy_surface(guimp->canvas, guimp->preview);
}

void	use_rect(t_guimp *guimp)
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
	    put_rect(guimp, pair);
	else
	{
		if (guimp->shape_data.filled)
			use_regular_rect(guimp, pair, guimp->preview);
		else
			use_filled_rect(guimp, pair, guimp->preview);
	}
}



