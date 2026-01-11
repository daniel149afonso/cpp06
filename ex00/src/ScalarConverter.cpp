/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:35:52 by daniel149af       #+#    #+#             */
/*   Updated: 2026/01/06 19:57:17 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

void	convertToInt(const std::string str)
{
	int nb;
	std::stringstream ss(str);
	ss >> nb;
	if (ss.fail() || !ss.eof()) //eof() avoid chars after the value "42abc" should not be allowed
		std::cerr << "int: impossible\n";
	else
		std::cout << "int: "<< nb << std::endl;
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
				std::cout << "char: "<< static_cast<char>(nb) << std::endl;
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
		// std::cout << "nb='" << nb << "'\n";//debug
		if (std::isnan(nb))
			std::cout << "float: nanf" << std::endl;
		else if (std::isinf(nb) && nb > 0)
			std::cout << "float: +inff" << std::endl;
		else if (std::isinf(nb) && nb < 0)
			std::cout << "float: -inff" << std::endl;
		else if (nb == static_cast<int>(nb)) // equivalent to (int)nb it's more c++ user friendly
		{
			std::ostringstream oss;
			oss << std::fixed << std::setprecision(1) << nb;
			std::cout << oss.str();
		}
		else
			std::cout << "float: "
				<< nb << "f" << std::endl;
	}
	else
		std::cerr << "float: impossible\n";
	// std::cout << "rest='" << endptr << "'\n";//debug

}

void convertToDouble(std::string str)
{
	float nb;
	char *endptr;

	nb = std::strtof(str.c_str(), &endptr);
	if (endptr[0] == '\0' || (endptr[0] == 'f' && endptr[1] == '\0'))
	{
		if (std::isinf(nb) && nb > 0)
			std::cout << "+" << endptr << "f" << std::endl;
		else if (std::isinf(nb) && nb < 0)
			std::cout << "-" << endptr << "f" << std::endl;
		else if (nb == static_cast<int>(nb)) // equivalent to (int)nb it's more c++ user friendly
			std::cout << "float: "<< std::fixed << std::setprecision(1)
				<< nb << "f" << std::endl;
		else
			std::cout << "float: "
				<< nb << "f" << std::endl;
	}
	else
		std::cerr << "float: impossible\n";
	std::cout << "rest='" << endptr << "'\n";
}

void	ScalarConverter::convert(std::string str)
{
	convertToChar(str);
	convertToInt(str);
	convertToFloat(str);
	
}