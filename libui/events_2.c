#include "libui.h"

void			eventloop_window(t_libui *unicorn)
{
	t_window    *window;

	if (unicorn->event.type == SDL_WINDOWEVENT)
	{
		if (unicorn->event.window.event
			== SDL_WINDOWEVENT_RESIZED)
		{
			change_window_surface(unicorn, "GUImp");
			recalculate_menu(unicorn->menu_list, unicorn->font,
							 unicorn->main_window->surface->w);
		}
		if (unicorn->event.window.event
			== SDL_WINDOWEVENT_FOCUS_GAINED)
		{
			window = find_window_by_id(unicorn,
									   unicorn->event.window.windowID);
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

void		event_loop_text_input(t_libui *unicorn)
{
	if (SDL_IsTextInputActive())
	{
		eventloop_textinput(unicorn);
		render_text(unicorn, unicorn->event,
					unicorn->active_window->widgets);
	}
}
