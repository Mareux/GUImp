/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks_bind_key.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnosko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 23:29:37 by mnosko            #+#    #+#             */
/*   Updated: 2019/10/29 23:29:38 by mnosko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int		add_key_to_list(t_keylist **lst, char *name, int kmod)
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

void	bind_key(t_libui *libui, char *name,
	int kmod, void (*func)(t_libui *))
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
	keybind->func = (void*)func;
	keybind->next = libui->hooks.keybinds;
	libui->hooks.keybinds = keybind;
}
