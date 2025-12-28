/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:35:52 by daniel149af       #+#    #+#             */
/*   Updated: 2025/12/27 17:21:18 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

void	convertToInt(const std::string str)
{
	int nb;
	std::stringstream ss(str);
	ss >> nb;
	if (ss.fail() || !ss.eof()) //eof() evite que "42abc" soit accepté
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
		if (ss.fail() || !ss.eof())
			std::cerr << "char: impossible" << std::endl;
		else
		{
			if (isascii(nb))
			{
				if (std::isprint(nb))
				std::cout << "char: "<< (char)nb << std::endl;
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
	if (!nb)
		std::cerr << "float: impossible\n";
	else
	{
		if (nb == (int)nb) //
			std::cout << "float: "<< std::fixed << std::setprecision(1)
				<< nb << "f" << std::endl;
		else
			std::cout << "float: "
				<< nb << "f" << std::endl;
	}
}

void	ScalarConverter::convert(std::string str)
{
	convertToChar(str);
	convertToInt(str);
	convertToFloat(str);
}