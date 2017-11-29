#include "client.h"

t_obj	*new_obj(void)
{
	t_obj *new;

	new = (t_obj *)ft_memalloc(sizeof(t_obj));
	new->next = NULL;
	return (new);
}

void	obj_push_back(t_obj **list, t_obj *cur)
{
	if (!list)
		return ;
	while (*list)
		list = &(*list)->next;
	*list = cur;
}

