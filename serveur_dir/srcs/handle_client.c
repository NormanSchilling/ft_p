/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_client.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 15:22:26 by nschilli          #+#    #+#             */
/*   Updated: 2015/10/22 17:09:04 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void	send_msg(int sock, char *msg, int flag)
{
	if (msg)
	{
		if ((send(sock, msg, ft_strlen(msg), flag)) == -1)
		{
			ft_putendl("Error: send !");
			return ;
		}
	}
}