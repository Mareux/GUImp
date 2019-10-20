#include "guimp.h"

static void	use_regular_square(t_guimp *guimp, t_vec2_pair pair, t_surface *dst)
{
	if (guimp->libui->mouse.m1_pressed || guimp->libui->mouse.m1_released)
		draw_rect(dst, pair.vec_1, pair.vec_2, guimp->color1);
	else
		draw_rect(dst, pair.vec_1, pair.vec_2, guimp->color2);
}

static void	use_filled_square(t_guimp *guimp, t_vec2_pair pair, t_surface *dst)
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

/*
*	Calculates what needs to be added to src
*	to make it the same length as dst
*/

static int length_diff(int src, int dst)
{
	int diff;

	diff = ft_abs(dst) - ft_abs(src);
	if (src > 0)
		return (diff);
	return (-diff);
}

t_vec2_pair	convert_rect_to_square(t_vec2_pair pair)
{
	t_vec2	diff;

	diff.x = pair.vec_1.x - pair.vec_2.x;
	diff.y = pair.vec_1.y - pair.vec_2.y;
	if (ft_abs(diff.x) < ft_abs(diff.y))
	{
		pair.vec_1.y += length_diff(diff.y, diff.x);
	}
	else
		{
		pair.vec_1.x += length_diff(diff.x, diff.y);
	}
	return (pair);
}

void	use_square(t_guimp *guimp)
{
	t_vec2f			tmp;
	t_vec2_pair		pair;

	set_anchor_point(guimp);
	tmp = find_canvas_coordinates(guimp,
			vec2f((double)guimp->libui->mouse.pos.x,
					(double)guimp->libui->mouse.pos.y));
	pair.vec_1 = vec2((int)tmp.x, (int)tmp.y);
	pair.vec_2 = guimp->shape_data.anchor;
	pair = convert_rect_to_square(pair);
	swap_coordinates(&pair);
	if (guimp->libui->mouse.m1_released || guimp->libui->mouse.m2_released)
	{
        push_to_buffer(guimp);
		if (guimp->shape_data.filled)
			use_regular_square(guimp, pair, guimp->canvas);
		else
			use_filled_square(guimp, pair, guimp->canvas);
		guimp->shape_data.anchor_set = 0;
	}
	else
	{
		if (guimp->shape_data.filled)
			use_regular_square(guimp, pair, guimp->preview);
		else
			use_filled_square(guimp, pair, guimp->preview);
	}
}



