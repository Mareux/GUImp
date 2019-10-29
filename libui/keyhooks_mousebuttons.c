/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks_mousebuttons.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 23:31:42 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/29 23:31:44 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	libui_hook_m1_down(t_libui *libui, void (*func)(t_libui *))
{
	libui->hooks.mouse1_down = (void*)func;
}

void	libui_hook_m2_down(t_libui *libui, void (*func)(t_libui *))
{
	libui->hooks.mouse2_down = (void*)func;
}

void	libui_hook_m3_down(t_libui *libui, void (*func)(t_libui *))
{
	libui->hooks.mouse3_down = (void*)func;
}

void	libui_hook_mwheel_down(t_libui *libui, void (*func)(t_libui *))
{
	libui->hooks.mwheel_down = (void*)func;
}

void	libui_hook_mwheel_up(t_libui *libui, void (*func)(t_libui *))
{
	libui->hooks.mwheel_up = (void*)func;
}
