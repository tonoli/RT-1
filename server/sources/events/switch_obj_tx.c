#include "server.h"

void	switch_obj_tx(t_env *e)
{
	if (!e->selected)
		return ;
	e->selected->texture_index++;
	if (e->selected->texture_index == e->obj_tx_total)
	{
		e->selected->texture_index = -1;
		e->selected->current_texture = NULL;
	}
	else
		e->selected->current_texture = e->s_obj_tx[e->selected->texture_index];
}
