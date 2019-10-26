#include "guimp.h"

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