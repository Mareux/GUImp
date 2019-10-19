/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 20:51:06 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/17 20:48:30 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libui.h"

static	void draw_text_field(SDL_Surface *surface, char *text, SDL_Rect field_rect, TTF_Font *font, t_color color)
{
	SDL_Surface *text_surface;

	draw_filled_rect(surface,
					 (t_vec2){field_rect.x, field_rect.y},
					 (t_vec2){field_rect.x + field_rect.w, field_rect.y + field_rect.h},
					 color);
	text_surface = create_text_surface(text, font);
	SDL_BlitSurface(text_surface, NULL, surface, &field_rect);

}

static void draw_image_field(SDL_Surface *surface, SDL_Surface *image, SDL_Rect field_size)
{
	SDL_BlitScaled(image, &image->clip_rect, surface, &field_size);
}

static void draw_color_field(SDL_Surface *surface, void *data, SDL_Rect field_rect)
{
	t_color	color;

	color = *((t_color *)data);
	draw_filled_rect(surface,
					 (t_vec2){field_rect.x, field_rect.y},
					 (t_vec2){field_rect.x + field_rect.w, field_rect.y + field_rect.h},
					 color);
}

void draw_field(SDL_Surface *surface, t_menu_field *field,
					   TTF_Font *font)
{

	if (field->type == FIELD_IMAGE)
	{
		draw_image_field(surface, field->data, field->field_rect);
	}
	else if (field->type == FIELD_TEXT)
	{
		draw_text_field(surface, field->data, field->field_rect, font, field->field_color);
	}
	else if (field->type == FIELD_COLOR_PICKER)
	{
		draw_color_field(surface, field->data, field->field_rect);
	}
	else if (field->type == FIELD_TEXTFIELD)
	{
	}
	else if (field->type == FIELD_COMBOBOX)
	{

	}
}

static void draw_bar(SDL_Surface *surface, t_menu_field *field, TTF_Font *font)
{
	int opened;
	t_menu *menu;

	opened = FALSE;
	menu = NULL;
	while (field)
	{
		if (field->active)
		{
			draw_field(surface, field, font);
			if (field->menu->opened)
			{
				opened = TRUE;
				menu = field->menu;
			}
		} else
		{
			draw_field(surface, field, font);
		}
		field = field->next;
	}
	if (opened)
		draw_menu(surface, menu, font);
}

static void draw_context(SDL_Surface *surface, t_menu_field *field, TTF_Font *font)
{
	while (field)
	{
		draw_field(surface, field, font);
		field = field->next;
	}
}

static void draw_table(SDL_Surface *surface, t_menu_field *field, TTF_Font *font)
{
	while (field)
	{
		draw_field(surface, field, font);
		field = field->next;
	}
}

void draw_menu(SDL_Surface *surface, t_menu *menu, TTF_Font *font)
{
	if (menu->type == BAR)
	{
		draw_bar(surface, menu->fields, font);
	} else if (menu->type == CONTEXT)
	{
		draw_context(surface, menu->fields, font);
	} else if (menu->type == TABLE)
	{
		draw_table(surface, menu->fields, font);
	}
}

void	draw_all_menus(t_menu_list *list, TTF_Font *font)
{
	while (list)
	{
		draw_menu(list->menu.menu_surface, &list->menu, font);
		list = list->next;
	}
}
