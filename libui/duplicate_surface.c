/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_surface.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:50:52 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/29 21:50:55 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_surface	*duplicate_surface(t_surface *src)
{
	t_surface	*new;

	new = SDL_DuplicateSurface(src);
	return (new);
}
