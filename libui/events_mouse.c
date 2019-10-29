#include "libui.h"

void	scroll_widgets(t_window *window, t_vec2 scroll)
{
	t_textfield_list *textfield;
	t_label_list	*label;
	t_buttons_list *button;



		if (window->widgets) {
//			textfield = window->widgets->textfield;
//			while (textfield) {
//				textfield->textfield.pos.x += scroll.x;
//				textfield->textfield.pos.y += scroll.y;
//				textfield = textfield->next;
//			}
//			button = window->widgets->button;
//			while (button) {
//				button->button.pos.x += scroll.x;
//				button->button.pos.y += scroll.y;
//				button = button->next;
//			}∑
			label = window->widgets->label;
			while (label) {
				label->label.pos.x += scroll.x;
				label->label.pos.y += scroll.y;
				label = label->next;
			}
		}
}

void			eventloop_mousewheel(t_libui *data)
{
    if (data->event.type == SDL_MOUSEWHEEL
        && (int)data->event.window.windowID == data->active_window->id)
    {
        if (data->event.wheel.y > 0)
        {
            if (data->hooks.mwheel_up)
                data->hooks.mwheel_up(data);
            scroll_widgets(data->active_window, vec2(0, 30));
        }
        else
        {
            if (data->hooks.mwheel_down)
                data->hooks.mwheel_down(data);
			scroll_widgets(data->active_window, vec2(0, -30));
        }
    }
}

static void     mouse_up(t_libui *data)
{
	SDL_Point point;

	point = (SDL_Point){data->mouse.pos.x, data->mouse.pos.y};

    if (data->event.button.button == SDL_BUTTON_LEFT)
    {
        data->mouse.m1_pressed = 0;
        data->mouse.m1_released = 1;
		if (point_in_textfield(point, data->active_window->widgets))
			if (!SDL_IsTextInputActive())
				SDL_StartTextInput();
		if (button_clicked(point, data))
			if (SDL_IsTextInputActive())
				SDL_StopTextInput();
    }
    if (data->event.button.button == SDL_BUTTON_RIGHT)
    {
        data->mouse.m2_pressed = 0;
        data->mouse.m2_released = 1;
    }
    if (data->event.button.button == SDL_BUTTON_MIDDLE)
    {
        data->mouse.m3_pressed = 0;
        data->mouse.m3_released = 1;
    }
}

static void     update_active_window(t_libui *data)
{
    t_window_list    *win;

    win = data->windows;
    while (win)
    {
        if (SDL_GetWindowFlags(win->window.window) == SDL_WINDOW_INPUT_FOCUS)
            data->active_window = &win->window;
        win = win->next;
    }
}

static void left_mouse_button_down(t_libui *data)
{

    if (data->mouse.m1_pressed == 0)
        data->mouse.m1_just_pressed = 1;
    data->mouse.m1_pressed = 1;
    if (data->hooks.mouse1_down)
        data->hooks.mouse1_down(data);
}


void	        eventloop_mousebuttondown(t_libui *data, SDL_Point point)
{
    if (data->event.type == SDL_MOUSEBUTTONDOWN)
    {
    	if (data->event.button.windowID != data->active_window->id)
			return ;
        update_active_window(data);
        if (data->event.button.button == SDL_BUTTON_LEFT)
			left_mouse_button_down(data);
        else if (data->event.button.button == SDL_BUTTON_RIGHT)
        {
            if (data->mouse.m2_pressed == 0)
                data->mouse.m2_just_pressed = 1;
            data->mouse.m2_pressed = 1;
            if (data->hooks.mouse2_down)
                data->hooks.mouse2_down(data);
        }
        else if (data->event.button.button == SDL_BUTTON_MIDDLE)
        {
            data->mouse.m3_pressed = 1;
            if (data->hooks.mouse3_down)
                data->hooks.mouse3_down(data);
        }
    }
    else if (data->event.type == SDL_MOUSEBUTTONUP)
        mouse_up(data);
}