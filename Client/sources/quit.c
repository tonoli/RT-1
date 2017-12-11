/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 02:50:08 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 11:37:46 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	custom_quit(char *msg)
{
	if (msg)
		ft_dprintf(2, "\nFatal error : %s\n", msg);
//	close(g_cli_socket);
	exit(EXIT_FAILURE);
}

void	fatal_quit(char *msg)
{
	perror(msg);
//	close(g_cli_socket);
	exit(EXIT_FAILURE);
}
