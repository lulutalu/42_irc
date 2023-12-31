/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IRCServer.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:00:14 by yoel              #+#    #+#             */
/*   Updated: 2023/07/16 16:47:10 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRCSERVER_HPP
# define IRCSERVER_HPP

# include <iostream>
# include <string>
# include <map>
# include <vector>
# include <sys/socket.h>
# include <sys/select.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

# include "perror.hpp"
# include "Client.hpp"
# include "Channel.hpp"
# include "Message.hpp"

class IRCServer
{
	public:
		IRCServer();
		IRCServer(IRCServer const & src);
		~IRCServer();
		IRCServer & operator=(IRCServer const & src);
		
		int init(int port, std::string const & password);
		int run();

		int sendToClient(std::string const & message, Client & client);

	private:
		int 	_socket;
		int 	_port;
		int 	_maxfd;
		fd_set 	_allfds;
		fd_set 	_readfds;
		fd_set 	_writefds;
		std::string 				_motd;
		std::string 				_password;
		std::vector<Client> 		_clients;
		std::vector<Channel> 		_channels;

		int 	_initSocket();
		void 	_initFdSets();

		int			_select();
		int			_accept();
		int			_recv(Client & client);
		int			_send(Client & client);
		void		_addClient(int fd);
		void		_removeClient(Client & client);
		void		_processRequest(Client & client);


		std::string	_processCap(Message request, Client & client);
//		std::string	_processPass(Message request, Client & client);
//		std::string	_processNick(Message request, Client & client);
//		std::string	_processUser(Message request, Client & client);
//		std::string	_processPing(Message request, Client & client);
//		std::string	_processPong(Message request, Client & client);
//		std::string	_processOper(Message request, Client & client);
//		std::string	_processQuit(Message request, Client & client);
//		std::string	_processJoin(Message request, Client & client);
//		std::string	_processPrivmsg(Message request, Client & client);
//		std::string	_processMotd(Message request, Client & client);
//		std::string	_processKick(Message request, Client & client);
//		std::string	_processInvite(Message request, Client & client);
//		std::string	_processTopic(Message request, Client & client);
//		std::string	_processMode(Message request, Client & client);
};

#endif
