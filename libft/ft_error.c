#include "libft.h"

/*
**	Frees the pointer, sets it to NULL,
**	and returns -1
*/

int	ft_error(char **ptr)
{
	free(*ptr);
	*ptr = 0;
	return (-1);
}