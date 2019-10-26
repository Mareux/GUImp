#include "guimp.h"

/*
**  Ensures that there are no more than UNDO_BUFFER_LIMIT items
**  in this buffer
*/

void    limit_buffer(t_undo *buffer)
{
    int     i;
    t_undo  *tmp;

    i = 1;
    while (i < UNDO_BUFFER_LIMIT && buffer)
    {
        buffer = buffer->next;
        i++;
    }
    if (i < UNDO_BUFFER_LIMIT || !buffer)
        return ;
    tmp = buffer;
    buffer = buffer->next;
    tmp->next = NULL;
    while (buffer)
    {
        tmp = buffer;
        buffer = buffer->next;
        free_surface(tmp->surface);
        free(tmp);
    }
}

t_undo	*new_buffer_item(void)
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
	t_undo	*new;

	new = new_buffer_item();
	new->surface = duplicate_surface(guimp->canvas);
	new->next = guimp->undo_buffer;
	guimp->undo_buffer = new;
	limit_buffer(guimp->undo_buffer);
}


/*
**	Copies the most recent buffered surface to the canvas,
**	and removes it from buffer
*/

void	pull_from_buffer(t_guimp *guimp)
{
    t_undo  *tmp;

    if (guimp->undo_buffer)
    {
        copy_surface(guimp->undo_buffer->surface, guimp->canvas);
        tmp = guimp->undo_buffer;
        guimp->undo_buffer = tmp->next;
        free_surface(tmp->surface);
        free(tmp);
    }
}

void    guimp_undo(t_libui *libui)
{
    t_guimp *guimp;

    guimp = (t_guimp *)libui->data;
    if (!guimp->undo_buffer)
        return ;
    backup_buffer(guimp);
    pull_from_buffer(guimp);
}
