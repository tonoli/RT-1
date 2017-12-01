#include "server.h"

void perlin_generate(t_env *e)
{
	int i = 0;

	while (i < 256)
	{
		e->ranvec[i].x = -1.0 + (2.0 * randb());
		e->ranvec[i].y = -1.0 + (2.0 * randb());
		e->ranvec[i].z = -1.0 + (2.0 * randb());
		e->ranvec[i] = vector_normalize(e->ranvec[i]);
		i++;
	}
}

void permute(int *p, int n)
{
	int i = n - 1;

	while (i > 0)
	{
		int target = (int)(randb() * (i + 1));
		int tmp = p[i];
		p[i] = p[target];
		p[target] = tmp;
		i--;
	}
}

void perlin_generate_perm(int *p)
{
	int i = 0;

	while (i < 256)
	{
		p[i] = i;
		i++;
	}

	permute(p, 256);
}

