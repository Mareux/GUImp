//
// Created by Ilya BARABASH on 2019-07-03.
//

#ifndef LIBUI_H
# define LIBUI_H

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

# include <SDL.h>
# include <SDL_ttf.h>
# include <SDL_image.h>
# include <math.h>
# include "../libft/libft.h"

typedef SDL_Surface				t_surface;

typedef struct					s_vec2
{
    int							x;
    int							y;
}								t_vec2;

typedef struct					s_vec2f
{
    double						x;
    double						y;
}								t_vec2f;

typedef struct 					s_vec2_pair
{
	t_vec2						vec_1;
	t_vec2						vec_2;
}								t_vec2_pair;

typedef struct 					s_vec2f_pair
{
	t_vec2f						vec_1;
	t_vec2f						vec_2;
}								t_vec2f_pair;

typedef struct					s_color
{
    int							r;
    int							g;
    int							b;
    int							a;
}								t_color;

typedef struct					s_scrolling_list
{
    SDL_Surface					*field_text;
    void						*data;
    struct s_scrolling_list		*next;
    struct s_scrolling_list		*prew;
}								t_scrolling_list;

enum 					e_menu_type
{
	CONTEXT,
	BAR,
	TABLE,
	NONE
};

typedef struct 					s_menu
{
	int							id;
	enum e_menu_type 			type;
	void						*fields;
	int 						opened;
	SDL_Surface					*menu_surface;
	SDL_Rect					menu_frame;
}								t_menu;

typedef struct 					s_menu_field
{
	int 						id;
	void						(*click)(void *);
	t_menu						*menu;
	t_color						active_color;
	t_color						color;
	SDL_Rect					field_rect;
	SDL_Surface					*image;
	char 						*field_text;
	int 						active;
	struct s_menu_field			*next;
	struct s_menu_field			*prew;
}								t_menu_field;

typedef struct 					s_menu_list
{
	t_menu						menu;
	struct s_menu_list			*next;
}								t_menu_list;

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
    t_menu						*menu;
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
    t_menu						*menu;
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
    t_menu						*menu;
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
    t_menu						*menu;
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
    t_menu						*menu;
}								t_image;

typedef struct					s_image_list
{
    t_image						image;
    struct s_image_list			*next;
}								t_image_list;

typedef struct 					s_textarea
{

}								t_textarea;

typedef struct					s_textarea_list
{
	t_textarea					textarea;
	struct s_textarea_list		*next;
}								t_textarea_list;


typedef struct 					s_checkbox
{

}								t_checkbox;

typedef struct 					s_checkbox_list
{
	t_checkbox					checkbox;
	struct s_checkbox_list		*next;
}								t_checkbox_list;

typedef struct					s_widget
{
    t_textfield_list			*textfield;
    t_label_list				*label;
    t_buttons_list				*button;
    t_combobox_list				*combobox;
    t_image_list				*image;
    t_menu_list					*menu;
    t_textarea_list				*textarea;
    t_checkbox_list				*checkbox;
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

typedef struct					s_keylist
{
	SDL_Scancode				scancode;
	struct s_keylist			*next;
}								t_keylist;

typedef struct					s_keybind
{
	t_keylist					*keys;
	void						(*func)(struct s_libui *);
	struct s_keybind			*next;
}								t_keybind;

typedef struct					s_keyhooks
{
	void 						(*mouse1_down)(struct s_libui *);
	void 						(*mouse2_down)(struct s_libui *);
	void 						(*mouse3_down)(struct s_libui *);
	void 						(*mwheel_down)(struct s_libui *);
	void 						(*mwheel_up)(struct s_libui *);
	t_keybind					*keybinds;
}								t_keyhooks;

typedef struct 					s_mouse_data
{
	t_vec2						pos;
	t_vec2						last_pos;
	int							m1_pressed;
	int							m1_released;
	int							m2_pressed;
	int 						m2_released;
	int 						m3_pressed;
	int 						m3_released;
}								t_mouse_data;

typedef struct		s_line
{
	t_color			color;
	int				direction_x;
	int             i;
	double			dx;
	double			dy;
	double			ydiff;
	double			coeff;
	t_surface		*target_surface;
}					t_line;

typedef struct                  s_libui
{
    SDL_Event					event;
    t_window					*main_window;
    t_window					*active_window;
    void						*active_window_return_data;
    t_window_list				*windows;
    SDL_Cursor					*active_cursor;
    TTF_Font					*font;
    t_keyhooks					hooks;
	void						*data;
	void 						(*custom_loop)(struct s_libui *);
	t_mouse_data				mouse;
}                               t_libui;

void							main_event_loop(
        t_window *window, t_libui *unicorn);

int					new_window(t_libui *libui, t_vec2 size, const char *title);
void				set_window_resizable(t_libui *libui, const char *title, int resizable);
void				set_window_position(t_libui *libui, const char *title, t_vec2 position);
void	change_window_surface(t_libui *libui, const char *title);


SDL_Window			*find_window(t_libui *libui, const char *title);

void				libui_loop(t_libui *unicorn);
void				eventloop_keydown(t_libui *data, int *quit);
void				eventloop_mousebuttondown(t_libui *data, SDL_Point point);

void				libui_hook_m1_down(t_libui *libui, void (*func)(t_libui *));
void				libui_hook_m2_down(t_libui *libui, void (*func)(t_libui *));
void				libui_hook_m3_down(t_libui *libui, void (*func)(t_libui *));
void				libui_hook_mwheel_down(t_libui *libui, void (*func)(t_libui *));
void				libui_hook_mwheel_up(t_libui *libui, void (*func)(t_libui *));

int					init_libui(t_libui **data);
void				init_widgets(t_widget **widgets);
void 				init_keyhooks(t_libui *libui);

t_surface			*create_scaled_surface(SDL_Surface *surface, double scale);
t_vec2				find_scaled_surface_size(t_surface *surface, double scale);


void				close_sdl(t_libui *data);
t_color				get_pixel(SDL_Surface *img, int x, int y);
t_vec2				vec2(int x, int y);
t_vec2f				vec2f(double x, double y);
double				vec2len(t_vec2f *vec);
t_vec2				vec2f_to_vec2(t_vec2f vec);
t_vec2f				vec2_to_vec2f(t_vec2 vec);

/*
** Colors
*/

t_color				rgba(int r, int g, int b, int a);
t_color				rgb(int r, int g, int b);
int					same_color(t_color c1, t_color c2);

/*
**	Key binding
*/

void				bind_key(t_libui *libui, const char *name, void (*func)(t_libui *));
void				bind_key_combination(t_libui *libui, t_keylist *keys, void (*func)(t_libui *));
int					add_key_to_list(t_keylist **lst, char *name);

/*
**	Drawing functions
*/

typedef struct		s_queue
{
	t_vec2			pos;
	t_color			affected_color;
	t_color			target_color;
	struct s_queue	*next;
}					t_queue;

void				put_pixel(SDL_Surface *img, int x, int y, t_color color);
void				fill_surface(SDL_Surface *surface, t_color color);
void 				flood_fill(t_surface *surface, t_vec2 pos,
				   		t_color affected_color, t_color target_color);
void				draw_line(SDL_Surface *surface, t_vec2f start,
					  t_vec2f end, t_color color);
void				draw_thick_line(
						SDL_Surface *surface,
						t_vec2f_pair v,
						t_color color,
						int thickness);
void 				draw_circle(t_surface *surface, t_vec2 center, int	radius, t_color color);
void				draw_filled_circle(t_surface *surface, t_vec2 center, int radius, t_color color);
void				draw_rect(t_surface *surface, t_vec2 topleft,
					t_vec2 bottomright, t_color color);
void				draw_filled_rect(t_surface *surface, t_vec2 topleft,
					t_vec2 bottomright, t_color color);

void 				put_sticker(t_surface *img, t_surface *canvas, t_vec2 pos);
void				draw_line_of_stickers(SDL_Surface *surface, t_vec2f start,
								  t_vec2f end, t_surface *sticker);


void 				change_cursor(SDL_SystemCursor id);


void				add_menu_to_list(t_menu_list **begin, t_menu menu);
t_menu				create_menu(enum e_menu_type type, SDL_Rect menu_frame, int id);
void				add_field(t_menu_field **begin, SDL_Rect field_rect, char *field_text,
				  void (*click)(void *));

void			draw_menu(SDL_Surface *surface, t_menu *menu, TTF_Font *font);
SDL_Surface		*create_text_surface(char *text, TTF_Font *font, SDL_Rect rect);
void			draw_rect(t_surface *surface, t_vec2 topleft,
						  t_vec2 bottomright, t_color color);
void			draw_filled_rect(t_surface *surface, t_vec2 topleft,
								 t_vec2 bottomright, t_color color);


#endif
