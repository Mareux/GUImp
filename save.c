/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 17:42:44 by mnosko            #+#    #+#             */
/*   Updated: 2019/07/09 17:55:58 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"



void save_img(SDL_Surface *canvas, char *filename)
{
	IMG_SaveJPG(canvas, filename, 100);
}
