/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 15:21:39 by nschilli          #+#    #+#             */
/*   Updated: 2015/10/22 16:40:58 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVEUR_H
# define SERVEUR_H
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <unistd.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <signal.h>
# include "../../libft/libft.h"

# define BUFF_SIZE 1024

int		manager(int cs);
int		listen_clients(int stock);
int		create_server(int port);

void	cmd_pwd(int sock);
int		cmd_ls(char *buff);

void	send_msg(int sock, char *msg, int flag);

#endif
