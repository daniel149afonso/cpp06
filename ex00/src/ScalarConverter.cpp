/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielafonso <danielafonso@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:35:52 by daniel149af       #+#    #+#             */
/*   Updated: 2026/01/12 13:12:31 by danielafons      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

void	convertToInt(const std::string str)
{
	long nb;
	char *endptr;
	errno = 0;

	nb = std::strtod(str.c_str(), &endptr);
	//nb = std::strtol(str.c_str(), &endptr, 10);
	if (endptr == str.c_str() || *endptr != '\0') //Check errors
		std::cerr << "int: impossible\n";
	else if (errno == ERANGE || //Check overflow of long and int max and min
    	nb < std::numeric_limits<int>::min() ||
    	nb > std::numeric_limits<int>::max())
	{
		std::cerr << "int: impossible\n";
	}
	else
		std::cout << "int: "<< static_cast<int>(nb) << std::endl;
}

void	convertToChar(std::string str)
{
	if (str.size() == 1)
	{
		if (std::isdigit(str[0]))
			std::cerr << "char: Non displayable" << std::endl;
		else
			std::cout << "char: "<< str[0] << std::endl;
	}
	else
	{
		int nb;
		std::stringstream ss(str);
		ss >> nb;
		if (ss.fail() || !ss.eof())//check also overflows int max etc
			std::cerr << "char: impossible" << std::endl;
		else
		{
			if (isascii(nb))
			{
				if (std::isprint(nb))
				std::cout << "char: '"<< static_cast<char>(nb) << "'" << std::endl;
				else
					std::cerr << "char: Non displayable" << std::endl;
			}
			else
				std::cerr << "char: impossible" << std::endl;
		}
	}
}

void convertToFloat(std::string str)
{
	float nb;
	char *endptr;

	nb = std::strtof(str.c_str(), &endptr);
	
	//nothing has been converted
	if (endptr == str.c_str())
	{
		std::cout << "float: impossible\n";
		return;
	}
	if (endptr[0] == '\0' || (endptr[0] == 'f' && endptr[1] == '\0'))
	{
		if (std::isnan(nb))
			std::cout << "float: nanf" << std::endl;
		else if (std::isinf(nb) && nb > 0)
			std::cout << "float: +inff" << std::endl;
		else if (std::isinf(nb) && nb < 0)
			std::cout << "float: -inff" << std::endl;
		else if (nb == static_cast<int>(nb)) // equivalent to (int)nb it's more c++ user friendly
		{
			//Case 1: accurate number ex: 42.0
			std::ostringstream oss;
			oss << std::fixed << std::setprecision(1) << nb << "f";
			std::cout << "float: " << oss.str() << std::endl;
		}
		else
		{
			//Case 2: decimal number ex: 42.42
			std::cout << "float: " << nb << "f" << std::endl;
		}
	}
	else
		std::cerr << "float: impossible\n";
}

void convertToDouble(std::string str)
{
	float nb;
	char *endptr;

	nb = std::strtof(str.c_str(), &endptr);
	
	//nothing has been converted
	if (endptr == str.c_str())
	{
		std::cout << "float: impossible\n";
		return;
	}
	if (endptr[0] == '\0' || (endptr[0] == 'f' && endptr[1] == '\0'))
	{
		if (std::isnan(nb))
			std::cout << "float: nanf" << std::endl;
		else if (std::isinf(nb) && nb > 0)
			std::cout << "float: +inff" << std::endl;
		else if (std::isinf(nb) && nb < 0)
			std::cout << "float: -inff" << std::endl;
		else if (nb == static_cast<int>(nb)) // equivalent to (int)nb it's more c++ user friendly
		{
			//Case 1: accurate number ex: 42.0
			std::ostringstream oss;
			oss << std::fixed << std::setprecision(1) << nb << "f";
			std::cout << "float: " << oss.str() << std::endl;
		}
		else
		{
			//Case 2: decimal number ex: 42.42
			std::cout << "float: " << nb << "f" << std::endl;
		}
	}
	else
		std::cerr << "float: impossible\n";
}

void	ScalarConverter::convert(std::string str)
{
	convertToChar(str);
	convertToInt(str);
	convertToFloat(str);
	
}