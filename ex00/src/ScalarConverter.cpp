/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daafonso <daafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:35:52 by daniel149af       #+#    #+#             */
/*   Updated: 2026/02/10 18:27:24 by daafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

void convertToInt(const std::string str)
{
    char* endptr;
    errno = 0;
    double nb;

	nb = std::strtod(str.c_str(), &endptr);

    if (endptr == str.c_str())
        return (void)(std::cout << "int: impossible\n");

    if (!(*endptr == '\0' || (*endptr == 'f' && endptr[1] == '\0')))
        return (void)(std::cout << "int: impossible\n");

    if (errno == ERANGE || std::isnan(nb) || std::isinf(nb))
        return (void)(std::cout << "int: impossible\n");

    if (std::floor(nb) != nb)
        return (void)(std::cout << "int: impossible\n");

    if (nb < std::numeric_limits<int>::min() || nb > std::numeric_limits<int>::max())
        return (void)(std::cout << "int: impossible\n");

    std::cout << "int: " << static_cast<int>(nb) << "\n";
}


void	convertToChar(std::string str)
{
	if (str.size() == 1)
	{
		if (std::isdigit(str[0]))
			std::cerr << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '"<< str[0] << "'" << std::endl;
	}
	else
	{
		double nb;
		char *endptr;

		nb = strtod(str.c_str(), &endptr);

		if (endptr == str.c_str())
			return (void) (std::cerr << "char: impossible" << std::endl);

		if (std::isnan(nb) || std::isinf(nb))
			return (void) (std::cerr << "char: impossible" << std::endl);

		if (std::floor(nb) != nb)
			return (void) (std::cerr << "char: impossible" << std::endl);

		if (endptr[0] == '\0' || (endptr[0] == 'f' && endptr[1] == '\0'))
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
		else
			std::cerr << "char: impossible" << std::endl;
	}
}


void convertToFloat(std::string str)
{
	float nb;
	char *endptr;

	nb = std::strtof(str.c_str(), &endptr);

	//nothing has been converted
	if (endptr == str.c_str())
		return (void) (std::cout << "float: impossible\n");

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
	double nb;
	char *endptr;

	nb = std::strtod(str.c_str(), &endptr);

	//nothing has been converted
	if (endptr == str.c_str())
		return (void) (std::cout << "double: impossible\n");

	if (endptr[0] == '\0' || (endptr[0] == 'f' && endptr[1] == '\0'))
	{
		if (std::isnan(nb))
			std::cout << "double: nan" << std::endl;
		else if (std::isinf(nb) && nb > 0)
			std::cout << "double: +inf" << std::endl;
		else if (std::isinf(nb) && nb < 0)
			std::cout << "double: -inf" << std::endl;
		else if (nb == static_cast<int>(nb)) // equivalent to (int)nb it's more c++ user friendly
		{
			//Case 1: accurate number ex: 42.0
			std::ostringstream oss;
			oss << std::fixed << std::setprecision(1) << nb;
			std::cout << "double: " << oss.str() << std::endl;
		}
		else
		{
			//Case 2: decimal number ex: 42.42
			std::cout << "double: " << nb << std::endl;
		}
	}
	else
		std::cerr << "double: impossible\n";
}

void	ScalarConverter::convert(std::string str)
{
	convertToChar(str);
	convertToInt(str);
	convertToFloat(str);
	convertToDouble(str);
}
