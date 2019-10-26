#include "guimp.h"

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
