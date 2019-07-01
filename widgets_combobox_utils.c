/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widgets_combobox_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 19:17:34 by mnosko            #+#    #+#             */
/*   Updated: 2019/06/29 19:17:34 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	widgets_get_content_size(t_scrolling_list *point,
		int *content_size)
{
	t_scrolling_list *tmp;

	tmp = point;
	*content_size = 0;
	while (tmp)
	{
		(*content_size)++;
		tmp = tmp->next;
	}
}
