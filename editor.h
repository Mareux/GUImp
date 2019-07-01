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

# include <SDL.h>
# include <SDL_ttf.h>
# include <SDL_image.h>
# include "libft/libft.h"

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


typedef struct		s_vec2
{
	int				x;
	int				y;
}					t_vec2;

typedef struct		s_vec2f
{
	double			x;
	double			y;
}					t_vec2f;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
	int				a;
}					t_color;

typedef struct					s_scrolling_list
{
	SDL_Surface					*field_text;
	void						*data;
	struct s_scrolling_list		*next;
	struct s_scrolling_list		*prew;
}								t_scrolling_list;

typedef struct					s_textfield
{
	int							id;
	SDL_Surface					*text_surface;
	SDL_Rect					rect;
	char						*input_text;
	int							type;
	int							visible;
	t_color						color;
	t_color						active_color;
	int							active;
	void						(*type_check)(char);
}								t_textfield;

typedef struct					s_textfield_list
{
	t_textfield					textfield;
	struct s_textfield_list		*next;
}								t_textfield_list;

typedef struct					s_combobox
{
	int							id;
	SDL_Surface					*field_text;
	t_scrolling_list			*content;
	int							content_size;
	void						*field_data;
	SDL_Rect					field_rect;
	SDL_Rect					menu_rect;
	SDL_Rect					menu_active_field_rect;
	SDL_Surface					*menu_surface;
	int							active;
	void						(*event)(void *);
	t_color						color;
}								t_combobox;

typedef struct					s_combobox_list
{
	t_combobox					combobox;
	struct s_combobox_list		*next;
}								t_combobox_list;

typedef struct					s_label
{
	int							id;
	SDL_Surface					*text_surface;
	char 						*text;
	TTF_Font					*font;
	SDL_Rect					rect;
	int							visible;
}								t_label;

typedef struct 					s_label_list
{
	t_label						label;
	struct s_label_list			*next;
}								t_label_list;

typedef struct					s_button
{
	int							id;
	SDL_Surface					*text_surface;
	SDL_Rect					rect;
	int							visible;
	char						*text;
	int							transparent;
	int							type;
	t_color						color;
	void						(*click)(void *);
}								t_button;

typedef struct					s_buttons_list
{
	t_button					button;
	struct s_buttons_list		*next;
}								t_buttons_list;

typedef	struct					s_image
{
	int							id;
	SDL_Surface					*image;
	SDL_Rect					rect;
	int							visible;
}								t_image;

typedef struct					s_image_list
{
	t_image						image;
	struct s_image_list			*next;
}								t_image_list;

typedef struct					s_widget
{
	t_textfield_list			*textfield;
	t_textfield					*active_textfield;
	t_label						*label;
	t_buttons_list				*button;
	t_combobox_list				*combobox;
	t_button					*active_toggle;
	t_combobox					*active_combobox;
	t_image						*drawbox;
}								t_widget;

typedef struct					s_window
{
	int							id;
	int							active;
	int							type;
	SDL_Window					*window;
	SDL_Surface					*surface;
	t_widget					*widgets;
}								t_window;

typedef struct					s_window_list
{
	t_window					window;
	struct s_window_list		*next;
}								t_window_list;

typedef struct					s_sdl_data
{
	SDL_Event					event;
	t_window					*main_window;
	t_window					*active_window;
	void						*active_window_return_data;
	t_window_list				*windows;
	TTF_Font					*font;
	char						*file;
	SDL_Surface					*bg;
}								t_sdl_data;

double							ft_atof(const char *p);

void							main_event_loop(
		t_window *window, t_sdl_data *data);
int								init_sdl(t_sdl_data *data);
void							draw_rect(
		SDL_Surface *surface, SDL_Rect rect,
		t_color color);
void							draw_filled_rect(
		SDL_Surface *surface, SDL_Rect rect,
		t_color color);
t_textfield						create_textfield(
		SDL_Surface *text_surface, SDL_Rect rect);
t_label create_label(char *text, SDL_Rect rect, TTF_Font *font);
t_button						create_button(
		SDL_Surface *text_surface, SDL_Rect rect, int type,
		char *name);
void							draw_textfield(
		SDL_Surface *surface, t_textfield *textfield);
void							draw_label(
		SDL_Surface *surface, t_label *label);
void							draw_button(
		SDL_Surface *surface, t_button *button);
SDL_Surface						*create_text_surface(
		char *text, TTF_Font *font);
void							text_input_event(
		char **output_text, const char *input_text);
int								digits_check(char c);
void							init_widgets(t_widget **widgets);
void							create_form(
		t_sdl_data *data, t_widget *widgets);
void							draw_form(
		SDL_Surface *surface, t_widget *widgets);
void							backspace_event(
		char **output_text, const char *input_text);
int								point_in_textfield(
		SDL_Point point, t_widget *widgets);
void							render_text_in_textfield(
		t_textfield *textfield, t_sdl_data *data,
		char *text,
		void (event)(char **, const char *));
void							draw_drawbox(
		SDL_Surface *surface, t_image *drawbox);

void							init_sdl_data(t_sdl_data **data);
int								button_clicked(
		SDL_Point point, t_widget *widgets,
		t_sdl_data *data);

void							clear_surface(
		SDL_Surface *surface);
int								textfield_type_check(
		char *text, int(f)(char));
void							add_button_to_list(
		t_buttons_list **buttons,
		t_button button, void (*click)(void *));
void							add_textfield_to_list(
		t_textfield_list **textfield_list,
		t_textfield textfield, void (*type_check)(char));
void							delete_widgets(t_widget **widget);

void							toggle_button_handler(t_sdl_data *data);

void							render_text(t_sdl_data *data, SDL_Event e,
		t_widget *widgets);

void							add_combobox_to_list(
		t_combobox_list **combobox_list,
		t_combobox combobox, void (*event)(void *));
void							combobox_clicked_event(
		t_sdl_data *data);
t_combobox						create_combobox(
		void *data, SDL_Rect field_rect,
		t_color color);

void							draw_combobox(
		SDL_Surface *surface, t_combobox *combobox);
int								combobox_clicked(
		SDL_Point point, t_widget *widgets,
		t_sdl_data *data);

SDL_Surface						*return_coord_surface(
		char *x, char *y, TTF_Font *font);

void							widgets_get_content_size(
		t_scrolling_list *point,
		int *content_size);

void							drawbox_add_text(t_image *drawbox,
		SDL_Surface *text);
void							draw_drawbox_menu(SDL_Surface *menu,
		SDL_Surface *full_menu, SDL_Rect zone);

void							add_window_to_list(
		t_window_list **begin, int weight,
		int height, int type);

void							delete_window(
		t_window_list **window, int id);

void							hide_active_window(
		t_window **active_window,
	t_window *main_window, t_window_list **window);
void							exit_event(SDL_Event *event);
void							show_active_window(
		t_window *active_window, t_sdl_data *data);
char							*get_textfield_data_by_id(
		int id, t_textfield_list *textfield);
void							change_textfield_data_by_id(int id,
	t_textfield_list *textfield, char *text, TTF_Font *font);

t_window						*combobox_form(t_sdl_data *data);
t_window						*one_textfield_form(t_sdl_data *data);
t_window						*two_textfield_form(t_sdl_data *data);

int								check_if_data_null(void *data,
	char *return_text, TTF_Font *font, t_image *drawbox);

void							add_to_scrolling_list(t_scrolling_list **begin,
	SDL_Surface *field_text, void *data);
void							delete_scrolling_list(t_scrolling_list **list);
void							combobox_update(
		t_combobox *combobox, t_scrolling_list *list);
void							active_field_select(
		t_combobox *combobox, SDL_Point mouse_point);
void							*active_field_clicked(SDL_Rect menu_rect,
	SDL_Point mouse_point, t_scrolling_list *list, t_combobox *combobox);
void							scroll(t_scrolling_list **list, int step,
	int *content_size, int menu_content_size);



/*
**  UI
*/

typedef struct					s_line
{
	t_color						color;
	int							direction_x;
	int							i;
	double						dx;
	double						dy;
	double						ydiff;
	double						coeff;
}								t_line;

typedef struct					s_rect
{
	t_vec2f						topleft;
	t_vec2f						bottomright;
}								t_rect;

typedef struct					s_sector_draw_data
{
	t_rect						rect;
	t_vec2f						offset;
	double						scale;
	t_color						color;
	t_sdl_data					*data;
}								t_sector_draw_data;

void							load_bg(t_sdl_data *data);
void							draw_bg(t_sdl_data *data);
void							line(
		SDL_Surface *surface, t_vec2f start, t_vec2f end,
		t_color color);

void							console(t_sdl_data *data, char *text);

void							draw_line(
		SDL_Surface *surface, t_vec2f start, t_vec2f end,
		t_color color);
void							draw_map_and_sector(
		t_sdl_data *data);
void							eventloop_window_events(
		t_sdl_data *data, int *quit);
void							eventloop_keydown(
		t_sdl_data *data, t_window *window, int *quit);
void							eventloop_mousebuttondown_2(
		t_sdl_data *data, SDL_Point point);
void							eventloop_mousebuttondown(
		t_sdl_data *data, SDL_Point point);



t_color			get_pixel(SDL_Surface *img, int x, int y);
void		put_pixel(SDL_Surface *img, int x, int y, t_color color);
void		add_to_pixel(
		SDL_Surface *img, t_vec2 pos, t_color color, double alpha);
t_color	rgba(int r, int g, int b, int a);
t_color	add_colors(t_color *c1, t_color *c2);
void	validate_color(t_color *color);

#endif
