/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_windows_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 21:52:44 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/21 15:50:10 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libui.h"

void	hide_active_window(t_window **active_window, t_window *main_window)
{
	SDL_HideWindow((*active_window)->window);
	SDL_HideWindow((*active_window)->window);
	*active_window = main_window;
	SDL_RaiseWindow(main_window->window);
}

void	show_active_window(t_window *active_window)
{
	SDL_ShowWindow(active_window->window);
	SDL_RaiseWindow(active_window->window);
}

int		point_in_rect(t_rect rect, int x, int y)
{
	return (
	x > rect.topleft.x && x < rect.bottomright.x &&
	y > rect.topleft.y && y < rect.bottomright.y);
}
