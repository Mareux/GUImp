#include "guimp.h"

void	use_tool(t_guimp *guimp)
{
	if (guimp->current_tool == PENCIL)
		use_pencil(guimp);
	else if (guimp->current_tool == HAND)
		use_hand(guimp);
	else if (guimp->current_tool == MAGNIFYING_GLASS)
		use_magnifying_glass(guimp);
}
