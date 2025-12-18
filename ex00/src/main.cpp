#include "../includes/ScalarConverter.hpp"

int main (int argc, char **argv)
{
	if (argc != 2 || argv[1])
		return (1);
	std::string str;
	str = argv[1];
	ScalarConverter::convert(str);
	return (0);
}