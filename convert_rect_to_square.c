#include "guimp.h"

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