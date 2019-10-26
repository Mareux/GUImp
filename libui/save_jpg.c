#include "libui.h"

void    save_jpg(t_surface *surface, const char *file, int quality)
{
    IMG_SaveJPG(surface, file, 100);
}

