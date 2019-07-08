#include "guimp.h"

void	use_tool(t_guimp *guimp)
{
	if (guimp->current_tool == PENCIL)
	{
		use_pencil(guimp);
	}
}
