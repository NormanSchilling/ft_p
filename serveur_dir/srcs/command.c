/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 15:22:26 by nschilli          #+#    #+#             */
/*   Updated: 2015/10/22 17:09:04 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void		cmd_pwd(int sock)
{
	char		pwd[BUFF_SIZE];

	send_msg(sock, ft_strdup(getcwd(pwd, BUFF_SIZE)), 0);
	ft_putendl("Launch cmd : pwd");
}

int			cmd_ls(char *buff)
{
	int			pid;
	char		**cmd;

	if ((pid = fork()) == -1)
		return (-1);
	if (pid == 0)
	{
		cmd = ft_strsplit(buff, ' ');
		if ((execve("/bin/ls", &cmd[0], NULL)) == -1)
		{
			ft_putendl("Error: execve !\n");
			return (-1);
		}
	}
	ft_putendl("Launch cmd : ls");
	return (0);
}
