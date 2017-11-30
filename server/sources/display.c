#include "server.h"

void	copy_image_to_sdl(SDL_Surface *win, int *image)
{
	short	x;
	short	y;

	y = -1;
	while (++y < F_HEIGHT)
	{
		x = -1;
		while (++x < F_WIDTH)
		{
			*((unsigned *)(win->pixels + y * win->pitch + x * win->format->BytesPerPixel)) = image[x * (int)F_HEIGHT + y];
		}
	}
	printf("created rect\n");
}


void	display_buffer(t_env *e)
{
	ft_printf("Displaying buffer image\n");

	SDL_Init(SDL_INIT_VIDEO);
	if (!(e->win = SDL_CreateWindow("RayTracer Server", SDL_WINDOWPOS_CENTERED,
									SDL_WINDOWPOS_CENTERED, F_WIDTH, F_HEIGHT, 0)))
		custom_quit("SDL Create Window");
	e->s_background = SDL_GetWindowSurface(e->win);
	copy_image_to_sdl(e->s_background, g_buffer);
	while (1)
	{
		SDL_UpdateWindowSurface(e->win);
		if (SDL_PollEvent(&e->event))
			;
	}
}
