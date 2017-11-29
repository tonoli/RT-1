#ifndef client_h
# define client_h

# include "rt_clu.h"

/*
**	OBJECT ADD
*/

t_obj		*new_obj(void);
void		obj_push_back(t_obj **list, t_obj *cur);

#endif
