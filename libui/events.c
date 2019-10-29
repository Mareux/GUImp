/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 17:55:33 by ibarabas          #+#    #+#             */
/*   Updated: 2019/10/28 11:47:50 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void		load_dropped_image(t_libui *unicorn, t_surface **target)
{
	SDL_Surface *img;

	if (img = IMG_Load(unicorn->event.drop.file))
	{
		if (*target)
			SDL_FreeSurface(*target);
		(*target) = img;
	}
}

void		eventloop_drop(t_libui *unicorn)
{
	t_window *window;

	if (unicorn->event.type == SDL_DROPFILE)
	{
		if (unicorn->event.drop.file)
		{
			window = find_window_by_id(unicorn,
									   unicorn->event.window.windowID);
			if (window)
			{
				if (window->drop_func)
					window->drop_func(unicorn);
			} else if (unicorn->default_drop_func)
				unicorn->default_drop_func(unicorn);
			SDL_free(unicorn->event.drop.file);
		}
	}
}

static void	handle_events(t_libui *unicorn, int *quit, SDL_Point *point)
{
	eventloop_window_events(unicorn, quit);
	eventloop_window(unicorn);
	eventloop_keydown(unicorn, quit);
	eventloop_mousebuttondown(unicorn);
	eventloop_mousewheel(unicorn);
	eventloop_drop(unicorn);
	color_change_loop(unicorn);
	menu_events(unicorn, unicorn->menu_list);
}

void		draw_window_backgrounds(t_window_list *list)
{
	while (list)
	{
		fill_surface(list->window.surface, list->window.background_color);
		list = list->next;
	}
}


void		libui_loop(t_libui *unicorn)
{
	int quit;
	SDL_Point point;

	quit = FALSE;
	while (!quit)
	{
		SDL_StartTextInput();
		draw_window_backgrounds(unicorn->windows);
		eventloop_init_mouse(unicorn);
		unicorn->textinput.active = 0;
		while (SDL_PollEvent(&(unicorn->event)))
		{
			handle_events(unicorn, &quit, &point);
			event_loop_text_input(unicorn);
		}
		if (unicorn->custom_loop)
			unicorn->custom_loop(unicorn);
		draw_all_menus(unicorn->menu_list, unicorn->font);
		if (find_window(unicorn, "Color picker"))
			draw_color_picker_window(unicorn);
		draw_widgets(unicorn->windows);
		update_window_surface(unicorn->windows);
		SDL_StopTextInput();
	}
}
