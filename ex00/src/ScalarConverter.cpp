#include "../includes/ScalarConverter.hpp"

int toInt(const std::string &str)
{
	std::stringstream ss(str);
	int nb;

	ss >> nb;
	if (ss.fail() || !ss.eof())
		throw std::runtime_error("conversion impossible");

	return nb;
}

void ScalarConverter::convert(std::string str)
{
	try{
		std::isalpha(str);
		int nb;
		std::stringstream(str) >> nb;
		std::cout << nb << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << "int: impossible" << std::endl;
	}
}