/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_post_realloc_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 04:38:24 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_pre_realloc_str(char *add, char *str)
{
	char *new_line;

	if (!str || !add)
		return (NULL);
	new_line = ft_strnew(ft_strlen(str) + ft_strlen(add));
	ft_strcpy(new_line, add);
	ft_strcat(new_line, str);
	free(str);
	str = NULL;
	return (new_line);
}

char	*ft_post_realloc_str(char *str, char *add)
{
	char *new_line;

	if (!str || !add)
		return (NULL);
	new_line = ft_strnew(ft_strlen(str) + ft_strlen(add));
	ft_strcpy(new_line, str);
	ft_strcat(new_line, add);
	free(str);
	str = NULL;
	return (new_line);
}
