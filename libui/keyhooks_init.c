/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 23:31:06 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/29 23:31:13 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	init_keyhooks(t_libui *libui)
{
	libui->hooks.mouse1_down = NULL;
	libui->hooks.mouse2_down = NULL;
	libui->hooks.mouse3_down = NULL;
	libui->hooks.mwheel_down = NULL;
	libui->hooks.mwheel_up = NULL;
	libui->hooks.keybinds = NULL;
}
