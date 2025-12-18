#include "../includes/ScalarConverter.hpp"

int main (int argc, char **argv)
{
	if (argc != 2 || !argv[1])
	{
		std::cerr << "Error: one argument is required\n";
		return (1);
	}
	std::string str;
	str = argv[1];
	ScalarConverter::convert(str);
	return (0);
}