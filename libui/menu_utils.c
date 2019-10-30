/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 13:59:54 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/30 13:59:56 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

SDL_Rect	return_rect(int x, int y, int w, int h)
{
	return (SDL_Rect){x, y, w, h};
}

t_surface	*get_window_surface(SDL_Window *window)
{
	return (SDL_GetWindowSurface(window));
}
