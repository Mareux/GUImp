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

void	hook_hooks(t_guimp *guimp)
{
	libui_hook_m1_down(guimp->libui, guimp_mouseclick);
	libui_hook_m2_down(guimp->libui, guimp_mouseclick);
	libui_hook_mwheel_up(guimp->libui, guimp_mwheel_up);
	libui_hook_mwheel_down(guimp->libui, guimp_mwheel_down);
	bind_key(guimp->libui, "T", LIBUI_CTRL, toggle_filled);
	bind_key(guimp->libui, "P", LIBUI_NONE, settool_pencil);
	bind_key(guimp->libui, "B", LIBUI_NONE, settool_brush);
	bind_key(guimp->libui, "F", LIBUI_NONE, settool_bucket);
	bind_key(guimp->libui, "C", LIBUI_NONE, settool_circle);
	bind_key(guimp->libui, "M", LIBUI_NONE, settool_magnifying_glass);
	bind_key(guimp->libui, "H", LIBUI_NONE, settool_hand);
	bind_key(guimp->libui, "E", LIBUI_NONE, settool_eraser);
	bind_key(guimp->libui, "L", LIBUI_NONE, settool_line);
	bind_key(guimp->libui, "R", LIBUI_NONE, settool_rect);
	bind_key(guimp->libui, "R", LIBUI_SHIFT, settool_square);
	bind_key(guimp->libui, "G", LIBUI_NONE, settool_pipette);
	bind_key(guimp->libui, "S", LIBUI_NONE, settool_sticker);
	bind_key(guimp->libui, "T", LIBUI_NONE, settool_text);
	bind_key(guimp->libui, "O", LIBUI_NONE, settool_picture);
	bind_key(guimp->libui, "Z", LIBUI_CTRL, guimp_undo);
	bind_key(guimp->libui, "Z", LIBUI_SHIFT, guimp_redo);
}

void	guimp_loop(t_libui *libui)
{
	t_guimp	*guimp;

	guimp = (t_guimp *)libui->data;
	guimp->preview = duplicate_surface(guimp->canvas);
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
	free_surface(guimp->preview);
}

void	drag_and_drop_image(t_libui *libui)
{
	t_guimp	*guimp;

	guimp = (t_guimp *)libui->data;
	load_dropped_image(libui, &guimp->imported_img);
}

void	init_settings_window(t_guimp *guimp)
{
	t_label		label;
	t_window	*window;

	window = find_t_window(guimp->libui, "Settings");
	label = create_label("This is a settings menu.", vec2(10, 10),
			guimp->libui->font);
	add_label_to_list(&window->widgets->label, label);
	label = create_label("It is scrollable.", vec2(10, 50),
			guimp->libui->font);
	add_label_to_list(&window->widgets->label, label);
	label = create_label("Scroll down to access the settings!",
			vec2(10, 300), guimp->libui->font);
	add_label_to_list(&window->widgets->label, label);
	label = create_label("Scroll some more, you're almost there.",
			vec2(10, 600), guimp->libui->font);
	add_label_to_list(&window->widgets->label, label);
	label = create_label("You expected some settings,",
			vec2(10, 1200), guimp->libui->font);
	add_label_to_list(&window->widgets->label, label);
	label = create_label("But it was me, Dio!",
			vec2(10, 1500), guimp->libui->font);
	add_label_to_list(&window->widgets->label, label);
	window->background_color = rgb(200, 200, 200);
	window->scrollable = 1;
	set_window_position(guimp->libui, "Settings", vec2(1800, 400));
}

int		main(void)
{
	t_guimp	guimp;

	init(&guimp);
	if (!init_libui(&(guimp.libui)))
		ft_putendl_fd("Failed to initialize", 2);
	guimp.imported_img = load_image_as_surface("../ananasique.png");
	guimp.libui->data = (void *)(&guimp);
	new_window(guimp.libui, vec2(1024, 600), "GUImp");
	new_window(guimp.libui, vec2(128, 400), "Tools");
	new_window(guimp.libui, vec2(400, 400), "Settings");
	init_settings_window(&guimp);
	guimp.libui->main_window->drop_func = drag_and_drop_image;
	guimp.libui->default_drop_func = drag_and_drop_image;
	create_menu_for_tools(guimp.libui);
	create_bar(guimp.libui);
	guimp.canvas = create_surface();
	fill_surface(guimp.canvas, rgb(255, 255, 255));
	set_window_position(guimp.libui, "GUImp", vec2(700, 350));
	set_window_position(guimp.libui, "Tools", vec2(500, 400));
	set_window_resizable(guimp.libui, "GUImp", 1);
	hook_hooks(&guimp);
	guimp.libui->custom_loop = guimp_loop;
	libui_loop(guimp.libui);
	system("leaks GUImp");
	return (0);
}
