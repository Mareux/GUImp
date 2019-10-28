#include "libui.h"

SDL_Window	*find_window(t_libui *libui, const char *title)
{
	t_window_list	*w;

	w = libui->windows;
	while (w)
	{
		if (!w->window.window)
			break ;
		if (!ft_strcmp(SDL_GetWindowTitle(w->window.window), title))
			return (w->window.window);
		w = w->next;
	}
	return (NULL);
}

t_window	*find_t_window(t_libui *libui, const char *title)
{
	t_window_list	*w;

	w = libui->windows;
	while (w)
	{
		if (!w->window.window)
			break ;
		if (!ft_strcmp(SDL_GetWindowTitle(w->window.window), title))
			return (&w->window);
		w = w->next;
	}
	return (NULL);
}

void	change_window_surface(t_libui *libui, const char *title)
{
	t_window_list	*w;

	w = libui->windows;
	while (w)
	{
		if (!w->window.window)
			break ;
		if (!ft_strcmp(SDL_GetWindowTitle(w->window.window), title))
		{
			SDL_FreeSurface(w->window.surface);
			w->window.surface = SDL_GetWindowSurface(w->window.window);
		}
		w = w->next;
	}
}

SDL_Surface	*get_window_surface(t_libui *libui, const char *title)
{
	t_window_list *w;

	w = libui->windows;
	while (w)
	{
		if (!w->window.window)
			break ;
		if (!ft_strcmp(SDL_GetWindowTitle(w->window.window), title))
		{
			return (w->window.surface);
		}
		w = w->next;
	}
	return (NULL);
}

void	set_window_resizable(t_libui *libui, const char *title, int resizable)
{
	SDL_Window	*window;

	if (!libui)
		return ;
	window = find_window(libui, title);
	if (!window)
		return ;
	if (resizable)
		SDL_SetWindowResizable(window, SDL_TRUE);
	else
		SDL_SetWindowResizable(window, SDL_FALSE);
}

void	set_window_position(t_libui *libui, const char *title, t_vec2 position)
{
	SDL_Window	*window;

	if (!libui)
		return ;
	window = find_window(libui, title);
	if (!window)
		return ;
	SDL_SetWindowPosition(window, position.x, position.y);
}