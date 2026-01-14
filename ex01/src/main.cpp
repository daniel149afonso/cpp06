/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielafonso <danielafonso@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:25:40 by danielafons       #+#    #+#             */
/*   Updated: 2026/01/14 12:21:51 by danielafons      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"

int main()
{
    Data data;

    data.value = 100;
    std::cout << "Original address: " << &data << std::endl;
    std::cout << "Original value: " << data.value << std::endl;
    
    uintptr_t raw = Serializer::serialize(&data);
    
    std::cout << "Original raw: " << raw << std::endl;
    
    Data *d = Serializer::deserialize(raw);
    
    std::cout << "Final address: " << &data << std::endl;
    std::cout << "Final value: " << data.value << std::endl;
    d->value = 200;
    return (0);
}