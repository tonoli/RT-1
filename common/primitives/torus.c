#include "rt_clu.h"

#define printf(x, ...) pute(x, __VA_ARGS__)

void pute(char *lol, ...)
{

}

double	hit_torus(t_env *e, t_obj *obj, t_ray ray)
{
	t_vector	v;
	double		m;
	double		n;
	double		o;
	double		p;
	double		q;

	v = vector_sub(ray.ori, obj->ori);

	m = vector_dot(ray.dir, ray.dir);
	n = vector_dot(ray.dir, v);
	o = vector_dot(v, v);
	p = vector_dot(ray.dir, obj->dir);
	q = vector_dot(v, obj->dir);

	obj->a = pow(m, 2.0);

	obj->b = 4.0 * m * n;

	obj->c =
		  (4.0 * pow(m, 2.0))
		+ (2.0 * m * o)
		- (2.0 * (pow(obj->big_r, 2.0) + pow(obj->small_r, 2.0)) * m)
		+ (4.0 * pow(obj->big_r, 2.0) * pow(p, 2.0));

	obj->d =
		  (4.0 * n * o)
		- (4.0 * (pow(obj->big_r, 2.0) + pow(obj->small_r, 2.0)) * n)
		+ (8.0 * pow(obj->big_r, 2.0) * p * q);

	obj->e =
		  pow(o, 2.0)
		- (2.0 * (pow(obj->big_r, 2.0) + pow(obj->small_r, 2.0)) * o)
		+ (4.0 * pow(obj->big_r, 2.0) * pow(q, 2.0))
		+ pow((pow(obj->big_r, 2.0) - pow(obj->small_r, 2.0)), 2.0);

	printf("\n%f %f %f %f %f\n", obj->a, obj->b, obj->c, obj->d, obj->e);


	//////////////////////////// QUARTIC /////////////////////////////////
	obj->b /= obj->a;
	obj->c /= obj->a;
	obj->d /= obj->a;
	obj->e /= obj->a;
	obj->a = 1.0;

	double f;

	f = obj->c - ((3.0 * pow(obj->b, 2.0)) / (double)8.0);

	double g;

	g = obj->d + (pow(obj->b, 3.0) / (double)8.0) - ((obj->b * obj->c) / (double)2.0);

	double h;

	h = obj->e
	- ((3.0 * pow(obj->b, 4.0)) / (double)256.0)
	+ ((pow(obj->b, 2.0) * obj->c) / (double)16.0)
	- ((obj->b * obj->d) / (double)4.0);

	printf("Div by a = %f, b = %f, c = %f, d = %f, e = %f\n", obj->a, obj->b, obj->c, obj->d, obj->e);
	printf("f = %f, g = %f, h = %f\n", f, g, h);

	///////////////////////////// CUBIC ///////////////////////////////////

	double	cu_a;
	double	cu_b;
	double	cu_c;
	double	cu_d;

	cu_a = 1.0;

	cu_b = (f / (double)2.0);

	cu_c = ((pow(f, 2.0) - (4.0 * h)) / (double)16.0);

	cu_d = -pow(g, 2.0) / (double)64.0;


	//https://www.easycalculation.com/algebra/learn-quartic-equation.php


	double	cu_f;

	cu_f = (((3.0 * cu_c) / cu_a) - (pow(cu_b, 2.0) / pow(cu_a, 2.0))) / (double)3.0;

	double	cu_g;

	cu_g =
		  (((2.0 * pow(cu_b, 3.0)) / pow(cu_a, 3.0))
		- ((9.0 * cu_b * cu_c) / pow(cu_a, 2.0))
		+ ((27 * cu_d) / cu_a))
		/ (double)27.0;

	double	cu_h;

	cu_h =
		  (pow(cu_g, 2.0) / (double)4.0)
		+ (pow(cu_f, 3.0) / (double)27.0);

	printf("cu_f : %f, cu_g : %f, cu_h : %f\n", cu_f, cu_g, cu_h);

	double	x1 = 0;
	double	x2 = 0;
	double	x3 = 0;
	double	real = 0;
	double	img = 0;


	if (cu_h <= 0 && cu_g && cu_f)
	{
		double	cu_i;
		double	cu_j;
		double	cu_k;
		double	cu_l;
		double	cu_m;
		double	cu_n;
		double	cu_p;

		cu_i = pow((pow(cu_g, 2.0) / (double)4.0) - cu_h, 1.0 / (double)2.0);

		cu_j = pow(cu_i, 1.0 / (double)3.0);

		cu_k = acos(-(cu_g / (double)(2.0 * cu_i)));

		cu_l = -cu_j;

		cu_m = cos(cu_k / (double)3.0);

		cu_n = (sqrt(3.0) * sin(cu_k / (double)3.0));

		cu_p = -(cu_b / (double)(3.0 * cu_a));

		x1 = 2.0 * cu_j * cos(cu_k / (double)3.0) - (cu_b / (double)(3.0 * cu_a));
		x2 = cu_l * (cu_m + cu_n) + cu_p;
		x3 = cu_l * (cu_m - cu_n) + cu_p;

		printf("3 real roots %f, %f, %f\n", x1, x2, x3);
	}
	else if (!cu_f && !cu_g && !cu_h)
	{
		x1 = -pow(cu_d / cu_a, 1.0 / (double)3.0);
		x2 = x1;
		x3 = x1;

		printf("3 equals roots %f, %f, %f\n", x1, x2, x3);

	}
	else if (cu_h > 0)
	{
		double	cu_r;
		double	cu_s;
		double	cu_t;
		double	cu_u;

		cu_r = -(cu_g / (double)2.0) + pow(cu_h, 1.0 / (double)2.0);
//		cu_s = pow(fabs(cu_r), 1.0 / (double)3.0);
		cu_s = pow(cu_r, 1.0 / (double)3.0);
		cu_t = -(cu_g / (double)2.0) - pow(cu_h, 1.0 / (double)2.0);
//		cu_u = pow(fabs(cu_t), 1.0 / (double)3.0);
		cu_u = pow(cu_t, 1.0 / (double)3.0);

//		cu_s = cu_r < 0 ? -cu_s : cu_s;
//		cu_u = cu_t < 0 ? -cu_u : cu_u;

		printf("r %f s %f t %f u %f\n", cu_r, cu_s, cu_t, cu_u);

		x1 = (cu_s + cu_u) - (cu_b / (double)(3.0 * cu_a));
		real = ((-(cu_s + cu_u)) / (double)2.0) - (cu_b / (double)(3.0 * cu_a));
		img = (cu_s - cu_u) * pow(3.0, 1.0 / (double)2.0) / (double)2.0;

		printf("1 real root and 2 img %f, %f, %f\n", x1, real, img);
	}

	///////////////////////// QUARTIC ///////////////////////////////////

	double f_p;
	double f_q;
	double f_r;
	double f_s;

	double s1 = -1;
	double s2 = -1;
	double s3 = -1;
	double s4 = -1;

	if (!img && !real)
	{
		if (x1 > 0 && x2 > 0)
		{
			f_p = sqrt(x1);
			f_q = sqrt(x2);
		}
		else if (x2 > 0 && x3 > 0)
		{
			f_p = sqrt(x2);
			f_q = sqrt(x3);
		}
		else
		{
			f_p = sqrt(x1);
			f_q = sqrt(x3);
		}

		f_r = -g / (double)(8.0 * f_p * f_q);

		f_s = obj->b / (4.0 * obj->a);


		s1 = f_p + f_q + f_r - f_s;
		s2 = f_p - f_q - f_r - f_s;
		s3 = -f_p + f_q - f_r - f_s;
		s4 = -f_p - f_q + f_r - f_s;

		printf("s1 : %f s2 : %f s3 : %f s4 : %f\n", s1, s2, s3, s4);

		if (s1 > e->t_min && s1 < e->t_max)
		{
			obj->t = s1;
			obj->cross = vector_factor(ray.ori, obj->t, ray.dir);
			obj->normal = normal_torus(obj);
			return (s1);
		}

		if (s2 > e->t_min && s2 < e->t_max)
		{
			obj->t = s2;
			obj->cross = vector_factor(ray.ori, obj->t, ray.dir);
			obj->normal = normal_torus(obj);
			return (s2);
		}

		if (s3 > e->t_min && s3 < e->t_max)
		{
			obj->t = s3;
			obj->cross = vector_factor(ray.ori, obj->t, ray.dir);
			obj->normal = normal_torus(obj);
			return (s3);
		}

		if (s4 > e->t_min && s4 < e->t_max)
		{
			obj->t = s4;
			obj->cross = vector_factor(ray.ori, obj->t, ray.dir);
			obj->normal = normal_torus(obj);
			return (s4);
		}

		return (-1);
	}
	else
	{
		double r;

		r = sqrt(pow(real, 2.0) + pow(img, 2.0));

		double y;

		y = sqrt((r - real) / (double)2.0);

		double x;

		x = img / (double)(2.0 * y);

		double pq;

		pq = (x * x) - (y * -y);

		double re;
		double se;

		re = -g / (8.0 * pq);
		se = obj->b / (4.0 * obj->a);

		printf("re : %f se : %f\n", re, se);


		s1 = 2.0 * x + re - se;
		s2 = -2.0 * x + re -se;

		printf("s1 : %f s2 : %f \n", s1, s2);

		if (s1 > e->t_min && s1 < e->t_max)
		{
			obj->t = s1;
			obj->cross = vector_factor(ray.ori, obj->t, ray.dir);
			obj->normal = normal_torus(obj);
			return (s1);
		}

		if (s2 > e->t_min && s2 < e->t_max)
		{
			obj->t = s2;
			obj->cross = vector_factor(ray.ori, obj->t, ray.dir);
			obj->normal = normal_torus(obj);
			return (s2);
		}


		return (-1);

	}

//	printf("s1 : %f s2 : %f s3 : %f s4 : %f\n", s1, s2, s3, s4);


	return (-1);
}

























