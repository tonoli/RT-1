/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:23:36 by itonoli-          #+#    #+#             */
/*   Updated: 2017/12/04 22:10:09 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	handle_events(t_env *e)
{
	if (e->event.window.event == SDL_WINDOWEVENT_CLOSE ||
		(e->event.type == SDL_KEYDOWN && e->event.key.keysym.sym == SDLK_ESCAPE))
	{
		//Stop, free and quit
		e->run = 0;
	}

	if (e->event.type == SDL_KEYDOWN && e->event.key.keysym.sym != SDLK_ESCAPE)
	{
		if (e->loader == 1)
		{
			//Place UI on main window
			SDL_BlitSurface(e->s_ui, 		 &(SDL_Rect){0, 0, e->win_w, e->win_h},
							e->s_background, &(SDL_Rect){0, 0, e->win_w, e->win_h});
			//Draw shit on render space
			create_rect(e->s_raytracer, (SDL_Rect){0, 0, F_WIDTH, F_HEIGHT}, 0xFF2b2b2b);
			SDL_BlitSurface(e->s_raytracer,  &(SDL_Rect){0, 0, F_WIDTH, F_HEIGHT},
							e->s_background, &(SDL_Rect){82, 72, F_WIDTH, F_HEIGHT});
			//Init interface buttons
			init_rects(e);

			//Loader step is done, go render shit nigga
			e->loader = 0;
			e->render = 1;
		}
		else if (e->render == 1 && e->event.key.keysym.sym != SDLK_f)
		{
			//f is a reserved simulated key
			//if user calls f manually, it messes up e->sum
			keyboard(e->event.key.keysym.sym, e);
		}
	}
	if (e->event.type == SDL_MOUSEMOTION || e->event.type == SDL_MOUSEBUTTONDOWN)
	{
		e->mouse.x = e->event.motion.x;
		e->mouse.y = e->event.motion.y;
//		printf("MOUSE x = %d\n", e->mouse.x);
//		printf("MOUSE y = %d\n", e->mouse.y);
		is_mouse_in_rect_right(e);
		is_mouse_in_rect_left(e);
		is_mouse_in_rect_top(e);
		if (e->event.type == SDL_MOUSEBUTTONDOWN)
			is_mouse_in_render(e);
	}
	// if (e->event.type == 0x300)
	// 	handle_keyboard_down(env);
	// if (e->event.type == 0x301)
	// 	handle_keyboard_up(env);
}

int		free_elements(t_env *e)
{
	SDL_DestroyWindow(e->win);
	SDL_FreeCursor(e->cursor);
	SDL_FreeSurface(e->w_icon);
	SDL_FreeSurface(e->gui);
	free(e->font);
	e->font = NULL;
	TTF_Quit();
	SDL_Quit();
	exit(EXIT_SUCCESS);
	return (0);
}

int		global_loop(t_env *e)
{
	//Display loader
	SDL_BlitSurface(e->s_loader,     &(SDL_Rect){0, 0, e->win_w, e->win_h},
					e->s_background, &(SDL_Rect){0, 0, e->win_w, e->win_h});

	//While loop, two states :
	// - Loader
	// - Render
	while (e->run)
	{
		SDL_UpdateWindowSurface(e->win);
		if (SDL_PollEvent(&e->event))
			handle_events(e);
	}
	return (free_elements(e));
}

void	start_interface(t_env *e)
{
	init_sdl_modules(e);
	init_sdl_env(e);
	init_sdl_interface(e);
	global_loop(e);
}
