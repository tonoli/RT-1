#include "server.h"

void	light_object(t_env *e)
{
	if (!e->selected)
		return ;
	e->selected->emit = e->selected->emit == 0 ? 1 : 0;
	if (e->selected->emit)
		e->selected->light = (t_vector){3.0, 3.0, 3.0};
	else
		e->selected->light = (t_vector){0, 0, 0};
}
