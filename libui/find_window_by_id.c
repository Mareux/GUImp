/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_window_by_id.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 23:23:03 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/29 23:23:06 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_window	*find_window_by_id(t_libui *unicorn, Uint32 id)
{
	t_window_list *konservirovannie_shproti;

	konservirovannie_shproti = unicorn->windows;
	while (konservirovannie_shproti)
	{
		if (konservirovannie_shproti->window.id == id)
			return (&konservirovannie_shproti->window);
		konservirovannie_shproti = konservirovannie_shproti->next;
	}
	return (NULL);
}
