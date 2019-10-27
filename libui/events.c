/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 17:55:33 by ibarabas          #+#    #+#             */
/*   Updated: 2019/10/20 19:15:31 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../guimp.h"

void			eventloop_window(t_libui *unicorn)
{
    t_window    *window;

	if (unicorn->event.type == SDL_WINDOWEVENT)
	{
		if (unicorn->event.window.event == SDL_WINDOWEVENT_RESIZED)
		{
			change_window_surface(unicorn, "GUImp");
		}
        if (unicorn->event.window.event == SDL_WINDOWEVENT_FOCUS_GAINED)
        {
            window = find_window_by_id(unicorn, unicorn->event.window.windowID);
            if (window)
                unicorn->active_window = window;
        }
	}
}

void			eventloop_textinput(t_libui *libui)
{
	libui->textinput.active = 1;
	if (libui->textinput.text)
		free(libui->textinput.text);
	libui->textinput.text = ft_strdup(libui->event.text.text);
}

void            eventloop_init_mouse(t_libui *unicorn)
{
    unicorn->mouse.m1_released = 0;
    unicorn->mouse.m2_released = 0;
    unicorn->mouse.m3_released = 0;
    unicorn->mouse.m1_just_pressed = 0;
    unicorn->mouse.m2_just_pressed = 0;
    unicorn->mouse.last_pos.x = unicorn->mouse.pos.x;
    unicorn->mouse.last_pos.y = unicorn->mouse.pos.y;
    SDL_GetMouseState(&(unicorn->mouse.pos.x), &(unicorn->mouse.pos.y));
    set_cursor(unicorn->cursor, unicorn);
}

void			load_dropped_image(t_libui *unicorn, t_surface **target)
{
	SDL_Surface	*img;

	if (img = IMG_Load(unicorn->event.drop.file))
	{
		if (*target)
			SDL_FreeSurface(*target);
		(*target) = img;
	}
}

void			eventloop_drop(t_libui *unicorn)
{
	t_window    *window;

	if (unicorn->event.type == SDL_DROPFILE)
	{
		if (unicorn->event.drop.file)
		{
			window = find_window_by_id(unicorn, unicorn->event.window.windowID);
			if (window)
			{
				if (window->drop_func)
					window->drop_func(unicorn);
			}
			else if (unicorn->default_drop_func)
				unicorn->default_drop_func(unicorn);
			SDL_free(unicorn->event.drop.file);
		}
	}
}

static void     handle_events(t_libui *unicorn, int *quit, SDL_Point *point)
{
    eventloop_window_events(unicorn, quit);
    eventloop_window(unicorn);
    eventloop_keydown(unicorn, quit);
    eventloop_mousebuttondown(unicorn, *point);
    eventloop_mousewheel(unicorn);
    eventloop_drop(unicorn);
    color_change_loop(unicorn);
    menu_events(unicorn, unicorn->menu_list);
}

void			libui_loop(t_libui *unicorn)
{
	int			quit;
	SDL_Point	point;

	quit = FALSE;
	while (!quit)
	{
		eventloop_init_mouse(unicorn);
		unicorn->textinput.active = 0;
		while (SDL_PollEvent(&(unicorn->event)))
		{
			handle_events(unicorn, &quit, &point);
			if (SDL_IsTextInputActive())
			{
				eventloop_textinput(unicorn);
//				render_text(unicorn, unicorn->event,
//						unicorn->active_window->widgets);
			}
		}
		if (unicorn->custom_loop)
			unicorn->custom_loop(unicorn);
		draw_all_menus(unicorn->menu_list, unicorn->font);
		if (find_window(unicorn, "Color picker"))
			draw_color_picker_window(unicorn);
		SDL_UpdateWindowSurface(find_window(unicorn, "Tools"));
		SDL_UpdateWindowSurface(unicorn->main_window->window);
	}
}
