#include "server.h"

double		get_distance(t_env *e, t_obj *obj, t_ray ray)
{
	double t;

	t = -1;
	if (obj->type == OBJ_SPHERE)
		t = hit_sphere(e, obj, ray);
	else if (obj->type == OBJ_PLANE)
		t = hit_plane(e, obj, ray);
	else if (obj->type == OBJ_CYL)
		t = hit_cyl(e, obj, ray);
	else if (obj->type == OBJ_CONE)
		t = hit_cone(e, obj, ray);
	return (t);
}
