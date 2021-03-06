#ifndef WEBSERVER_HPP
# define WEBSERVER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <unistd.h>
# include <arpa/inet.h>
# include <sys/socket.h>
# include <errno.h>
# include <string>
# include <fcntl.h>
# include <sys/stat.h>
# include <map>

# include <sys/types.h>
# include <sys/event.h>
# include <sys/time.h>
# include <pthread.h>

class Server;
class Client;
class Location;

class Webserver
{
	private:
		int kq;
		struct kevent return_events[1024];
		std::map<int, Server> servers;
		pthread_t wait_thread;		

		void disconnect_client(Client &client);
		const Server &getServerFromClient(int server_socket_fd, const std::string &server_name);

	public:
		Webserver();
		virtual ~Webserver();

		Location &getPerfectLocation(Server &server, const std::string &uri);
		bool initServers(int queue_size);
		bool run(struct timespec timeout);
		int prepareResponse(Client &client);
		int prepareGeneralResponse(Client &client, Location &location);
};

void deleteServerResoureces(int signo);
void *waitThread(void *wait_queue);

#endif