#include "libui.h"

void    save_jpg(t_surface *surface, const char *file, int quality)
{
	char *tmp;

	tmp = ft_strjoin(file, ".jpeg");
    IMG_SaveJPG(surface, tmp, quality);
    free(tmp);
}

