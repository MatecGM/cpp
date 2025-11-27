

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	BitcoinExchange	test;

	if (argc != 2)
	{
		std::cerr << "Error: not expected number of arguments" << std::endl;
		return (1);
	}
	try {
		test.open_reference("data.csv");
		test.open_input(argv[1]);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return (0);
}