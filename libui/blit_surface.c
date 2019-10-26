#include "libui.h"

void	blit_with_offset(SDL_Surface *src, SDL_Surface *dst, t_vec2 offset)
{
    SDL_Rect	sorc;
    SDL_Rect	dest;

    sorc.x = 0;
    sorc.y = 0;
    sorc.w = src->w;
    sorc.h = src->h;
    dest.x = offset.x;
    dest.y = offset.y;
    SDL_BlitSurface(src, &sorc, dst, &dest);
}

void    blit_surface(t_surface *src, t_int_rect src_rect, t_surface *dst, t_vec2 dst_pos)
{
    SDL_Rect    src_sdl_rect;
    SDL_Rect    dst_sdl_rect;

    src_sdl_rect.x = src_rect.topleft.x;
    src_sdl_rect.y = src_rect.topleft.y;
    src_sdl_rect.w = src_rect.bottomright.x - src_rect.topleft.x;
    src_sdl_rect.h = src_rect.bottomright.y - src_rect.topleft.y;
    dst_sdl_rect.x = dst_pos.x;
    dst_sdl_rect.y = dst_pos.y;
    SDL_BlitSurface(src, &src_sdl_rect, dst, &dst_sdl_rect);
}

void    copy_surface(t_surface *src, t_surface *dst)
{
    SDL_BlitSurface(src, 0, dst, 0);
}