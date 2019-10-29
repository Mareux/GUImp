#include "../libui.h"


void recalculate_menu(t_menu_list *menu, TTF_Font *font, int w)
{
	while (menu)
	{
		if (menu->menu->type == BAR)
		{
			calculate_bar_fields_position(menu->menu->fields, font);
			menu->menu->menu_frame.w = w;
		}
		menu = menu->next;
	}
}
