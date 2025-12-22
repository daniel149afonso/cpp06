/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:35:38 by daniel149af       #+#    #+#             */
/*   Updated: 2025/12/22 22:10:07 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ScalarConverter.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: one argument is required\n";
		return (1);
	}
	std::string str;
	str = argv[1];
	ScalarConverter::convert(str);
	return (0);
}