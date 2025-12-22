/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:35:52 by daniel149af       #+#    #+#             */
/*   Updated: 2025/12/22 22:29:38 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

void	convertToInt(const std::string &str)
{
	int nb;
	std::stringstream ss(str);
	ss >> nb;
	if (ss.fail() || !ss.eof()) //eof() evite que "42abc" soit accepté
		std::cerr << "int: impossible\n";
	else
		std::cout << "int: "<< nb << std::endl;
}

bool isNumber(std::string str)
{
	bool isdigit = true;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
		{
			isdigit = false;
			break;
		}
	}
	return (isdigit);
}

void	convertToChar(std::string str)
{
	int ret = std::isprint(std::atoi(str.c_str()));
	int ret1 = std::isprint(7);

	std::cout << "Value: "<< ret << std::endl;
	std::cout << "Value: "<< ret1 << std::endl;
	//Traitement d'un seul char
	if (str.size() == 1 && isascii(std::atoi(str.c_str()))
		&& std::isprint(str[0]))
	{
		if (std::isdigit(std::atoi(str.c_str())))
			std::cout << "char: " << (char)str[0] <<std::endl;
		else
			std::cout << "char: " << str.c_str() <<std::endl;
	}
	else if (isascii(std::atoi(str.c_str()))
		&& std::isprint(std::atoi(str.c_str())) && isNumber(str))
	{
		std::cout << "char: " << (char)std::atoi(str.c_str()) <<std::endl;
	}
	else
		std::cerr << "char: impossible\n";
}

void	ScalarConverter::convert(std::string str)
{
	convertToChar(str);
	convertToInt(str);
}