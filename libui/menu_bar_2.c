#include "libui.h"

void	free_array(char **array)
{
	int i;
	char *tmp;

	i = 0;
	while (array[i])
	{
		tmp = array[i];
		free(tmp);
		i++;
	}
	free(array);
}

void	load_font(t_libui *libui)
{
	t_return_data	*data;
	int				i;
	TTF_Font		*font;

	i = 0;
	data = libui->closed_window_return_data;
	while (data)
	{
		if (i == 0)
		{
			font = TTF_OpenFont(data->next->data, ft_atoi(data->data));
			if (font)
				libui->imported_font = font;
		}
		data = data->next;
		i++;
	}
}
