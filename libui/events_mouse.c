#include "libui.h"

void			eventloop_mousewheel(t_libui *data)
{
    if (data->event.type == SDL_MOUSEWHEEL
        && (int)data->event.window.windowID == data->active_window->id)
    {
        if (data->event.wheel.y > 0)
        {
            if (data->hooks.mwheel_up)
                data->hooks.mwheel_up(data);
        }
        else
        {
            if (data->hooks.mwheel_down)
                data->hooks.mwheel_down(data);
        }
    }
}