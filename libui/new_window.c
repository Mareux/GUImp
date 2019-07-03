#include "libui.h"

static t_window		create_window(int weight, int height, int type)
{
    t_window window;

    window.window = SDL_CreateWindow("",
                                     SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                     weight, height, SDL_WINDOW_HIDDEN);
    window.id = SDL_GetWindowID(window.window);
    window.surface = SDL_GetWindowSurface(window.window);
    init_widgets(&window.widgets);
    window.active = FALSE;
    window.type = type;
    return (window);
}

void				new_window(t_window_list **begin, t_vec2 size, int resizable, t_color color)
{
    t_window_list *new;

    if (!(new = malloc((sizeof(t_window_list)))))
        exit(1);
    new->window = create_window(weight, height, type);
    new->next = *begin;
    *begin = new;
}
