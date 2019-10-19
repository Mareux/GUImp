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

static void	draw_field(SDL_Surface *surface, SDL_Rect field_rect,
		char *field_text, TTF_Font *font, t_color color)
{
	SDL_Surface *text_surface;

	draw_filled_rect(
		surface,
		(t_vec2){field_rect.x, field_rect.y},
		(t_vec2){field_rect.x + field_rect.w, field_rect.y + field_rect.h},
		color);
	if (field_text)
	{
		text_surface = create_text_surface(field_text, font, field_rect);
		SDL_BlitSurface(text_surface, NULL, surface, &field_rect);
		SDL_FreeSurface(text_surface);
	}
}

static void	draw_bar(SDL_Surface *surface, t_menu_field	*field,
		enum e_menu_type type, TTF_Font *font)
{
	int		opened;
	t_menu	*menu;

	opened = FALSE;
	menu = NULL;
	while (field)
	{
		if (field->active)
		{
//			draw_field(surface, field->field_rect, field->field_text,
//					font, field->active_color);
			if (field->menu->opened)
			{
				opened = TRUE;
				menu = field->menu;
			}
		}
		else
		{
//			draw_field(surface, field->field_rect, field->field_text,
//					   font, field->color);
		}
		field = field->next;
	}
	if (opened)
		draw_menu(surface, menu, font);
}

static void	draw_context(SDL_Surface *surface, t_menu_field	*field,
		enum e_menu_type type, TTF_Font *font)
{

}

static void draw_table(SDL_Surface *surface, t_menu_field *field,
		enum e_menu_type  type, TTF_Font *font)
{
	while (field)
	{
//		draw_field(surface, field->field_rect, field->field_text, font, field->color);
		field = field->next;
	}
}

void draw_menu(SDL_Surface *surface, t_menu *menu, TTF_Font *font)
{
	if (menu->type == BAR)
	{
		draw_bar(surface, menu->fields,
				menu->type, font);
	}
	else if (menu->type == CONTEXT)
	{
		draw_context(surface, menu->fields,
				menu->type, font);
	}
	else if (menu->type == TABLE)
	{
		draw_table(surface, menu->fields, menu->type, font);
	}
}