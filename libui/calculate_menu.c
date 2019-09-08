/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_menu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:54:45 by mnosko            #+#    #+#             */
/*   Updated: 2019/09/07 16:06:25 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

SDL_Rect	calculate_bar()
{

}

void		recalculate_table_fields(t_menu_field *field, int difference)
{

}

SDL_Rect	calculate_table_field(t_menu_field *begin, SDL_Surface *image,
		SDL_Rect menu_frame)
{
	if (begin->field_rect.h * 2 + begin->field_rect.y
		> menu_frame.h + menu_frame.y)
	{
		recalculate_table_fields(begin,
				(menu_frame.h + menu_frame.y)
				- (begin->field_rect.h * 2 + begin->field_rect.y));
	}
	if (begin->field_rect.w * 2 + begin->field_rect.x
		> menu_frame.w + menu_frame.x)
	{

	}
}

SDL_Rect	calculate_context()
{

}
