/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielafonso <danielafonso@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:35:52 by daniel149af       #+#    #+#             */
/*   Updated: 2026/01/05 20:45:19 by danielafons      ###   ########.fr       */
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
	if (nb >= std::numeric_limits<float>::min() && nb <= std::numeric_limits<float>::max())
	{
		if (endptr[0] == '\0' || (endptr[0] == 'f' && endptr[1] == '\0'))
		{
			if (nb == static_cast<int>(nb)) // equivalent to (int)nb it's more c++ user friendly
				std::cout << "float: "<< std::fixed << std::setprecision(1)
					<< nb << "f" << std::endl;
			else
				std::cout << "float: "
					<< nb << "f" << std::endl;
		}
		else
			std::cerr << "float: impossible\n";
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