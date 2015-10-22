/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 15:22:26 by nschilli          #+#    #+#             */
/*   Updated: 2015/10/22 16:48:52 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

/*int		create_server(int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	(void)port;
	proto = getprotobyname("tcp");
	if (proto == 0)
		return (-1);
	//sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	//sin.sin_family = AF_INET;
	//sin.sin_port = htons(port);
	//sin.sin_addr.s_addr = htonl(INADDR_ANY);
	//bind(sock, (const struct sockaddr*)&sin, sizeof(sin));
	//listen(sock, 42);
	return (sock);
}
*/
int		main(int argc, char ** argv)
{
	int		port;
	// int		sock;

	if (argc != 2)
	{
		ft_putstr("./serveur [port]");
		exit(-1);
	}
	port = ft_atoi(argv[1]);
	// sock = create_server(port);
	// close(sock);

	return (0);
}
