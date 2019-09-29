#include "guimp.h"

void settool(t_libui *libui, int tool)
{
	t_guimp	*guimp;

	guimp = (t_guimp *)libui->data;
	guimp->shape_data.anchor_set = 0;
	guimp->current_tool = tool;
}

void	settool_pencil(t_libui *libui)
{
	set_cursor(libui->cursor, PENCIL);
	settool(libui, PENCIL);
}

void settool_brush(t_libui *libui)
{
	set_cursor(libui->cursor, BRUSH);
	settool(libui, BRUSH);
}

void settool_eraser(t_libui *libui)
{
	set_cursor(libui->cursor, ERASER);
	settool(libui, ERASER);
}

void settool_line(t_libui *libui)
{
	set_cursor(libui->cursor, LINE);
	settool(libui, LINE);
}

void settool_rect(t_libui *libui)
{
	set_cursor(libui->cursor, RECT);
	settool(libui, RECT);
}

void settool_circle(t_libui *libui)
{
	set_cursor(libui->cursor, CIRCLE);
	settool(libui, CIRCLE);
}

void settool_square(t_libui *libui)
{
	set_cursor(libui->cursor, SQUARE);
	settool(libui, SQUARE);
}

void settool_sticker(t_libui *libui)
{
	set_cursor(libui->cursor, STICKER);
	settool(libui, STICKER);
}

void settool_magnifying_glass(t_libui *libui)
{
	set_cursor(libui->cursor, MAGNIFYING_GLASS);
	settool(libui, MAGNIFYING_GLASS);
}

void settool_hand(t_libui *libui)
{
	set_cursor(libui->cursor, HAND);
	settool(libui, HAND);
}

void settool_bucket(t_libui *libui)
{
	set_cursor(libui->cursor, BUCKET);
	settool(libui, BUCKET);
}

void settool_text(t_libui *libui)
{
	set_cursor(libui->cursor, TEXT_LINE);
	settool(libui, TEXT_LINE);
}

void settool_pipette(t_libui *libui)
{
	set_cursor(libui->cursor, PIPETTE);
	settool(libui, PIPETTE);
}
