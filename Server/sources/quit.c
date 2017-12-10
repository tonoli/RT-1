/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 02:53:18 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 15:00:50 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	quit(int sig)
{
	(void)sig;
	close(g_srv_socket);
	exit(EXIT_SUCCESS);
}

void	fatal_quit(char *msg)
{
	perror(msg);
	quit(0);
}

void	custom_quit(char *msg)
{
	if (msg)
		ft_dprintf(2, "\nFatal error : %s\n", msg);
	quit(0);
}

void	thread_quit(char *msg)
{
	if (msg)
		dprintf(STDERR_FILENO, "\nWarning : %s. Quiting thread.\n", msg);
	pthread_exit(NULL);
}
