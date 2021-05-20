#include "../libft_cpp/libft.hpp"
#include "../includes/Client.hpp"
#include "../includes/Location.hpp"
#include "../includes/Manager.hpp"
#include "../includes/Server.hpp"
#include "../includes/Webserver.hpp"

int	main(int ac, char **av)
{
	ac = 0;

	if(!Manager::getInstance()->parseConfig(av[1]))
		return (1);
	Manager::getInstance()->show();

	struct timeval timeout;

	timeout.tv_sec = 5; // last request time out 5000ms
	timeout.tv_usec = 0;

	try
	{
		Manager::getInstance()->getWebserver().initServers(5);
	// 	my_webserver.run(timeout, 100);
	}
	catch(const char *e)
	{
		std::cerr << e << '\n';
	}
}