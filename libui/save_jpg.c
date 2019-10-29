/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_jpg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 23:34:30 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/29 23:34:32 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	save_jpg(t_surface *surface, const char *file, int quality)
{
	char *tmp;

	tmp = ft_strjoin(file, ".jpeg");
	IMG_SaveJPG(surface, tmp, quality);
	free(tmp);
}
