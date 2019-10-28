/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 21:49:23 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/16 09:46:37 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../guimp.h"

void	init_widgets(t_widget **widgets)
{
	*widgets = malloc(sizeof(t_widget));
	(*widgets)->textfield = NULL;
	(*widgets)->label = NULL;
	(*widgets)->button = NULL;
	(*widgets)->image = NULL;
	(*widgets)->combobox = NULL;
}

void 	init_mouse_data(t_libui *libui)
{
	libui->mouse.pos = vec2(0, 0);
	libui->mouse.last_pos = vec2(0, 0);
	libui->mouse.m1_pressed = 0;
	libui->mouse.m2_pressed = 0;
	libui->mouse.m3_pressed = 0;
	libui->mouse.m1_released = 0;
	libui->mouse.m2_released = 0;
	libui->mouse.m3_released = 0;
}

void     init_libui_2(t_libui **data)
{
    *data = malloc(sizeof(t_libui));
    if (!*data)
    {
        ft_putendl("Such error much memory wow");
        exit(1488);
    }
    (*data)->main_window = NULL;
    (*data)->windows = NULL;
    cursor_create((*data));
    (*data)->active_window = NULL;
    (*data)->menu_list = NULL;
    (*data)->closed_window_return_data = NULL;
    (*data)->data = NULL;
    (*data)->widget = NULL;
    (*data)->current_color = (t_hsv_color){180.0, 1.0, 1.0};
    (*data)->custom_loop = NULL;
    (*data)->textinput.active = 1;
    (*data)->textinput.text = NULL;
    (*data)->callback_function = NULL;
}

int		init_libui(t_libui **data)
{
	int success;

	success = 1;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		success = 0;
	if (IMG_Init(IMG_INIT_PNG) < 0)
		success = 0;
	init_libui_2(data);
	if (TTF_Init() < 0)
		exit(124);
	(*data)->font = TTF_OpenFont("../libui/font.ttf", 50); // Полиция!
	if (!(*data)->font)
	{
		ft_putendl_fd("Couldn't load font!", 2);
		exit(123);
	}
	init_keyhooks(*data);
	init_mouse_data(*data);
	return (success);
}

void			close_sdl(t_libui *data)
{
	while (data->windows)
	{
		SDL_DestroyWindow(data->windows->window.window);
		data->windows->window.window = NULL;
		data->windows = data->windows->next;
	}
	SDL_Quit();
}
