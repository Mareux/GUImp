/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 21:50:06 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/20 18:24:35 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

SDL_Surface *create_text_surface(char *text, t_font *font)
{
	t_surface		*surface;
	SDL_Color		text_color;

	text_color = (SDL_Color){0, 0, 0, 0};
	surface = TTF_RenderUTF8_Blended(font, text, text_color);
	return (surface);
}

void			render_text(t_libui *libui, SDL_Event e, t_widget *widgets)
{
	if (e.type == SDL_TEXTINPUT)
	{
		render_text_in_textfield(widgets->active_textfield,
		libui, e.text.text, text_input_event);
	}
	else if (e.type == SDL_KEYDOWN)
	{
		if (e.key.keysym.sym == SDLK_BACKSPACE)
		{
			render_text_in_textfield(widgets->active_textfield,
			libui, NULL, backspace_event);
		}
		if (e.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL)
		{
			render_text_in_textfield(widgets->active_textfield,
			libui, SDL_GetClipboardText(), text_input_event);
		}
	}
}

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

void    remove_char_from_text_input(t_guimp *guimp)
{

}

void    guimp_backspace(t_libui *libui)
{
    t_guimp *guimp;

    guimp = (t_guimp *)libui->data;
    if (guimp->text_tool.active)
        if (ft_strlen(guimp->text_tool.text) > 0)
            remove_char_from_text_input(guimp);
}

void    guimp_enter(t_libui *libui)
{
    t_guimp *guimp;

    guimp = (t_guimp *)libui->data;
}

void	hook_hooks(t_guimp *guimp)
{
	libui_hook_m1_down(guimp->libui, guimp_mouseclick);
	libui_hook_m2_down(guimp->libui, guimp_mouseclick);
	libui_hook_mwheel_up(guimp->libui, guimp_mwheel_up);
	libui_hook_mwheel_down(guimp->libui, guimp_mwheel_down);
//	bind_key(guimp->libui, "T", toggle_filled);
//	bind_key(guimp->libui, "P", settool_pencil);
//	bind_key(guimp->libui, "B", settool_brush);
//	bind_key(guimp->libui, "F", settool_bucket);
//	bind_key(guimp->libui, "C", settool_circle);
//	bind_key(guimp->libui, "M", settool_magnifying_glass);
//	bind_key(guimp->libui, "H", settool_hand);
//	bind_key(guimp->libui, "E", settool_eraser);
//	bind_key(guimp->libui, "L", settool_line);
//	bind_key(guimp->libui, "R", settool_rect);
//	bind_key(guimp->libui, "K", settool_square);
//	bind_key(guimp->libui, "G", settool_pipette);
//	bind_key(guimp->libui, "N", settool_sticker);
//	bind_key(guimp->libui, "J", settool_text);
//    bind_key(guimp->libui, "Backspace", guimp_backspace);
//    bind_key(guimp->libui, "Return", guimp_enter);
    bind_key(guimp->libui, "Z", LIBUI_CTRL, guimp_undo);
    bind_key(guimp->libui, "Z", LIBUI_SHIFT, guimp_redo);
}

void	guimp_loop(t_libui *libui)
{
	t_guimp	*guimp;

	guimp = (t_guimp *)libui->data;
	guimp->preview = SDL_DuplicateSurface(guimp->canvas); // move to libui
	if (libui->active_window == libui->main_window)
	{
		if (libui->mouse.m1_pressed || libui->mouse.m2_pressed
			|| libui->mouse.m1_released || libui->mouse.m2_released)
			use_tool(guimp);
		if (guimp->libui->mouse.m3_pressed &&
		    guimp->libui->active_window == guimp->libui->main_window)
			guimp_m3(guimp->libui);
		if (guimp->current_tool == TEXT_LINE &&
		    guimp->libui->active_window == guimp->libui->main_window)
			use_text(guimp);
	}
	fill_surface(guimp->libui->main_window->surface, rgb(0, 0, 0));
	draw_canvas(guimp);
	SDL_FreeSurface(guimp->preview); // move to libui
}

int				main(void)
{
	t_guimp	guimp;

	init(&guimp);
	if (!init_libui(&(guimp.libui)))
		ft_putendl_fd("Failed to initialize", 2);
	guimp.imported_img = IMG_Load("../ananasique.png");
	guimp.libui->data = (void *)(&guimp);
	new_window(guimp.libui, vec2(1024, 600), "GUImp");
	new_window(guimp.libui, vec2(128, 400), "Tools");
	create_menu_for_tools(guimp.libui);
	guimp.canvas = create_surface();
	fill_surface(guimp.canvas, rgb(255, 255, 255));
	set_tools_window_position(guimp.libui);
	set_window_resizable(guimp.libui, "GUImp", 1);
	hook_hooks(&guimp);
	guimp.libui->custom_loop = guimp_loop;
	libui_loop(guimp.libui);
	close_sdl(guimp.libui);
	return (0);
}
