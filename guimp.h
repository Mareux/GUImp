/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 17:55:25 by ibarabas          #+#    #+#             */
/*   Updated: 2019/06/29 21:10:33 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_NUKEM_EDITOR_H
# define DOOM_NUKEM_EDITOR_H

# include "libui/libui.h"

# define WHITE_SPACES(c) ((c) == ' ' || (c) == '\t')
# define VALID_DIGIT(c) ((c) >= '0' && (c) <= '9')

# define TRUE 1
# define FALSE 0
# define CLICK_BUTTON 0
# define TOGGLE_BUTTON 1
# define WINDOW_W 1920
# define WINDOW_H 1080

# define TWO_TEXTFIELD_WINDOW 0
# define COMBOBOX_WINDOW 1
# define LABEL_WINDOW 2
# define TEXTFIELD_WINDOW 3
# define MAIN_WINDOW 4

# define TEXT 0
# define DIGITS 1

enum				tools
{
	PENCIL,
	BRUSH,
	ERASER,
	LINE,
	RECT,
	FILLED_RECT,
	CIRCLE,
	FILLED_CIRCLE,
	SQUARE,
	FILLED_SQUARE,
	IMAGE_IMPORT,
	BUCKET,
	TEXT_LINE,
	PIPETTE,
	HAND,
	MAGNIFYING_GLASS
};

typedef struct		s_canvas_data
{
	double 			scale;
	t_vec2			offset;
	t_vec2			topleft;
}					t_canvas_data;

typedef struct		s_guimp
{
	int 			current_tool;
	int				line_thickness;
	t_color			color1;
	t_color			color2;
	t_libui			*libui;
	SDL_Surface		*canvas;
	t_canvas_data	canvas_data;
}					t_guimp;

void				init(t_guimp *guimp);

void 				guimp_mouse1_down(t_libui *libui);
void				use_tool(t_guimp *guimp);
void				use_pencil(t_guimp *guimp);
void				use_hand(t_guimp *guimp);
void				use_magnifying_glass(t_guimp *guimp);
t_vec2f				find_canvas_coordinates(t_guimp *guimp, t_vec2f screen_coordinates);

void				draw_canvas(t_guimp *guimp);

void				save_img(SDL_Surface *canvas, char *filename);

#endif
