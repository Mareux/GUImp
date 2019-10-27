#include "guimp.h"

void settool(t_libui *libui, int tool)
{
	t_guimp	*guimp;

	guimp = (t_guimp *)libui->data;
	if (guimp->text_tool.active)
		return ;
	guimp->shape_data.anchor_set = 0;
	guimp->current_tool = tool;
	if (guimp->current_tool == TEXT_LINE)
	{
		free(guimp->text_tool.text);
		guimp->text_tool.text = ft_strdup("");
	}
}

void	settool_pencil(t_libui *libui)
{
	settool(libui, PENCIL);
}

void settool_brush(t_libui *libui)
{
	settool(libui, BRUSH);
}

void settool_eraser(t_libui *libui)
{
	settool(libui, ERASER);
}

void	settool_picture(t_libui *libui)
{
	settool(libui, PICTURE);
}
