/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widgets_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 19:20:12 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/16 10:40:50 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libui.h"

void	draw_textfield(SDL_Surface *surface, t_textfield *textfield)
{
	SDL_Rect rect;

	if (textfield->visible == TRUE)
	{
		rect = textfield->rect;
		if (!textfield->active)
			draw_rect(surface, (t_vec2){rect.x, rect.y},
				(t_vec2){rect.x + rect.w, rect.y + rect.h},
				textfield->color);
		else
			draw_rect(surface, (t_vec2){rect.x, rect.y},
				(t_vec2){rect.x + rect.w, rect.y + rect.h},
				textfield->active_color);
		if (textfield->text_surface)
			SDL_BlitSurface(textfield->text_surface, NULL,
				surface, &textfield->rect);
		textfield->rect = rect;
	}
}

void	draw_label(SDL_Surface *surface, t_label_list *label)
{
	if (label->label.visible)
	{
		label->label.rect.x = label->label.pos.x;
		label->label.rect.y = label->label.pos.y;
		if (label->label.text_surface)
			SDL_BlitSurface(label->label.text_surface, NULL,
			surface, &label->label.rect);
	}
}

void	draw_button(SDL_Surface *surface, t_button *button)
{
	SDL_Rect rect;

	if (button->visible)
	{
		rect = button->rect;
		draw_rect(surface, (t_vec2){button->rect.x, button->rect.y},
		(t_vec2){button->rect.x + button->rect.w,
		button->rect.y + button->rect.h},
		button->color);
		if (!button->transparent)
			draw_filled_rect(surface, (t_vec2){button->rect.x, button->rect.y},
			(t_vec2){button->rect.x + button->rect.w,
			button->rect.y + button->rect.h},
			button->color);
		SDL_BlitSurface(button->text_surface,
				NULL, surface, &button->rect);
		button->rect = rect;
	}
}

void	draw_widgets_2(t_label_list *label,
		t_buttons_list *button, SDL_Surface *surface)
{
	while (button)
	{
		draw_button(surface, &button->button);
		button = button->next;
	}
	while (label)
	{
		draw_label(surface, label);
		label = label->next;
	}
}

void	draw_widgets(t_window_list *list)
{
	t_textfield_list	*textfield;

	while (list)
	{
		if (list->window.widgets)
		{
			textfield = list->window.widgets->textfield;
			while (textfield)
			{
				draw_textfield(list->window.surface, &textfield->textfield);
				textfield = textfield->next;
			}
			draw_widgets_2(list->window.widgets->label,
					list->window.widgets->button, list->window.surface);
		}
		list = list->next;
	}
}
