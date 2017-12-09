/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:23:36 by itonoli-          #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		start_render(t_env *e)
{
	init_rects(e);
	init_txt_rects(e);
	SDL_BlitSurface(e->s_ui, 		 &(SDL_Rect){0, 0, e->win_w, e->win_h},
					e->s_background, &(SDL_Rect){0, 0, e->win_w, e->win_h});
	create_rect(e->s_raytracer, (SDL_Rect){0, 0, F_WIDTH, F_HEIGHT}, 0xFF2b2b2b);
	SDL_BlitSurface(e->s_raytracer,  &(SDL_Rect){0, 0, F_WIDTH, F_HEIGHT},
					e->s_background, &(SDL_Rect){82, 72, F_WIDTH, F_HEIGHT});
	create_rect(e->s_background,
				(SDL_Rect){1126, 80, 160, 530}, 0xFF2b2b2b);
	write_top_text(e);
	e->loader = 0;
	e->render = 1;
}

void		where_is_mickey(t_env *e)
{
	is_mouse_in_rect_top_input(e);
	is_mouse_in_rect_left(e);
	is_mouse_in_rect_top(e);
	if (e->event.type == SDL_MOUSEBUTTONDOWN)
		is_mouse_in_render(e);
}

void	handle_events(t_env *e)
{
	// EXIT
	if (e->event.window.event == SDL_WINDOWEVENT_CLOSE ||
		(e->event.type == SDL_KEYDOWN && e->event.key.keysym.sym == SDLK_ESCAPE))
		e->run = 0;

	// KEYBOARD
	if (e->event.type == SDL_KEYDOWN && e->event.key.keysym.sym != SDLK_ESCAPE)
	{
		if (e->loader == 1 && e->nb_cli > 0)
			start_render(e);
		else if (e->render == 1)
			keyboard(e->event.key.keysym.sym, e);
	}

	// MOUSE
	if ((e->event.type == SDL_MOUSEMOTION ||
		e->event.type == SDL_MOUSEBUTTONDOWN) && e->render == 1)
	{
		e->mouse.x = e->event.motion.x;
		e->mouse.y = e->event.motion.y;
		draw_selected(e);
		where_is_mickey(e);
	}
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
	kill(e->child, SIGTERM);
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
		loader_wait(e);
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
