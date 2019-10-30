/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_windows_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 21:52:44 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/21 15:50:10 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libui.h"

static void		clear_hidden_window(t_widget *widget)
{
	t_textfield_list	*textfield;
	t_buttons_list		*button;

	textfield = widget->textfield;
	while (textfield)
	{
		if (textfield->textfield.text_surface)
		{
			free_surface(textfield->textfield.text_surface);
			textfield->textfield.text_surface = NULL;
		}
		free(textfield->textfield.input_text);
		textfield->textfield.input_text = ft_strdup("\0");
		textfield->textfield.active = FALSE;
		textfield = textfield->next;
	}
	button = widget->button;
	while (button)
	{
		button->button.color = rgb(60, 70, 90);
		button = button->next;
	}
}

void			hide_active_window(t_window **active_window,
		t_window *main_window)
{
	SDL_HideWindow((*active_window)->window);
	clear_hidden_window((*active_window)->widgets);
	*active_window = main_window;
	SDL_RaiseWindow(main_window->window);
}

void			show_active_window(t_window *active_window)
{
	SDL_ShowWindow(active_window->window);
	SDL_RaiseWindow(active_window->window);
}

int				point_in_rect(t_rect rect, int x, int y)
{
	return (
	x > rect.topleft.x && x < rect.bottomright.x &&
	y > rect.topleft.y && y < rect.bottomright.y);
}
