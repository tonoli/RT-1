#include "server.h"

void	copy_image_to_sdl(t_env *e, SDL_Surface *win)
{
	short	x;
	short	y;
	t_vector v_color;

	y = -1;
	while (++y < F_HEIGHT)
	{
		x = -1;
		while (++x < F_WIDTH)
		{
			v_color = vector_scale(g_buffer[x * (int)F_HEIGHT + y], 1 / (double)e->sum);

			int final_color;

			final_color =
				((int)v_color.x << 16) +
				((int)v_color.y << 8) +
				(int)v_color.z
			;

			*((unsigned *)(win->pixels + y * win->pitch + x * win->format->BytesPerPixel)) = final_color;
		}
	}
	printf("created rect\n");
}


void	display_buffer(t_env *e)
{
	ft_printf("Displaying buffer image\n");

	copy_image_to_sdl(e, e->s_background);
//	SDL_UpdateWindowSurface(e->win);
//	SDL_PollEvent(&e->event);
}
