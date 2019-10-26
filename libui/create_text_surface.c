#include "libui.h"

t_surface *create_text_surface(char *text, t_font *font)
{
    t_surface		*surface;
    SDL_Color		text_color;

    text_color = (SDL_Color){0, 0, 0, 0};
    surface = TTF_RenderUTF8_Blended(font, text, text_color);
    return (surface);
}