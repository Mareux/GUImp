/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 12:46:42 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/16 10:43:59 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	add_text_field(t_menu_field **begin, SDL_Rect field_rect, char *field_text,
					   void (*click)(void *))
{
	t_menu_field *new;

	new = ft_memalloc(sizeof(t_menu_field));
	new->click = click;
	new->image = NULL;
	new->type = NONE;
	new->data = NULL;
	new->field_text = field_text;
	new->active_color = (t_color){340, 6, 100};
	new->color = (t_color){350, 25, 100};
	new->field_rect = field_rect;
	new->active = TRUE;
	new->next = *begin;
	new->prew = NULL;
	if (*begin != NULL)
		(*begin)->prew = new;
	*begin = new;
}

void	add_image_field(t_menu_field **begin, SDL_Surface *image, char *field_text,
						void (*click)(void *))
{
	t_menu_field *new;

	new = ft_memalloc(sizeof(t_menu_field));
	new->click = click;
	new->image = image;
	new->data = NULL;
	new->type = IMAGE;
	new->field_text = field_text;
	new->active_color = (t_color){340, 6, 100};
	new->color = (t_color){350, 25, 100};
	new->field_rect = image->clip_rect;
	new->active = TRUE;
	new->next = *begin;
	new->prew = NULL;
	if (*begin != NULL)
		(*begin)->prew = new;
	*begin = new;
}

void	add_textfield_field(t_menu_field **begin, t_textfield_list *list, char *field_text,
						void (*click)(void *))
{
	t_menu_field *new;

	new = ft_memalloc(sizeof(t_menu_field));
	new->click = click;
	new->image = SDL_CreateRGBSurface(0, 16, 16, 32, 0, 0, 0, 0);
	new->data = list;
	new->type = TEXTFIELD;
	new->field_text = field_text;
	new->active_color = (t_color){340, 6, 100};
	new->color = (t_color){350, 25, 100};
	new->field_rect = (SDL_Rect){0, 0 , 0, 0};
	new->active = TRUE;
	new->next = *begin;
	new->prew = NULL;
	if (*begin != NULL)
		(*begin)->prew = new;
	*begin = new;
}

void	add_color_field(t_menu_field **begin, char *field_text, t_color color,
							void (*click)(void *))
{
	t_menu_field *new;

	new = ft_memalloc(sizeof(t_menu_field));
	new->click = click;
	new->image = NULL;
	new->data = NULL;
	new->type = COLOR_PICKER;
	new->field_text = field_text;
	new->active_color = (t_color){340, 6, 100};
	new->color = color;
	new->field_rect = (SDL_Rect){0, 300 , 32, 32};
	new->active = TRUE;
	new->next = *begin;
	new->prew = NULL;
	if (*begin != NULL)
		(*begin)->prew = new;
	*begin = new;
}


t_menu	create_menu(enum e_menu_type type, SDL_Rect menu_frame, int id)
{
	t_menu menu;

	menu.id = id;
	menu.type = type;
	menu.fields = NULL;
	menu.opened = FALSE;
	menu.menu_surface = SDL_CreateRGBSurface(0,
			menu_frame.w, menu_frame.h, 32, 0, 0, 0, 0);
	menu.menu_frame = menu_frame;
	return (menu);
}

void	add_menu_to_list(t_menu_list **begin, t_menu menu)
{
	t_menu_list *new;

	new = malloc(sizeof(t_menu_list));
	new->menu = menu;
	new->next = *begin;
	*begin = new;
}
