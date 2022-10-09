#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	Harl	harl;
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments! Should be: ./harlFilter [FILTER]\n";
		return (0);
	}
	harl.complain(argv[1]);
	return (1);
}
