/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielafonso <danielafonso@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:25:40 by danielafons       #+#    #+#             */
/*   Updated: 2026/01/14 17:13:23 by danielafons      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"

int main()
{
    std::srand(std::time(NULL));
    Base* ptr;
    
    ptr = Base::generate();
    Base::identify(ptr);
    Base::identify(ptr);

    delete ptr;
    return (0);
}