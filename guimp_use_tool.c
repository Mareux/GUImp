#include "guimp.h"

void	use_tool(t_guimp *guimp)
{
	if (guimp->current_tool == PENCIL)
		use_pencil(guimp);
	else if (guimp->current_tool == BRUSH)
		use_brush(guimp);
	else if (guimp->current_tool == HAND)
		use_hand(guimp);
	else if (guimp->current_tool == ERASER)
		use_eraser(guimp);
	else if (guimp->current_tool == LINE)
		use_line(guimp);
	else if (guimp->current_tool == CIRCLE)
		use_circle(guimp);
	else if (guimp->current_tool == RECT)
		use_rect(guimp);
	else if (guimp->current_tool == SQUARE)
		use_square(guimp);
	else if (guimp->current_tool == PIPETTE)
		use_pipette(guimp);
	else if (guimp->current_tool == STICKER)
		use_sticker_brush(guimp);
	else if (guimp->current_tool == TEXT_LINE)
		toggle_text_input(guimp);
}
