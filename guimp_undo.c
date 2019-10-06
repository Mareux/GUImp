#include "guimp.h"

t_undo	*new_buffer_item()
{
	t_undo	*new;

	new = (t_undo *)malloc(sizeof(t_undo));
	if (!new)
	{
		ft_putendl("Malloc has abandoned us, my lord!");
		exit(-999);
	}
	return (new);
}

/*
**	Adds current state of the canvas to buffer
*/

void	push_to_buffer(t_guimp *guimp)
{
	// Need some buffer size limit to prevent from crashing
	t_undo	*new;

	new = new_buffer_item();
	new->surface = duplicate_surface(guimp->canvas);
	new->next = guimp->undo_buffer;
	guimp->undo_buffer = new;
}

/*
**	Copies the most recent buffered surface to the canvas,
**	and removes it from buffer
*/

// void	pull_from_buffer(t_guimp *guimp)
