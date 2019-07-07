//
// Created by Ilya BARABASH on 2019-07-03.
//

#ifndef LIBUI_H
# define LIBUI_H

# include <SDL.h>
# include <SDL_ttf.h>
# include <SDL_image.h>
# include <math.h>
# include "../libft/libft.h"

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
    t_label_list				*label;
    t_buttons_list				*button;
    t_combobox_list				*combobox;
    t_button					*active_toggle;
    t_combobox					*active_combobox;
    t_image_list				*image;
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

typedef struct                  s_libui
{
    SDL_Event					event;
    t_window					*main_window;
    t_window					*active_window;
    void						*active_window_return_data;
    t_window_list				*windows;
    TTF_Font					*font;
}                               t_libui;

void							main_event_loop(
        t_window *window, t_libui *unicorn);

int					new_window(t_libui *libui, t_vec2 size, const char *title);
void				set_window_resizable(t_libui *libui, const char *title, int resizable);
void				set_window_position(t_libui *libui, const char *title, t_vec2 position);

SDL_Window			*find_window(t_libui *libui, const char *title);

void				libui_loop(t_libui *unicorn);

void				init_widgets(t_widget **widgets);
t_color				rgba(int r, int g, int b, int a);
t_color				rgb(int r, int g, int b);
void				close_sdl(t_libui *data);
void				put_pixel(SDL_Surface *img, int x, int y, t_color color);
void				clear_surface(SDL_Surface *surface);
int					init_libui(t_libui **data);
t_vec2				vec2(int x, int y);
double				vec2len(t_vec2f *vec);

#endif
