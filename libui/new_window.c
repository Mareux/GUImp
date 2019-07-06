#include "libui.h"

static t_window		create_window(int weight, int height, const char *title)
{
    t_window window;

    window.window = SDL_CreateWindow(title,
                                     SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                     weight, height, SDL_WINDOW_SHOWN);
    window.id = SDL_GetWindowID(window.window);
    window.surface = SDL_GetWindowSurface(window.window);
    init_widgets(&window.widgets);
    window.active = 1;
    window.type = 1; // Unused, delete this
    return (window);
}

int		new_window(t_libui *libui, t_vec2 size, const char *title)
{
    t_window_list *new;

    if (!(new = malloc((sizeof(t_window_list)))))
        return (0);
    new->window = create_window(size.x, size.y, title);
    if (!new->window.window)
    	return (0);
    new->next = libui->windows;
    libui->windows = new;
    if (!libui->main_window)
		libui->main_window = &new->window;
	if (!libui->active_window)
		libui->active_window = libui->main_window;
    return (1);
}
