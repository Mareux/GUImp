/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 21:50:06 by mnosko            #+#    #+#             */
/*   Updated: 2019/06/29 20:05:38 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

SDL_Surface		*create_text_surface(char *text, TTF_Font *font)
{
	SDL_Surface		*surface;
	SDL_Color		text_color;

	text_color = (SDL_Color){255, 255, 255, 0};
	surface = TTF_RenderUTF8_Blended(font, text, text_color);
	return (surface);
}

//void			render_text(t_sdl_data *data, SDL_Event e, t_widget *widgets)
//{
//	if (e.type == SDL_TEXTINPUT)
//	{
//		render_text_in_textfield(widgets->active_textfield,
//				data, e.text.text, text_input_event);
//	}
//	else if (e.type == SDL_KEYDOWN)
//	{
//		if (e.key.keysym.sym == SDLK_BACKSPACE)
//		{
//			render_text_in_textfield(widgets->active_textfield,
//					data, NULL, backspace_event);
//		}
//		if (e.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL)
//		{
//			render_text_in_textfield(widgets->active_textfield,
//					data, SDL_GetClipboardText(), text_input_event);
//		}
//	}
//}

void set_tools_window_position(t_libui *libui)
{
	SDL_Window	*main_window;
	SDL_Window	*tools_window;
	t_vec2		main_window_pos;

	main_window = find_window(libui, "GUImp");
	tools_window = find_window(libui, "Tools");
	SDL_GetWindowPosition(main_window,
			&main_window_pos.x, &main_window_pos.y);
	SDL_SetWindowPosition(tools_window,
			main_window_pos.x - 200, main_window_pos.y + 100);
}

int				main(void)
{
	t_libui	*libui;

	if (!init_libui(&libui))
		ft_putendl_fd("Failed to initialize", 2);
	if (!new_window(libui, vec2(1024, 600), "GUImp"))
		ft_putendl_fd("Failed to initialize", 2);
	new_window(libui, vec2(150, 400), "Tools");
	set_tools_window_position(libui);
	set_window_resizable(libui, "GUImp", 1);
	libui_loop(libui);
	close_sdl(libui);
	return (0);
}
