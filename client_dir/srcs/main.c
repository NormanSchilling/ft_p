/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 17:10:35 by nschilli          #+#    #+#             */
/*   Updated: 2015/10/22 17:14:26 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		ft_putstr("./client [serveur][port]");
		exit(-1);
	}
	return (0);
}