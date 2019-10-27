/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:25:22 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/20 18:15:12 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"
#include <dirent.h>

void	cursor_picture_add(t_cursor_surface **begin,
		t_surface *cursor_image, char *name)
{
	t_cursor_surface *new;

	if (cursor_image == NULL)
		return;
	new = ft_memalloc(sizeof(t_cursor_surface));
	new->id = ft_atoi(name);
	new->cursor_image = cursor_image;
	new->next = *begin;
	*begin = new;
}

t_cursor_surface*	cursor_picture_load(void)
{
	struct dirent *de;
	DIR *dr;
	t_cursor_surface *cursor_surface;

	dr = opendir("GUImp_icons");
	if (dr == NULL)
	{
		ft_putendl_fd("Could not open current directory", 2);
		return (NULL);
	}
	cursor_surface = NULL;
	while ((de = readdir(dr)) != NULL)
	{
		cursor_picture_add(&cursor_surface, IMG_Load(ft_strjoin("GUImp_icons/", de->d_name)), de->d_name);
	}
	closedir(dr);
	return (cursor_surface);
}

void	cursor_add(t_cursor **begin,
		SDL_Cursor *cursor, int id)
{
	t_cursor *new;

	new = ft_memalloc(sizeof(t_cursor_surface));
	new->id = id;
	new->cursor = cursor;
	new->next = *begin;
	*begin = new;
}

void	cursor_create(t_libui *libui)
{
	t_cursor *cursor;
	t_cursor_surface *cursor_surface;

	cursor_surface = cursor_picture_load();
	libui->cursor_surface = cursor_surface;
	cursor = NULL;
	while (cursor_surface)
	{
		cursor_add(&cursor,
				SDL_CreateColorCursor(cursor_surface->cursor_image, 0, 0),
				cursor_surface->id);
		cursor_surface = cursor_surface->next;
	}
	libui->cursor = cursor;
}

