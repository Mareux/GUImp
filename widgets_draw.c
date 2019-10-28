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

#include "guimp.h"

void	draw_textfield(SDL_Surface *surface, t_textfield *textfield)
{
	SDL_Rect rect;

	if (textfield->visible == TRUE)
	{
		rect = textfield->rect;
		SDL_BlitSurface(textfield->text_surface, NULL,
				surface, &textfield->rect);
		if (!textfield->active)
			draw_rect(surface, (t_vec2){rect.x, rect.y},
					(t_vec2){rect.x + rect.w, rect.y + rect.h},
					textfield->color);
		else
			draw_rect(surface, (t_vec2){rect.x, rect.y},
					  (t_vec2){rect.x + rect.w, rect.y + rect.h},
					  textfield->active_color);
		textfield->rect = rect;
	}
}

void	draw_label(SDL_Surface *surface, t_label_list *label)
{
	if (label->label.visible)
	{
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
				  (t_vec2){button->rect.x + button->rect.w, button->rect.y + button->rect.h},
				button->color);
		if (!button->transparent)
			draw_filled_rect(surface,(t_vec2){button->rect.x, button->rect.y},
							 (t_vec2){button->rect.x + button->rect.w, button->rect.y + button->rect.h},
							 button->color);
		SDL_BlitSurface(button->text_surface,
				NULL, surface, &button->rect);
		button->rect = rect;
	}
}

//void	draw_drawbox(SDL_Surface *surface, t_image *drawbox)
//{
//	SDL_Rect rect;
//
//	if (drawbox->visible)
//	{
//		rect = drawbox->rect;
//		if (drawbox->full_drawbox)
//		{
//			draw_drawbox_menu(drawbox->menu,
//					drawbox->full_drawbox, drawbox->active_rect);
//			SDL_BlitSurface(drawbox->menu,
//					NULL, surface, &drawbox->rect);
//		}
//		drawbox->rect = rect;
//		draw_rect(surface, drawbox->rect, (t_color){60, 70, 90, 0xFF});
//	}
//}

void	draw_combobox(SDL_Surface *surface, t_combobox *combobox)
{
	SDL_Rect rect;

	rect = combobox->field_rect;
//	draw_rect(surface, combobox->field_rect, combobox->color);
	if (combobox->field_text)
		SDL_BlitSurface(combobox->field_text,
				NULL, surface, &combobox->field_rect);
	combobox->field_rect = rect;
	if (combobox->active)
	{
		rect = combobox->menu_rect;
		SDL_BlitSurface(combobox->menu_surface,
				&combobox->menu_surface->clip_rect,
				surface, &combobox->menu_rect);
//		draw_rect(surface, combobox->menu_rect,
//				combobox->color);
		combobox->menu_rect = rect;
	}
}

void	draw_widgets(t_window_list *list)
{
	t_textfield_list *textfield;
	t_label_list	*label;
	t_buttons_list *button;

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
			button = list->window.widgets->button;
			while (button)
			{
				draw_button(list->window.surface, &button->button);
				button = button->next;
			}
			label = list->window.widgets->label;
			while (label)
			{
				draw_label(list->window.surface, label);
				label = label->next;
			}
		}
		list = list->next;
	}
}
