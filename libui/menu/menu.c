/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 20:51:06 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/28 11:18:34 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libui.h"

static void		draw_text_field(SDL_Surface *surface,
		t_menu_field *field, TTF_Font *font)
{
	SDL_Surface *text_surface;

	draw_filled_rect(surface,
				(t_vec2){field->field_rect.x, field->field_rect.y},
				(t_vec2){field->field_rect.x + field->field_rect.w,
				field->field_rect.y + field->field_rect.h},
				field->field_color);
	text_surface = create_text_surface(field->data, font);
	SDL_BlitSurface(text_surface, NULL, surface, &field->field_rect);
	SDL_FreeSurface(text_surface);
}

static void		draw_number_field(SDL_Surface *surface,
		int *number, t_menu_field *field,
		TTF_Font *font)
{
	SDL_Surface		*text_surface;
	char			*text;

	draw_filled_rect(surface,
				(t_vec2){field->field_rect.x, field->field_rect.y},
				(t_vec2){field->field_rect.x + field->field_rect.w,
				field->field_rect.y + field->field_rect.h},
				field->field_color);
	text = ft_itoa(*number);
	text_surface = create_text_surface(text, font);
	free(text);
	SDL_BlitSurface(text_surface, NULL, surface, &field->field_rect);
	SDL_FreeSurface(text_surface);
}

static void		draw_color_field(SDL_Surface *surface,
		void *data, SDL_Rect field_rect)
{
	t_color	color;

	color = *((t_color *)data);
	draw_filled_rect(surface,
				(t_vec2){field_rect.x, field_rect.y},
				(t_vec2){field_rect.x + field_rect.w,
	field_rect.y + field_rect.h},
	color);
}

static void		draw_tool_field(SDL_Surface *surface,
		t_table_tools *tool, SDL_Rect field_rect, t_color color)
{
	draw_filled_rect(surface,
				(t_vec2){field_rect.x, field_rect.y},
				(t_vec2){field_rect.x + field_rect.w,
	field_rect.y + field_rect.h},
				color);
	SDL_BlitScaled(tool->image,
			&tool->image->clip_rect,
			surface,
			&field_rect);
}

void			draw_field(SDL_Surface *surface, t_menu_field *field,
		TTF_Font *font)
{
	if (field->type == FIELD_IMAGE)
		draw_image_field(surface, field->data, field->field_rect);
	else if (field->type == FIELD_TEXT)
		draw_text_field(surface, field, font);
	else if (field->type == FIELD_COLOR_PICKER)
		draw_color_field(surface, field->data, field->field_rect);
	else if (field->type == FIELD_TOOL)
		draw_tool_field(surface, field->data,
				field->field_rect, field->field_color);
	else if (field->type == FIELD_NUMBER)
		draw_number_field(surface, (field->data), field, font);
}
