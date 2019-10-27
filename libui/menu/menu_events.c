#include "../libui.h"

void bar_on_click(t_menu_field *field, t_menu_list **list)
{
	if (field->menu)
	{
		if (!field->menu->opened)
		{
			field->menu->opened = TRUE;
			add_menu_to_list(list, *(field->menu));
		}
		else
		{
			field->menu->opened = FALSE;
			remove_menu_from_list(list, *(field->menu));
		}
	}
}

void menu_events(t_libui *libui, t_menu_list *list)
{
	t_menu_field *field;
	SDL_Point point;
	t_window *window;
	t_menu_list *begin;
	t_menu_list *iter;

	begin = list;
	iter = list;
	point = (SDL_Point){libui->mouse.pos.x, libui->mouse.pos.y};
	window = find_t_window(libui, "Tools");
	while (iter)
	{
		field = iter->menu.fields;
		while (field)
		{
//			if (libui->active_window->id == window->id)
//			{
				if (libui->mouse.m1_pressed && SDL_PointInRect(&point, &field->field_rect))
				{
					if (field->click)
						field->click(libui);
					if (iter->menu.type == BAR)
					{
						bar_on_click(field, &begin);
					}
				}
				if (SDL_PointInRect(&point, &field->field_rect))
					field->field_color = iter->menu.active_field_color;
				else
					field->field_color = iter->menu.menu_color;
//			}
			field = field->next;
		}
		iter = iter->next;
	}
}


