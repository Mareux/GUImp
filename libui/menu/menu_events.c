#include "../libui.h"

void menu_events(t_libui *libui, t_menu_list *list, SDL_Point mouse)
{
	t_menu_field *field;

	while (list)
	{
		field = list->menu.fields;
		while (field)
		{
			if (libui->mouse.m1_pressed && SDL_PointInRect(&mouse, &field->field_rect))
				if (field->click)
					field->click(libui);
			if (SDL_PointInRect(&mouse, &field->field_rect))
				field->field_color = list->menu.active_field_color;
			else
				field->field_color = list->menu.menu_color;
			field = field->next;
		}
		list = list->next;
	}
}
