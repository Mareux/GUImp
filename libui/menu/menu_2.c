#include "../libui.h"

void draw_image_field(SDL_Surface *surface,
		SDL_Surface *image, SDL_Rect field_size)
{
	SDL_BlitScaled(image, &image->clip_rect, surface, &field_size);
}

void draw_menu(SDL_Surface *surface, t_menu *menu, TTF_Font *font)
{
	t_menu_field *field;

	if (!menu->opened)
		return ;
	field = menu->fields;
	if (menu->type == BAR)
		draw_filled_rect(surface,
				(t_vec2){menu->menu_frame.x, menu->menu_frame.y},
				(t_vec2){menu->menu_frame.x + menu->menu_frame.w,
				menu->menu_frame.y + menu->menu_frame.h},
				menu->menu_color);
	while (field)
	{
		draw_field(surface, field, font);
		field = field->next;
	}
}

void	draw_all_menus(t_menu_list *list, TTF_Font *font)
{
	while (list)
	{
		draw_menu(SDL_GetWindowSurface(list->menu->menu_window),
				list->menu, font);
		list = list->next;
	}
}
