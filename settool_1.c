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

void settool_line(t_libui *libui)
{
	settool(libui, LINE);
}

void settool_rect(t_libui *libui)
{
	settool(libui, RECT);
}

void settool_circle(t_libui *libui)
{
	settool(libui, CIRCLE);
}

void settool_square(t_libui *libui)
{
	settool(libui, SQUARE);
}

void settool_sticker(t_libui *libui)
{
	settool(libui, STICKER);
}

void settool_magnifying_glass(t_libui *libui)
{
	settool(libui, MAGNIFYING_GLASS);
}

void settool_hand(t_libui *libui)
{
	settool(libui, HAND);
}

void settool_bucket(t_libui *libui)
{
	settool(libui, BUCKET);
}

void settool_text(t_libui *libui)
{
	settool(libui, TEXT_LINE);
}

void settool_pipette(t_libui *libui)
{
	settool(libui, PIPETTE);
}
