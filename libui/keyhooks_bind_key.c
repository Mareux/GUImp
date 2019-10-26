#include "libui.h"

int	add_key_to_list(t_keylist **lst, char *name, int kmod)
{
	SDL_Keycode	keycode;
	t_keylist	*new;

	keycode = SDL_GetKeyFromName(name);
	if (keycode == SDLK_UNKNOWN)
		return (0);
	new = (t_keylist *)malloc(sizeof(t_keylist));
    if (!new)
    {
        ft_putendl("Such error much memory wow");
        exit(1488);
    }
	new->scancode = SDL_GetScancodeFromKey(keycode);
    new->keymod = kmod;
	new->next = *lst;
	*lst = new;
	return (1);
}

void	bind_key(t_libui *libui, const char *name, int kmod, void (*func)(t_libui *))
{
	t_keybind	*keybind;
	t_keylist	*keys;

	keybind = (t_keybind *)malloc(sizeof(t_keybind));
    if (!keybind)
    {
        ft_putendl("Such error much memory wow");
        exit(1488);
    }
	keys = NULL;
	add_key_to_list(&keys, name, kmod);
	keybind->keys = keys;
	keybind->func = func;
	keybind->next = libui->hooks.keybinds;
	libui->hooks.keybinds = keybind;
}

