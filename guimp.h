/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guimp.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <mnosko@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 17:55:25 by ibarabas          #+#    #+#             */
/*   Updated: 2019/10/29 21:20:32 by ibarabas         ###   ########.fr       */
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

# define UNDO_BUFFER_LIMIT 10

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
	MAGNIFYING_GLASS,
	STICKER,
	PICTURE
};

enum 				BUTTONS
{
	MOUSE1,
	MOUSE2
};

typedef struct		s_canvas_data
{
	double 			scale;
	t_vec2			offset;
	t_vec2			topleft;
}					t_canvas_data;

typedef struct		s_shape_data
{
	int				filled;
	int				radius;
	int 			thickness;
	t_vec2			size;
	int				anchor_set;
	t_vec2			anchor;
	TTF_Font		*font;
}					t_shape_data;

typedef struct		s_text_tool
{
	int				active;
	char			*text;
}					t_text_tool;

typedef struct 		s_undo
{
	t_surface		*surface;
	struct s_undo	*next;
}					t_undo;

typedef struct		s_guimp
{
	int 			current_tool;
	t_text_tool		text_tool;
	t_shape_data	shape_data;
	t_color			color1;
	t_color			color2;
	t_libui			*libui;
	t_surface		*canvas;
	t_surface		*preview;
	t_surface		*imported_img;
	t_canvas_data	canvas_data;
	t_undo			*undo_buffer;
	t_undo          *redo_buffer;
}					t_guimp;

void				init(t_guimp *guimp);

void 				guimp_mouseclick(t_libui *libui);
void 				guimp_mwheel_up(t_libui *libui);
void 				guimp_mwheel_down(t_libui *libui);
void				guimp_m3(t_libui *libui);
void				use_tool(t_guimp *guimp);
void				use_hand(t_guimp *guimp);
void				use_magnifying_glass(t_guimp *guimp);
t_vec2f				find_canvas_coordinates(t_guimp *guimp, t_vec2f screen_coordinates);

void 				set_anchor_point(t_guimp *guimp);

void 				settool(t_libui *libui, int tool);

void				settool_pencil(t_libui *libui);
void				use_pencil(t_guimp *guimp);

void				settool_circle(t_libui *libui);
void				use_circle(t_guimp *guimp);

void				settool_brush(t_libui *libui);
void				use_brush(t_guimp *guimp);

void				settool_eraser(t_libui *libui);
void				use_eraser(t_guimp *guimp);

void				settool_line(t_libui *libui);
void				use_line(t_guimp *guimp);

void				settool_rect(t_libui *libui);
void				use_rect(t_guimp *guimp);
void				swap_coordinates(t_vec2_pair *pair);

void				settool_square(t_libui *libui);
void				use_square(t_guimp *guimp);

void				settool_sticker(t_libui *libui);
void				use_sticker_brush(t_guimp *guimp);

void				settool_magnifying_glass(t_libui *libui);

void				zoom_in(t_guimp *guimp);
void				zoom_out(t_guimp *guimp);

void				settool_hand(t_libui *libui);

void				settool_bucket(t_libui *libui);
void				use_bucket(t_guimp *guimp);

void				settool_text(t_libui *libui);
void				toggle_text_input(t_guimp *guimp);
void				use_text(t_guimp *guimp);

void				settool_pipette(t_libui *libui);
void				use_pipette(t_guimp *guimp);

void				settool_picture(t_libui *libui);
void				use_picture(t_guimp *guimp);

void				toggle_filled(t_libui *libui);

void				draw_canvas(t_guimp *guimp);

void save_img(t_libui *libui);

t_undo	            *new_buffer_item(void);
void            	push_to_buffer(t_guimp *guimp);
void	            pull_from_buffer(t_guimp *guimp);
void                backup_buffer(t_guimp *guimp);
void                limit_buffer(t_undo *buffer);

void                guimp_undo(t_libui *libui);
void                guimp_redo(t_libui *libui);

void                check_bounds(t_guimp *guimp);

t_vec2_pair         convert_rect_to_square(t_vec2_pair pair);

void	draw_textfield(SDL_Surface *surface, t_textfield *textfield);

void	draw_label(SDL_Surface *surface, t_label_list *label);
void	draw_button(SDL_Surface *surface, t_button *button);


#endif
