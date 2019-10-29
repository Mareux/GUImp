/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settool_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarabas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:21:57 by ibarabas          #+#    #+#             */
/*   Updated: 2019/10/29 21:21:59 by ibarabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

void	settool_magnifying_glass(t_libui *libui)
{
	settool(libui, MAGNIFYING_GLASS);
}

void	settool_hand(t_libui *libui)
{
	settool(libui, HAND);
}

void	settool_bucket(t_libui *libui)
{
	settool(libui, BUCKET);
}

void	settool_text(t_libui *libui)
{
	settool(libui, TEXT_LINE);
}

void	settool_pipette(t_libui *libui)
{
	settool(libui, PIPETTE);
}
