/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:40:10 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/29 21:40:12 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libui.h"

void	recalculate_menu(t_menu_list *menu, TTF_Font *font, int w)
{
	while (menu)
	{
		if (menu->menu->type == BAR)
		{
			calculate_bar_fields_position(menu->menu->fields, font);
			menu->menu->menu_frame.w = w;
		}
		menu = menu->next;
	}
}
