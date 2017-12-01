#include "client.h"

t_vector	live_preview(t_env *e, t_obj *closest_obj, t_ray ray)
{
	if (closest_obj->damier)
		damier(closest_obj);
	if (closest_obj->current_texture)
		color_mapping(closest_obj);
	return (closest_obj->color);
}
