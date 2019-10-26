#include "../libui.h"

void bar_on_click(t_menu_field *field)
{
	if (field->menu)
	{
		if (field->menu->opened)
			field->menu->opened = TRUE;
		else
			field->menu->opened = FALSE;
	}
}

void menu_events(t_libui *libui, t_menu_list *list)
{
	t_menu_field *field;
	SDL_Point point;
	t_window *window;

	point = (SDL_Point){libui->mouse.pos.x, libui->mouse.pos.y};
	window = find_t_window(libui, "Tools");
	while (list)
	{
		field = list->menu.fields;
		while (field)
		{
			if (libui->active_window->id == window->id)
			{
				if (libui->mouse.m1_pressed && SDL_PointInRect(&point, &field->field_rect))
				{
					if (field->click)
						field->click(libui);
					if (list->menu.type == BAR)
					{
						bar_on_click(field);
					}
				}
				if (SDL_PointInRect(&point, &field->field_rect))
					field->field_color = list->menu.active_field_color;
				else
					field->field_color = list->menu.menu_color;
			}
			field = field->next;
		}
		list = list->next;
	}
}


