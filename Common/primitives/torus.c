#include "rt_clu.h"

//http://cosinekitty.com/raytrace/chapter14_set_operations.html

//#define printf(x, ...) pute(x, __VA_ARGS__)

#define M_2PI  (2.0 * M_PI)
#define eps 0.00001

void pute(char *lol, ...)
{

}

//http://www.ams.org/journals/mcom/1960-14-071/S0025-5718-1960-0117882-6/S0025-5718-1960-0117882-6.pdf

double d4, d3, d2, d1, d0;

void solve_cubic_equation
(double  c3, double  c2, double  c1, double c0, double *x1, double *x2, double *x3, int *nr)
{
	double a2 = c2/c3;
	double a1 = c1/c3;
	double a0 = c0/c3;

	double q = a1/3.0 - a2*a2/9.0;
	double r = (a1*a2 - 3.0*a0)/6.0 - a2*a2*a2 / 27.0;
	double delta = q*q*q + r*r;

	if (delta>0.0) {
		double s1 = r + sqrt(delta);
		s1 = (s1>=0.0) ? pow(s1,1./3.) : -pow(-s1,1./3.);

		double s2 = r - sqrt(delta);
		s2 = (s2>=0.0) ? pow(s2,1./3.) : -pow(-s2,1./3.);

		*x1 = (s1+s2) - a2/3.0;
		*x2 = *x3 = -0.5 * (s1+s2) - a2/3.0;

		*nr = 1;
	}
	else if (delta < 0.0) {
		double theta = acos(r/sqrt(-q*q*q)) / 3.0;
		double costh = cos(theta);
		double sinth = sin(theta);
		double sq = sqrt(-q);

		*x1 = 2.0*sq*costh - a2/3.0;
		*x2 = -sq*costh - a2/3.0 - sqrt(3.) * sq * sinth;
		*x3 = -sq*costh - a2/3.0 + sqrt(3.) * sq * sinth;

		*nr = 3;
	}
	else {
		double s = (r>=0.0) ? pow(r,1./3.) : -pow(-r,1./3.);
		*x1 = 2.0*s - a2/3.0;
		*x2 = *x3 = -s - a2/3.0;
		*nr = 3;
	}
}

int Solve(double *roots)
{
	double r1, r2, r3, r4;
	int nr12, nr34;

	double a3 = d3/d4;
	double a2 = d2/d4;
	double a1 = d1/d4;
	double a0 = d0/d4;

	double au2 = -a2;
	double au1 = (a1 * a3 - 4.0 * a0) ;
	double au0 = 4.0*a0*a2 - a1*a1 - a0*a3*a3;

	double x1, x2, x3;
	int nr;
	solve_cubic_equation(1.0, au2, au1, au0, &x1, &x2, &x3, &nr);

	double u1;
	if (nr == 1) {
		u1 = x1;
	}
	else {
		u1 = (x1>x3) ? x1 : x3;
	}

	double R2 = 0.25*a3*a3 + u1 - a2;
	double R = (R2>0.0) ? sqrt(R2) : 0.0;

	double D2, E2;
	if (R != 0.0) {
		double foo1 = 0.75*a3*a3 - R2 - 2.0*a2;
		double foo2 = 0.25*(4.0*a3*a2 - 8.0*a1 - a3*a3*a3) / R;
		D2 = foo1 + foo2;
		E2 = foo1 - foo2;
	}
	else {
		double foo1 = 0.75*a3*a3 - 2.0*a2;
		double foo2 = 2.0 * sqrt(u1*u1 - 4.0*a0);
		D2 = foo1 + foo2;
		E2 = foo1 - foo2;
	}

	if (D2 >= 0.0) {
		double D = sqrt(D2);
		r1 = -0.25*a3 + 0.5*R - 0.5*D;
		r2 = -0.25*a3 + 0.5*R + 0.5*D;
		nr12 = 2;
	}
	else {
		r1 = r2 = -0.25*a3 + 0.5*R;
		nr12 = 0;
	}

	if (E2 >= 0.0) {
		double E = sqrt(E2);
		r3 = -0.25*a3 - 0.5*R - 0.5*E;
		r4 = -0.25*a3 - 0.5*R + 0.5*E;
		nr34 = 2;
	}
	else {
		r3 = r4 = -0.25*a3 - 0.5*R;
		nr34 = 0;
	}

	int i=0;
	if (nr12 != 0) {
		roots[i++] = r1;
		roots[i++] = r2;
	}
	if (nr34 != 0) {
		roots[i++] = r3;
		roots[i++] = r4;
	}

	return nr12 + nr34;
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

//	printf("\n%f %f %f %f %f\n", obj->a, obj->b, obj->c, obj->d, obj->e);


	//////////////////////////// QUARTIC /////////////////////////////////

//	t_vector rayOriginPosition = ray.ori;
//	t_vector rayDirection = ray.dir;
//
//	t_vector centerToRayOrigin = vector_sub(rayOriginPosition, obj->ori);
//
//	const double centerToRayOriginDotDirection = vector_dot(rayDirection, centerToRayOrigin);
//
//	double	centerToRayOriginDotDirectionSquared = vector_dot(centerToRayOrigin, centerToRayOrigin);
//
//	double innerRadiusSquared = obj->small_r * obj->small_r;
//	double outerRadiusSquared = obj->big_r * obj->big_r;
//
//	double	axisDotCenterToRayOrigin	= vector_dot(obj->dir, centerToRayOrigin);
//	double	axisDotRayDirection = vector_dot(obj->dir, rayDirection);
//	double	a = 1.0 - (axisDotRayDirection * axisDotRayDirection);
//	double	b = 2.0 * (vector_dot(centerToRayOrigin, rayDirection) - axisDotCenterToRayOrigin * axisDotRayDirection);
//	double	c = centerToRayOriginDotDirectionSquared - (axisDotCenterToRayOrigin * axisDotCenterToRayOrigin);
//	double	d = centerToRayOriginDotDirectionSquared + outerRadiusSquared - innerRadiusSquared;
//
//	// Solve quartic equation with coefficients A, B, C, D and E
//	double A = 1;
//	double B = 4 * centerToRayOriginDotDirection;
//	double C = 2 * d + B * B * 0.25f - 4 * outerRadiusSquared * a;
//	double D = B * d - 4 * outerRadiusSquared * b;
//	double E = d * d - 4 * outerRadiusSquared * c;

	d4 = obj->a;
	d3 = obj->b;
	d2 = obj->c;
	d1 = obj->d;
	d0 = obj->e;

	double roots[4] = {-1.0, -1.0, -1.0, -1.0};
	int rootsCount = Solve(roots);

//	printf("%d roots %f %f %f %f\n", rootsCount, roots[0], roots[1], roots[2], roots[3]);

	if (!rootsCount)
		return (-1);

	double closest_root = e->t_max;
	int found = 0;

	for (int idx = 0; idx < rootsCount; ++idx) {
		double root = roots[idx];

		if (root > e->t_min && root < closest_root)
		{
			closest_root = root;
			found = 1;
		}
	}

	if (!found)
		return (-1);

	obj->t = closest_root;
	obj->cross = vector_factor(ray.ori, obj->t, ray.dir);
	obj->normal = normal_torus(obj);
	return (closest_root);


	return (-1);
}






























