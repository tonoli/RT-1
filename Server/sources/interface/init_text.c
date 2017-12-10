/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 14:34:06 by itonoli-          #+#    #+#             */
/*   Updated: 2017/12/10 15:32:07 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		right_text(t_env *e, char *str,
	SDL_Rect rect, SDL_Color color_back)
{
	e->s_tmp = TTF_RenderText_Shaded(e->font[2], str, COLOR_W, color_back);
	SDL_BlitSurface(e->s_tmp, &(SDL_Rect){0, 0, e->s_tmp->w,
		e->s_tmp->h}, e->s_background,
					&(SDL_Rect){rect.x + 41 - e->s_tmp->w, rect.y + 2,
						rect.w, rect.h});
	SDL_FreeSurface(e->s_tmp);
}

void		center_text(t_env *e, char *str,
						SDL_Rect rect, SDL_Color color_back)
{
	e->s_tmp = TTF_RenderText_Shaded(e->font[2], str, COLOR_W, color_back);
	SDL_BlitSurface(e->s_tmp, &(SDL_Rect){0, 0, e->s_tmp->w,
		e->s_tmp->h}, e->s_background,
					&(SDL_Rect){rect.x + 35 - e->s_tmp->w, rect.y + 2,
						rect.w, rect.h});
	SDL_FreeSurface(e->s_tmp);
}

void		write_top_text(t_env *e)
{
	int i;

	i = -1;
	sprintf(e->txt[0], " %.*f ", 2, e->rebond);
	sprintf(e->txt[1], " %.*f ", 2, e->rot_speed);
	sprintf(e->txt[2], " %.*f ", 1, e->move_speed);
	while (++i < 3)
	{
		create_rect(e->s_background, e->tt_rect[i], 0x3c3c3c);
		center_text(e, e->txt[i], e->tt_rect[i], COLOR_TXT);
	}
}

char		*name_obj(int i)
{
	char *ret;

	ret = NULL;
	if (i == OBJ_SPHERE)
		ret = ft_strdup("   SPHERE");
	else if (i == OBJ_PLANE)
		ret = ft_strdup("       PLANE");
	else if (i == OBJ_CYL)
		ret = ft_strdup("CYLINDRE");
	else if (i == OBJ_CONE)
		ret = ft_strdup("         CONE");
	else if (i == OBJ_TRI)
		ret = ft_strdup("TRIANGLE");
	else if (i == OBJ_TORUS)
		ret = ft_strdup("    TORUS");
	else if (i == OBJ_SQUARE)
		ret = ft_strdup("   SQUARE");
	return (ret);
}

char		*yes_no(int i)
{
	char *ret;

	ret = NULL;
	if (i == 1)
		ret = ft_strdup("YES");
	else
		ret = ft_strdup("NO");
	return (ret);
}

void		write_right_text_top(t_env *e)
{
	int i;

	i = -1;
	sprintf(e->txt[3], " %s ", name_obj(e->selected->type));
	if (e->selected->emit != 1)
		sprintf(e->txt[4], " - ");
	else
		sprintf(e->txt[4], " %.0f ", e->selected->light);
	sprintf(e->txt[5], " %.*f ", 2, e->selected->fuzz);
	sprintf(e->txt[6], " %s ", yes_no(e->selected->reflection));
	sprintf(e->txt[7], " %.*f ", 1, e->selected->refraction);
	if (e->selected->type == 6 || e->selected->type == 2)
		sprintf(e->txt[8], " - ");
	else
		sprintf(e->txt[8], " %.0f ", e->selected->radius);
	while (++i < 6)
	{
		create_rect(e->s_background, e->it_rect[i], 0x2b2b2b);
		right_text(e, e->txt[i + 3], e->it_rect[i], COLOR_BG);
	}
}

void		select_marble_damier(t_env *e, int i)
{
	if (i == 0)
	{
		sprintf(e->txt[15], " %.0f  ", e->selected->marblecolor.x * 255);
		sprintf(e->txt[16], " %.0f  ", e->selected->marblecolor.y * 255);
		sprintf(e->txt[17], " %.0f  ", e->selected->marblecolor.z * 255);
		sprintf(e->txt[18], " -    ");
		sprintf(e->txt[19], " -    ");
		sprintf(e->txt[20], " -    ");
	}
	else if (i == 1)
	{
		sprintf(e->txt[15], " %.0f  ", e->selected->damier1.x * 255);
		sprintf(e->txt[16], " %.0f  ", e->selected->damier1.y * 255);
		sprintf(e->txt[17], " %.0f  ", e->selected->damier1.z * 255);
		sprintf(e->txt[18], " %.0f  ", e->selected->damier2.x * 255);
		sprintf(e->txt[19], " %.0f  ", e->selected->damier2.y * 255);
		sprintf(e->txt[20], " %.0f  ", e->selected->damier2.z * 255);
	}
	else
	{
		sprintf(e->txt[15], " -    ");
		sprintf(e->txt[16], " -    ");
		sprintf(e->txt[17], " -    ");
		sprintf(e->txt[18], " -    ");
		sprintf(e->txt[19], " -    ");
		sprintf(e->txt[20], " -    ");
	}
}

void		write_right_text(t_env *e)
{
	int i;

	i = 5;
	//Color
	sprintf(e->txt[9], " %.0f  ", e->selected->color.x * 255);
	sprintf(e->txt[10], " %.0f  ", e->selected->color.y * 255);
	sprintf(e->txt[11], " %.0f  ", e->selected->color.z * 255);
	// Rotation
	sprintf(e->txt[12], " %.1f  ", e->selected->dir.x);
	sprintf(e->txt[13], " %.1f  ", e->selected->dir.y);
	sprintf(e->txt[14], " %.1f  ", e->selected->dir.z);
	// Marble
	if (e->selected->marblesize != 0)
		select_marble_damier(e, 0);
	else if (e->selected->damier)
		select_marble_damier(e, 1);
	else
		select_marble_damier(e, 2);
	while (++i < 18)
	{
		if (i == e->it_actif)
			create_b_rect(e->s_background, e->it_rect[e->it_actif],
				0x3c3c3c, 0x5bc4e6);
		else
			create_rect(e->s_background, e->it_rect[i], 0x3c3c3c);
		center_text(e, e->txt[i + 3], e->it_rect[i], COLOR_TXT);
	}
}
