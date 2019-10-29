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

#define COLOR_PICKER_WINDOW_W 280
#define COLOR_PICKER_WINDOW_H 300
#define MAIN_GRADIENT_SIZE (COLOR_PICKER_WINDOW_W)
#define SAMPLE_BOX_SIZE (COLOR_PICKER_WINDOW_H - COLOR_PICKER_WINDOW_W)
#define HUE_GRADIENT_W (COLOR_PICKER_WINDOW_W - SAMPLE_BOX_SIZE)
#define HUE_GRADIENT_H (SAMPLE_BOX_SIZE)

typedef SDL_Surface				t_surface;
typedef TTF_Font                t_font;

typedef struct s_hsv_color
{
	double h;       // angle in degrees
	double s;       // a fraction between 0 and 1
	double v;       // a fraction between 0 and 1
} t_hsv_color;

enum color_picker_ui_state
{
	UI_GRADIENT_CHANGE,
	UI_SLIDER_CHANGE,
	UI_NONE
};

enum kmods
{
    LIBUI_NONE,
    LIBUI_ALT,
    LIBUI_CTRL,
    LIBUI_SHIFT
};


typedef struct s_rgb_color
{
	double r;       // a fraction between 0 and 1
	double g;       // a fraction between 0 and 1
	double b;       // a fraction between 0 and 1
} t_rgb_color;



typedef struct 		s_cursor_surface
{
	int				id;
	SDL_Surface		*cursor_image;
	struct s_cursor_surface *next;
}					t_cursor_surface;

typedef struct 		s_cursor
{
	int				id;
	SDL_Cursor		*cursor;
	struct s_cursor	*next;
}					t_cursor;

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

typedef struct                  s_int_rect
{
    t_vec2                      topleft;
    t_vec2                      bottomright;
}                               t_int_rect;

typedef struct                  s_rect
{
    t_vec2f                      topleft;
    t_vec2f                      bottomright;
}                               t_rect;

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

typedef struct	s_return_data
{
	void					*data;
	struct s_return_data	*next;
}				t_return_data;

enum 					e_menu_type
{
	CONTEXT,
	BAR,
	TABLE
};

typedef struct 					s_menu
{
	int							id;
	enum e_menu_type 			type;
	void						*fields;
	int 						opened;
	t_color						menu_color;
	t_color						active_field_color;
	SDL_Window					*menu_window;
	int							spacing_w;
	int							spacing_h;
	SDL_Rect					menu_frame;
}								t_menu;

enum e_field_data_type
{
	FIELD_NONE,
	FIELD_IMAGE,
	FIELD_TEXT,
	FIELD_TEXTFIELD,
	FIELD_COMBOBOX,
	FIELD_COLOR_PICKER,
	FIELD_TOOL,
	FIELD_NUMBER
};

#define ELEMENTS_IN_TABLE 3

typedef struct 					s_table_tools
{
	SDL_Surface					*image;
	int 						tool;
}								t_table_tools;

typedef struct 					s_menu_field
{
	int 						id;
	void						(*click)(void *);
	void						*data;
	enum e_field_data_type		type;
	t_menu						*menu;
	SDL_Rect					field_rect;
	int 						active;
	t_color						field_color;
	struct s_menu_field			*next;
}								t_menu_field;

typedef struct 					s_menu_list
{
	t_menu						*menu;
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

typedef struct					s_label
{
    int							id;
    SDL_Surface					*text_surface;
    char 						*text;
    TTF_Font					*font;
	t_vec2						pos;
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


typedef struct					s_widget
{
    t_textfield_list			*textfield;
	t_textfield					*active_textfield;
	t_label_list				*label;
    t_buttons_list				*button;
    t_menu_list					*menu;
}								t_widget;

enum e_window_type
{
	GENERIC_WINDOW,
	IMPORTANT_WINDOW,
};

typedef struct					s_window
{
    int							id;
    int							active;
    int							type;
    int							scrollable;
    t_vec2						scroll_offset;
    t_color						background_color;
    SDL_Window					*window;
    SDL_Surface					*surface;
    t_widget					*widgets;
    void						(*drop_func)(struct s_libui *);
	void						(*callback_function)(void*);

}								t_window;

typedef struct					s_window_list
{
    t_window					window;
    struct s_window_list		*next;
}								t_window_list;

typedef struct					s_keylist
{
	SDL_Scancode				scancode;
	int                         keymod;
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
	int                         m1_just_pressed;
	int							m2_pressed;
	int 						m2_released;
	int                         m2_just_pressed;
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

typedef struct					s_textinput
{
	int							active;
	char 						*text;
}								t_textinput;

typedef struct 					s_text
{
	TTF_Font					*font;
	t_surface					*surface;
	t_vec2						position;
	char						*text;
	t_color						color;
}								t_text;

typedef struct                  s_libui
{
    SDL_Event					event;
    t_window					*main_window;
    t_window					*active_window;
    t_return_data				*closed_window_return_data;
	void						(*callback_function)(void*);
	t_menu_list					*menu_list;
    t_window_list				*windows;
    TTF_Font					*font;
    TTF_Font					*imported_font;;
    t_keyhooks					hooks;
    t_cursor_surface			*cursor_surface;
    t_cursor					*cursor;
	void						*data;
	void 						(*custom_loop)(struct s_libui *);
	void						(*generic_window_loop)(struct s_libui *);
	t_mouse_data				mouse;
	t_textinput					textinput;
	t_hsv_color					current_color;
	void						(*default_drop_func)(struct s_libui *);
}                               t_libui;

void							main_event_loop(
        t_window *window, t_libui *unicorn);

int					new_window(t_libui *libui, t_vec2 size, const char *title);
void				set_window_resizable(t_libui *libui, const char *title, int resizable);
void				change_window_surface(t_libui *libui, const char *title);

SDL_Window			*find_window(t_libui *libui, const char *title);
t_window			*find_t_window(t_libui *libui, const char *title);
t_window            *find_window_by_id(t_libui *unicorn, Uint32 id);

void				add_button_to_list(t_buttons_list **buttons,
						   t_button button, void (*click)(void *));
void				add_label_to_list(t_label_list **list, t_label label);
void				add_textfield_to_list(t_textfield_list **textfield_list,
							  t_textfield textfield, void (*type_check)(char));
t_textfield			create_textfield(SDL_Surface *text_surface,
									SDL_Rect rect);
t_label				create_label(char *text, t_vec2 pos, t_font *font);
t_button			create_button(SDL_Surface *text_surface,
							  SDL_Rect rect, int type, char *name);

void				libui_loop(t_libui *unicorn);
void				eventloop_keydown(t_libui *data, int *quit);
void eventloop_mousebuttondown(t_libui *data);
void				eventloop_window_events(t_libui *data, int *quit);

void				libui_hook_m1_down(t_libui *libui, void (*func)(t_libui *));
void				libui_hook_m2_down(t_libui *libui, void (*func)(t_libui *));
void				libui_hook_m3_down(t_libui *libui, void (*func)(t_libui *));
void				libui_hook_mwheel_down(t_libui *libui, void (*func)(t_libui *));
void				libui_hook_mwheel_up(t_libui *libui, void (*func)(t_libui *));

int					init_libui(t_libui **data);
void				init_widgets(t_widget **widgets);
void 				init_keyhooks(t_libui *libui);

t_surface           *create_scaled_area(t_surface *surface, double scale, t_vec2 topleft, t_vec2 bottomright);
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

void				bind_key(t_libui *libui, const char *name, int kmod, void (*func)(t_libui *));
int                 add_key_to_list(t_keylist **lst, char *name, int kmod);

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

/*
**	Managing surfaces
*/

t_surface			*duplicate_surface(t_surface *src);
t_surface			*free_surface(t_surface *surface);

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

void				init_text(t_libui *libui, t_text *text);
void				draw_text(t_text *text);


void				add_menu_to_list(t_menu_list **begin, t_menu *menu);
t_menu * create_menu(enum e_menu_type type, SDL_Rect menu_frame, int id, SDL_Window *menu_window);
void add_field(t_menu_field **begin, void (*click)(void *), void *data, enum e_field_data_type type);
void	calculate_table_fields_position(SDL_Surface *surface, t_menu *menu, t_menu_field *field);
void	calculate_context_fields_position(t_menu_field *field, TTF_Font *font, SDL_Rect menu_rect);
void	calculate_bar_fields_position(t_menu_field *field, TTF_Font *font);
void menu_events(t_libui *libui, t_menu_list *list);
void			draw_menu(SDL_Surface *surface, t_menu *menu, TTF_Font *font);
void	draw_all_menus(t_menu_list *list, TTF_Font *font);

SDL_Surface *create_text_surface(char *text, TTF_Font *font);
void			draw_rect(t_surface *surface, t_vec2 topleft,
						  t_vec2 bottomright, t_color color);
void			draw_filled_rect(t_surface *surface, t_vec2 topleft,
								 t_vec2 bottomright, t_color color);

void	cursor_create(t_libui *libui);
void set_cursor(t_cursor *cursor, t_libui *libui);

void create_menu_for_tools(t_libui *libui);
void create_bar(t_libui *libui);


t_window *create_window_with_textfield(t_libui *libui, void (*callback_function)(void *), const char *name);

t_window *create_font_window(t_libui *libui, void (*callback_function)(void *), const char *name);

t_rgb_color hsv_to_rgb(t_hsv_color in);

void set_pixel(SDL_Surface *surface, SDL_Color color, int x, int y);

SDL_Color rgb_color_to_sdl_color(t_rgb_color rgb_color);

int clamp(int lower, int higher, int num);

void draw_sample_box(SDL_Surface *surface, SDL_Color color);

void	draw_position_indicator(SDL_Surface *surface, t_hsv_color color);

void draw_hue_slider(SDL_Surface *surface, double hue);

void draw_hue_gradient(SDL_Surface *surface);

void draw_main_gradient(SDL_Surface *surface, double hue);

enum color_picker_ui_state get_state(SDL_Point mouse);

void color_picker_window_create(t_libui *libui);

void calculate_current_color(enum color_picker_ui_state ui_state, t_libui *libui);

void draw_color_picker_window(t_libui *libui);

void color_change_loop(t_libui *libui);

void	delete_widgets(t_widget **widget);

void	delete_window(t_window_list **window, int id);

void	hide_active_window(t_window **active_window,
						   t_window *main_window, t_window_list **window);

void	show_active_window(t_window *active_window);

void cancel_event(t_libui *libui);

void	ok_event(t_libui *libui);

int		button_clicked(SDL_Point point, t_libui *data);

int		point_in_textfield(SDL_Point point, t_widget *widgets);

void	render_text_in_textfield(t_textfield *textfield,
								 t_libui *libui, char *text,
								 void (event)(char **, const char *));

void	text_input_event(char **output_text,
						 const char *input_text);

void	backspace_event(char **output_text,
						const char *input_text);

void			render_text(t_libui *libui, SDL_Event e, t_widget *widgets);

void	blit_with_offset(SDL_Surface *src, SDL_Surface *dst, t_vec2 offset);

void    blit_surface(t_surface *src, t_int_rect src_rect, t_surface *dst, t_vec2 dst_pos);
void    blit_scaled(t_surface *src, t_int_rect src_rect, t_surface *dst, t_int_rect dst_rect);

void    copy_surface(t_surface *src, t_surface *dst);

void    save_jpg(t_surface *surface, const char *file, int quality);

t_surface *create_text_surface(char *text, t_font *font);
t_surface   *create_surface(void);

void	put_filled_circle_pixels(t_surface *surface, t_vec2 *top, t_vec2 center, t_color color);

void	remove_from_queue(t_queue **queue);
t_queue	*init_queue(t_vec2 pos,
                       t_color affected_color, t_color target_color);
int 	in_queue(t_queue *queue, t_vec2 pos);

void			eventloop_mousewheel(t_libui *data);

void			load_dropped_image(t_libui *unicorn, t_surface **target);

void update_window_surface(t_window_list *list);

void add_return_data(t_return_data **begin, void *data);
void	delete_return_data(t_return_data **begin);
void draw_image_field(SDL_Surface *surface, SDL_Surface *image, SDL_Rect field_size);
void draw_field(SDL_Surface *surface, t_menu_field *field,
				TTF_Font *font);
int 		pixel_inside_surface(t_surface *img, int x, int y);

void recalculate_menu(t_menu_list *menu, TTF_Font *font, int w);
void	draw_widgets(t_window_list *list);

void 				flood_fill(t_surface *surface, t_vec2 pos,
							   t_color affected_color, t_color target_color);
t_color rgb_color_to_t_color(t_rgb_color rgb_color);
void set_system_cursor(t_cursor *cursor, t_libui *libui, int id);
t_surface			*load_image_as_surface(const char *file);

#endif
